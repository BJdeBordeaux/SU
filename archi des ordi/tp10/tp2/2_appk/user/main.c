/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

extern volatile int __tty_regs_map;      // declare tty output defined in ldscript

int main (void)
{
    char *s;

    for (s = "hello World from user!\n"; *s; s++) {   // for all char in hello string
        __tty_regs_map = *s;             // write it to the tty output register
    }
    return 0;
}
