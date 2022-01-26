/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-12-11
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

#include <klibc.h>      // always include the functions declaration file

//-------------------------------------------------------------------------------------------------
// TTY Definition
// - NTTYS              is the number of available TTY
// - struct tty_s       tty's registers map description
// - __tty_regs_map     declare tty's registers map defined in ldscript
// - volatile           means that compiler must really read from and write to memory
//                      thus it must not use registers to optimize
//-------------------------------------------------------------------------------------------------

struct tty_s {
    int write;          // tty's output address
    int status;         // tty's status address something to read if not null)
    int read;           // tty's input address
    int unused;         // unused address
};

extern volatile struct tty_s __tty_regs_map[NTTYS];

//-------------------------------------------------------------------------------------------------

int tty_putc (int tty, int c)
{
    tty = tty % NTTYS;                          // to be sure that tty is an existing tty
    return __tty_regs_map[ tty ].write = c;     // send c to the tty
}

int tty_getc (int tty)
{
    tty = tty % NTTYS;                          // to be sure that tty is an existing tty

    while (__tty_regs_map[ tty ].status == 0);  // wait for a char from the keyboard

    int c = __tty_regs_map[ tty ].read;         // read the char
    tty_putc (tty, c);                          // loop back to the tty

    return c;                                   // return the read char
}

int tty_puts (int tty, char *buf)
{
    tty = tty % NTTYS;                          // to be sure that tty is an existing tty
    int res = 0;                                // nb of written char

    while (*buf != 0) {
        tty_putc (tty, *buf);                   // send the char to TTY
        res++;                                  // nb of written char
        buf++;		                            // but is the next address in buffer
    }
    return res;
}

int tty_gets (int tty, char *buf, int count)
{
    // to make the backspace, we use ANSI codes : https://www.wikiwand.com/en/ANSI_escape_code
#   define CL "\033[D"                          /* move the cursor left */

    tty = tty % NTTYS;                          // to be sure that tty is an existing tty

    int res = 0;
    count--;                                    // we need to add a NUL (0) char at the end
    int c;

    while ((count != 0) && (c != '\n')) {       // as long as we can or need to get a char

        c = tty_getc (tty);                     // get one char
        if (c == '\r')                          // if c is the carriage return (13)
            c = tty_getc (tty);                 // get the next that is line feed (10)

        if ((c == 8)||(c == 127)) {             // 8 = backspace, 127 = delete
            if (res) {                          // go back in the buffer if possible
        	    tty_puts (tty, CL " " CL);      // replace the current char by a ' '
                count++;		                // count is the remaining place
                buf--;                          // but is the next address in buffer
                res--;
            }
            continue;                           // ask for another key
        }

        *buf = c;                               // write the char into the buffer
        buf++;                                  // increments the writing pointer
        count--;                                // decrements the remaining space
        res++;
    }
    *buf = 0;                                   // add a last 0 to end the string

    return res;                                 // returns the number of char read

#   undef CL
}

//-------------------------------------------------------------------------------------------------
// TIMER Definition
// - NCPUS              is the number of available TIMERs given to gcc (see Makefile)
// - struct timer_s     timer's registers map description
// - __timer_regs_map   declare timer's registers map defined in ldscript
// - volatile           means that compiler must really read from and write to memory
//                      thus it must not use registers to optimize
//-------------------------------------------------------------------------------------------------

struct timer_s {
    int value;          // timer's counter : +1 each cycle, can be written
    int mode;           // timer's mode : bit 0 = ON/OFF ; bit 1 = IRQ enable
    int period;         // timer's period between two IRQ
    int resetirq;       // address to acknowledge the timer's IRQ
};

extern volatile struct timer_s __timer_regs_map[NCPUS];

/**
 * \brief     start the timer to periodically raise an IRQ (only used by arch_init)
 * \param     timer  timer number (between 0 and NCPUS-1)
 * \param     tick   delay between two IRQ
 */
