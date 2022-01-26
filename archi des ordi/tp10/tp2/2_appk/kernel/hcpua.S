/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

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

.text                                   // that code must in ktext region

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
    li     $26,     2                   // define next status reg. value
    mtc0   $26,     $12                 // UM <- 0, IE <- 0, EXL <- 1
    eret                                // j EPC and EXL <- 0

