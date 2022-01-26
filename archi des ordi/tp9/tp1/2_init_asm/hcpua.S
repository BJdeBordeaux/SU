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

    la      $26,    kinit               // get address of kinit() function
    jr      $26                         // goto kinit()