static void timer_init (int timer, int tick)
{
// TODO A remplir avec 2 lignes :
// 1) initialiser le registre period du timer n°timer avec la période tick (reçus en argument)
// 2) initialiser le registre mode   du timer n°timer avec 3 (démarre le timer avec IRQ demandée)
}

/**
 * \brief     isr for timer IRQ (only used by icu_init)
 * \param     timer device instance number
 */
static void timer_isr (int timer)
{
// TODO A remplir avec 3 lignes :
// 1) Acquiter l'interruption du timer en écrivant n'importe quoi dans le registre resetirq
// 2) afficher un message "Game Over" avec kprintf()
// 3) appeler la fonction kernel exit() (c'est une sortie définitive ici)
}

//-------------------------------------------------------------------------------------------------
// ICU Definition
// - NCPUS              is the number of available ICUs given to gcc (see Makefile)
// - struct icu_s       icu's registers map description
// - __icu_regs_map     declare icu's registers map defined in ldscript
// - volatile           means that compiler must really read from and write to memory
//                      thus it must not use registers to optimize
//-------------------------------------------------------------------------------------------------

struct icu_s {
    int state;          // state of all IRQ signals
    int mask;           // IRQ mask to chose what we need for this ICU
    int set;            // IRQ set   --> enable specific IRQs for this ICU
    int clear;          // IRQ clear --> disable specific IRQs for this ICU
    int highest;        // highest pritority IRQ number for this ICU
    int unused[3];      // 3 register addresses are not used
};

extern volatile struct icu_s __icu_regs_map[NCPUS];

/**
 * \brief     enable device IRQ siqnal
 * \param     icu  icu number (between 0 and NCPUS-1)
 * \param     irq  irq number to enable
 */
static void icu_set_mask (int icu, int irq)
{
    icu = icu % NCPUS;                      // the number of ICU is the number of CPU
    __icu_regs_map[icu].set = 1 << irq;     // set bit n'irq to 1, do not change the others
}

/**
 * \brief     get the highest priority irq number for an ICU instance
 *            There are as many ICU as CPU.
 *            Each ICU allows to select which IRQ must be handled by the corresponding CPU
 *            The IRQ selection is done thanks to the icu_set_mask() functioni.
 *            If there are several IRQs active at the same time, the register named "highest"
 *            gives the IRQ number with the highest priority
 * \param     icu  icu number (which is in fact the CPU number, thus between 0 and NCPUS-1)
 * \return    the highest priorty irq number that is for this ICU the lowest irq number
 */
static int icu_get_highest (int icu)
{
    icu = icu % NCPUS;                      // the number of ICU is the number of CPU
    return __icu_regs_map[icu].highest;     // get and return the  highest priority irq number
}

//-------------------------------------------------------------------------------------------------
// Architecture intialisation
//-------------------------------------------------------------------------------------------------

/**
 * isr_t is a type of an isr function
 *
 * This comment explains what is a type of function, and how to create one.
 * If we have a function : RETURN_TYPE FUNCTION_NAME ( list of ARG_TYPE ARG_NAME )
 *
 * For example : int erase (double * tab, unsigned size);
 *  * RETURN_TYPE = int          * FUNCTION_NAME = erase
 *  * ARG_TYPE 1  = double       * ARG_TYPE 2    = unsigned
 *  * ARG_NAME 1  = tab          * ARG_NAME 2    = size
 *
 * To create a variable named VF which is a pointer to a function, we must write :
 *    RETURN_TYPE (*VF) ( list of ARG_TYPE ARG_NAME );
 *    be warned that the parentheses around *VF are mandatory,
 *    otherwise gcc recognize a simple declaration of function
 *
 * For example, we can write :
 *    int (*VF) (double * tab, unsigned size); // declaration of VF
 *    VF = erase;                              // initialisation of VF
 *    int x = VF (tab, size);                  // this line is equivalent to
 *    int x = erase (tab, size);               // this one
 *
 * To create a type named TF for the pointer to a function, we must write :
 *    typedef RETURN_TYPE (*TF) ( list of ARG_TYPE ARG_NAME );
 *    the parentheses around *TF are also mandatory,
 *
 * For example, we can write :
 *    typedef int (*TF) (double * tab, unsigned size);
 *    TF VF ;
 *    VF = erase;
 *    int x = VF (tab, size);
 *    int x = erase (tab, size);
 */
