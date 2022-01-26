/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-12-05
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

extern int __bss_origin;                // first int of uninitialized global data
extern int __bss_end;                   // first int of above the uninitialized global data
extern int main (void);                 // tell the compiler that main() exists
extern volatile int __tty_regs_map;     // declare tty output defined in ldscript

__attribute__ ((section (".start")))
void _start (void)
{
    // erase the global unitialize variables
    for (int *a = &__bss_origin; a != &__bss_end; *a++ = 0);

    main ();

    // write "bye!" to the tty output register, then stops
    for (char *s = "bye!\n"; *s; __tty_regs_map = *s++);
    while (1);  // There is not syscall handler yet then we need be stuck here for ever
}
