/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
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