typedef  void (*isr_t) (int);

/**
 * \brief   Default Interrupt Service Routine which will be executed if an unexpected IRQ happens
 */
static void isr_default (int irq)
{
    kprintf("ERROR: CPU %d receives unexpected IRQ n'%d\n", cpuid(), icu_get_highest (cpuid()));
    kpanic();
}

/**
 * The interrupt vector is a structure that binds the interrupt service routine to the interrupt
 * requests. Each IRQ may have its own ISR.
 *
 * An interrupt requets (IRQ) is an electrical signal comming from a device to warn of an event.
 * An Interrupt Service Routine (ISR) is a function that handles a specific IRQ.
 *
 * For each IRQ, we need to know which ISR handles it AND from which device it is come through.
 * That's why we have 2 tables here:
 * * irq_vector_isr[] given the ISR to execute for each IRQ
 *   For example: irq_vector_isr[13] = tty_isr; if the IRQ n'13 is bound to the tty device.
 * * irq_vector_dev[] given the device instance number from the IRQ.
 *   For example: irq_vector_dev[13] = 3; if the IRQ n'13 is bound to the tty device n'3.
 *   Because, we can have several tty, all of them share the ISR, but we need to know which
 *   instance in order to use the right device registers.
 *
 * Theses tables are filled in arch_init() with the knownledge of the SoC architecture.
 */
static isr_t irq_vector_isr[32] = { [0 ... 31] = isr_default };
static int   irq_vector_dev[32] = { [0 ... 31] = -1 };

/**
 * \brief   This function is the general interrupt dispatcher.
 *          It is called by the kentry routine when a CPU is interrupted by an IRQ
 *          Its aims is to find out which IRQ is now active to know which device needs the CPU.
 *          and to launch the right ISR of the right device instance by using irq_vector tables.
 */
void irq_handler (void)
{
    int irq = icu_get_highest (cpuid());        // IRQ nb with the highest prio for the current cpu
    irq_vector_isr[irq] (irq_vector_dev[irq]);  // launch the ISR for the bound device
}

/**
 * For the SoC almo1, IRQ n'x (that is ICU.PIN[x]) is wired to the Interrup Signal of device n'y
 *
 * There are at most 14 IRQs for almo1, but the real number depends of the prototype paramaters
 * There are as many timers as CPU, thus NCPUS timers
 * There are NTTYs ttys
 * There are also a DMA to perfom memcpy and optionnal Block Device (hard drive)
 *
 * Device IRQs are wired as following:
 * * ICU.PIN [0]  : timer 0
 *      "     "        "        depending on NCPUS (0 to 7)
 * * ICU.PIN [7]  : timer 7
 * * ICU.PIN [8]  : bd          Bloc Device (Hard Drive)
 * * ICU.PIN [9]  : dma         Direct Memory Access (Hard memcpy)
 * * ICU.PIN [10] : TTY0        TTY n'0
 *      "     "      "          depending on NTTYS (0 to 3)
 * * ICU.PIN [13] : TTY3
 */
void arch_init (int tick)
{
// TODO A remplir avec 4 lignes :
// 1) appel de la fonction timer_init(pour le timer 0 avec tick comme période
// 2) mise à 1 du bit 0 du registre ICU_MASK en utilisant la fonction icu_set_mask()
// 3) initialisation de la table irq_vector_isr[] vecteur d'interruption avec timer_isr() 
// 4) initialisation de la table irq_vector_dev[] vecteur d'interruption avec 0
}
