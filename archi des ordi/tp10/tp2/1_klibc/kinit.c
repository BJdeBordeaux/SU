/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

#include <klibc.h>              // standard functions for the kernel

void kinit (void)
{

    char name[64];
    // put bss sections to zero. bss contains uninitialised global variables
    extern int __bss_origin;    // first int of bss section (defined in ldscript kernel.ld)
    extern int __bss_end;       // first int of above bss section (defined in ldscript kernel.ld)
    for (int *a = &__bss_origin; a != &__bss_end; *a++ = 0);

    memcpy(name, "bonjour", 8);

    // say Hello !
    kprintf ("[%d] Hello World!\n", clock());

    exit (1);                   // stop the execution
}
