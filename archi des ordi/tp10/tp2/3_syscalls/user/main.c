/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

#include <syscalls.h>

char hello[] = "app is alive at ";

// unsigned to ascii, that is temporary before to have a printf()
char utoa_buffer[16];
char *utoa (int val)
{
    char *res;

    res = &utoa_buffer[15];
    *res = 0;
    do {
        *--res = (val % 10) + '0';  // compute the unit digit
        val = val / 10;             // go to the next digit
    }
    while (val);
    return res;
}

int main (void)
{
    int t0;

    t0 = syscall (0, 0, 0, 0, SYSCALL_CLOCK);
    syscall (0, (int) hello, 0, 0, SYSCALL_TTY_PUTS);
    syscall (0, (int) utoa (t0), 0, 0, SYSCALL_TTY_PUTS);

    syscall (1, 0, 0, 0, SYSCALL_EXIT);

    return 0;
}
