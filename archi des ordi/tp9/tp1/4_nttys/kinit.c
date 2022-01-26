/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

//--------------------------------------------------------------------------------------------------
// TTY Definition
// - NTTYS              is the number of available TTY
// - struct tty_s       tty's registers map description
// - __tty_regs_map     declare tty's registers map defined in ldscript
// - volatile           means that compiler must really read from and write to memory
//                      thus it must not use registers to optimize
//--------------------------------------------------------------------------------------------------

struct tty_s {
    int write;          // tty's output address
    int status;         // tty's status address something to read if not null)
    int read;           // tty's input address
    int unused;         // unused address
};

extern volatile struct tty_s __tty_regs_map[NTTYS];

//--------------------------------------------------------------------------------------------------

char * hello_0 = "Hello World!\n";

void kinit (void)
{
    char *s;
    char c;
    int tty = 0;

    for (s = hello_0; *s; s++) {                        // for all char in hello string
        __tty_regs_map[ tty%NTTYS ].write = *s;         // write it to the tty output register
    }

    while (1) {
        while (__tty_regs_map[ tty%NTTYS ].status == 0);// wait for a char typed on keyboard
        c = __tty_regs_map[ tty%NTTYS ].read;           // read the char
        __tty_regs_map[ tty%NTTYS ].write = c;          // print it (that is a software loopback)
    }

    while (1);                                          // infinite loop at the end
}
