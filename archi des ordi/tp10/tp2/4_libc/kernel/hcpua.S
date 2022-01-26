/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-28
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

#include <hcpu.h>
#include <syscalls.h>

//--------------------------------------------------------------------------------------------------
// Boot code
//--------------------------------------------------------------------------------------------------

.section .boot,"ax"                     // new section: .boot (see https://bit.ly/3gzKWob)
                                        // flags "ax": a -> allocated means section is in memory
                                        //             x -> section contains instructions

boot:                                   // must be 0xBFC0000 for the MIPS

    la      $29,    __kdata_end         // define stack ptr (first address after kdata region)
    la      $26,    kinit               // get address of kinit() function
    jr      $26                         // goto kinit()

.section    .kentry,"ax"                // "ax": allocated executable
.org        0x180                       // ktext is 0x80000000 but kentry is 0x80000180

//--------------------------------------------------------------------------------------------------
// kernel entry for all causes,
// for now, kernel only handles syscall, then if is not a syscall, it is a panic
//--------------------------------------------------------------------------------------------------

kentry:                                 // kernel entry

    mfc0    $26,    $13                 // read CR (Cause Register)
    andi    $26,    $26,    0x3C        // apply cause mask (keep bits 2 to 5)
    li      $27,    0x20                // 0x20 is the syscall code
    bne     $26,    $27,    kpanic      // if not then that is not a syscall

//--------------------------------------------------------------------------------------------------
// cause syscall : $2 is the syscall number, $4..$7 are the syscall args
//--------------------------------------------------------------------------------------------------

ksyscall:

    addiu   $29,    $29,    -8*4        // context for $31 + EPC + SR + syscall_code + 4 args
    mfc0    $27,    $14                 // $27 <- EPC (addr of syscall instruction)
    mfc0    $26,    $12                 // $26 <- SR (status register)
    addiu   $27,    $27,    4           // $27 <- EPC+4 (return address)
    sw      $31,    7*4($29)            // save $31 because it will be erased
    sw      $27,    6*4($29)            // save EPC+4 (return address of syscall)
    sw      $26,    5*4($29)            // save SR (status register)
    sw      $2,     4*4($29)            // save syscall code (useful for debug message)
    mtc0    $0,     $12                 // SR <- kernel-mode without INT (UM=0 ERL=0 EXL=0 IE=0)

    la      $26,    syscall_vector      // $26 <- table of syscall functions
    andi    $2,     $2,     SYSCALL_NR-1// apply syscall mask
    sll     $2,     $2,     2           // compute syscall index (mutiply by 4)
    addu    $2,     $26,    $2          // $2 <- & syscall_vector[$2]
    lw      $2,     ($2)                // at the end: $2 <- syscall_vector[$2]
    jalr    $2                          // call syscall function

    lw      $26,    5*4($29)            // get old SR
    lw      $27,    6*4($29)            // get return address of syscall
    lw      $31,    7*4($29)            // restore $31 (return address of syscall function)
    mtc0    $26,    $12                 // restore SR
    mtc0    $27,    $14                 // restore EPC
    addiu   $29,    $29,    8*4         // restore stack pointer
    eret                                // return : jr EPC with EXL <- 0

//--------------------------------------------------------------------------------------------------
// Not managed cause, thus call kpanic () that displays the registers' value and stops the program
//--------------------------------------------------------------------------------------------------

.globl kpanic // ------------------------- void kpanic (void)
kpanic:

    addiu   $29,    $29,   -4           // reserve space for arg of kdump()

    la      $26,    kpanic_regs_val     // save all registers in kpanic_regs_val[]
.set noat
    sw      $1,     AT*4 ($26)
.set at
    sw      $2,     V0*4 ($26)
    sw      $3,     V1*4 ($26)
    sw      $4,     A0*4 ($26)
    sw      $5,     A1*4 ($26)
    sw      $6,     A2*4 ($26)
    sw      $7,     A3*4 ($26)
    sw      $8,     T0*4 ($26)
    sw      $9,     T1*4 ($26)
    sw      $10,    T2*4 ($26)
    sw      $11,    T3*4 ($26)
    sw      $12,    T4*4 ($26)
    sw      $13,    T5*4 ($26)
    sw      $14,    T6*4 ($26)
    sw      $15,    T7*4 ($26)
    sw      $16,    S0*4 ($26)
    sw      $17,    S1*4 ($26)
    sw      $18,    S2*4 ($26)
    sw      $19,    S3*4 ($26)
    sw      $20,    S4*4 ($26)
    sw      $21,    S5*4 ($26)
    sw      $22,    S6*4 ($26)
    sw      $23,    S7*4 ($26)
    sw      $24,    T8*4 ($26)
    sw      $25,    T9*4 ($26)
    sw      $28,    GP*4 ($26)
    sw      $29,    SP*4 ($26)
    sw      $30,    FP*4 ($26)
    sw      $31,    RA*4 ($26)
    mfc0    $2,     $9
    mfc0    $3,     $10
    mfc0    $4,     $12
    mfc0    $5,     $13
    mfc0    $6,     $14
    mfhi    $7
    mflo    $8
    sw      $2,     COUNT*4 ($26)
    sw      $3,     BAR*4 ($26)
    sw      $4,     SR*4($26)
    sw      $5,     CR*4($26)
    sw      $6,     EPC*4($26)
    sw      $7,     HI*4($26)
    sw      $8,     LO*4($26)

    move    $4,     $26                 // get arg
    la      $26,    kdump               // kdump( kpanic_regs_val )
    j       $26                         // kdump ends with exit() and never retuns

//--------------------------------------------------------------------------------------------------
// Others cpu dependant functions
//--------------------------------------------------------------------------------------------------

.globl clock // -------------------------- int clock (void) is an external function
clock:                                  // clock is a terminal function then don't use the stack

    mfc0    $2,     $9                  // 32 bits counter in the coprocessor system (c0_$9)
    jr      $31                         // get it in $2 and return

//--------------------------------------------------------------------------------------------------
// app managment
//--------------------------------------------------------------------------------------------------

.globl app_load // ----------------------- void app_load (void * fun) called by kinit()
app_load:                               // call when we exit kinit() function to go to user code

    mtc0   $4,      $14                 // put _start address in c0_EPC
    li     $26,     0x12                // define next status reg. value
    mtc0   $26,     $12                 // UM <- 1, IE <- 0, EXL <- 1
    la     $29,    __data_end           // define new user stack pointer
    eret                                // j EPC and EXL <- 0
