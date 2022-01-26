/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

extern volatile int __tty_regs_map;     // declare tty's registers map defined in ldscript
                                        // volatile means that the compiler must write in memory
                                        // each time and cannot use a register to optimize

char hello[] = "Hello World!\n";        // define a global string

void kinit (void)
{
    char *s;

    for (s = hello; *s; s++) {          // for all char in hello string
        __tty_regs_map = *s;            // write it to the tty output register
    }
    while (1);                          // infinite loop at the end
}
