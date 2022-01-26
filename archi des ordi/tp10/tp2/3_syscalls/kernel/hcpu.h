/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

#ifndef _HCPU_H_
#define _HCPU_H_

#define CR      0
#define AT      1
#define V0      2
#define V1      3
#define A0      4
#define A1      5
#define A2      6
#define A3      7
#define T0      8
#define T1      9
#define T2      10
#define T3      11
#define T4      12
#define T5      13
#define T6      14
#define T7      15
#define S0      16
#define S1      17
#define S2      18
#define S3      19
#define S4      20
#define S5      21
#define S6      22
#define S7      23
#define T8      24
#define T9      25
#define HI      26
#define LO      27
#define GP      28
#define SP      29
#define FP      30
#define RA      31
#define COUNT   32
#define BAR     33
#define SR      34
#define EPC     35
#define PANIC_REGS_NR   36

#ifndef __ASSEMBLER__

/**
 * __ASSEMBLER__ is automatically defined when gcc runs the assembler (.S source file)
 * (see https://bit.ly/32tv7u8) thus this part is not included in assembler files (.S)
 * In others words, the part bellow is only present in c files.
 */

/**
 * \brief     clock cycle counter
 * \return    the number of cycles from the reset
 */
extern unsigned clock (void);

/**
 * \brief  prints all registers' value on TTY0 (must be in kernel mode) then stops program
 */
extern void kpanic (void);

/**
 * \brief   start the user application when there is not threads yet, which is in .start section
 * \param   fun is the entry point of the user application
 */
extern void app_load (void * fun);

#endif//__ASSEMBLER__

#endif//_HCPU_H_
