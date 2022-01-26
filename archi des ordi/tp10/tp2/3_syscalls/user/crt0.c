/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-12-05
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

#include <syscalls.h>

extern int __bss_origin;        // first int of uninitialized global data
extern int __bss_end;           // first int of above the uninitialized global data
extern int main (void);         // tell the compiler that main() exists

//int syscall (int a0, int a1, int a2, int a3, int syscall_code)
__asm__ (
".globl syscall     \n"         // it is an external function, it must be declared globl
"syscall:           \n"         // syscall function label
"   lw  $2,16($29)  \n"         // since syscall has 5 parameters, the fifth is in the stack
"   syscall         \n"         // EPC=addr_of_syscall; j 0x80000180; c0_sr.EXL=1; c0_cause.XCODE=8
"   jr  $31         \n"         // $31 must not have changed
);

__attribute__ ((section (".start")))
void _start (void)
{
    int res;

    for (int *a = &__bss_origin; a != &__bss_end; *a++ = 0);
    res = main ();
    syscall (res, 0, 0, 0, SYSCALL_EXIT);
}
