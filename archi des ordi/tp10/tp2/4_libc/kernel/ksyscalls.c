/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-30
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

#include <syscalls.h>
#include <klibc.h>

int syscall (int a0, int a1, int a2, int a3, int syscall_code)
{
    kprintf ("Unknown Syscall : %d\n", syscall_code);
    kprintf ("a0 : 0x%p (%d)\n", a0, a0);
    kprintf ("a1 : 0x%p (%d)\n", a1, a1);
    kprintf ("a2 : 0x%p (%d)\n", a2, a2);
    kprintf ("a3 : 0x%p (%d)\n", a3, a3);
    return 1;
}

void *syscall_vector[] = {
    [0 ...  SYSCALL_NR - 1] = syscall,   /* default value */
    [SYSCALL_EXIT         ] = exit,
    [SYSCALL_TTY_PUTC     ] = tty_putc,
    [SYSCALL_TTY_GETC     ] = tty_getc,
    [SYSCALL_TTY_PUTS     ] = tty_puts,
    [SYSCALL_TTY_GETS     ] = tty_gets,
    [SYSCALL_CLOCK        ] = clock,
};
