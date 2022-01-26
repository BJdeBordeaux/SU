/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-30
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

#ifndef _SYSCALL_H_
#define _SYSCALL_H_

#define SYSCALL_EXIT        0
#define SYSCALL_TTY_PUTC    1
#define SYSCALL_TTY_GETC    2
#define SYSCALL_TTY_PUTS    3
#define SYSCALL_TTY_GETS    4
#define SYSCALL_CLOCK       5
#define SYSCALL_NR          32

#if (SYSCALL_NR != 16) && (SYSCALL_NR != 32)
#   error SYSCALL_NR doit être une puissance de 2
#endif

/**
 * __ASSEMBLER__ is automatically defined when gcc runs the assembler (.S source file)
 * (see https://bit.ly/32tv7u8) thus this part is not included in assembler files (.S)
 */
#ifndef __ASSEMBLER__
/**
 * syscall_vector[] is an array of function pointers that have at most 5 args, but often less than 5
 */
extern void *syscall_vector[];
/**
 * \brief   syscall is a function with 2 implementations : one for the user, one for the kernel.
 *          - For the user : syscall() defines how to entry the kernel, written in assembler in crt0.c
 *          - For the kernel : syscall() is the default function called when none other function has
 *                             been planned for the syscall_code given as 5e argument
 */
extern int syscall (int a0, int a1, int a2, int a3, int syscall_code);
#endif

#endif//_SYSCALL_H_
