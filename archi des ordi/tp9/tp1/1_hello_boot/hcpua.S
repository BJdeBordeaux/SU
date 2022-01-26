/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

//--------------------------------------------------------------------------------------------------
// Boot code
//--------------------------------------------------------------------------------------------------

.text                                   // section for this code

boot:                                   // must be 0xBFC0000 for the MIPS

    la      $4, hello                   // $4 <- address of string: "hello..."
    la      $5, __tty_regs_map          // $5 <- address of tty's registers map (cf. ldscript)

print:

    lb      $8, 0($4)                   // get current char
    sb      $8, 0($5)                   // send the current char to the tty
    addiu   $4, $4, 1                   // point to the next char
    bne     $8, $0, print               // check that it is not null, if yes it must be printed

dead:                                   // infinite loop (nothing else to do)

    j       dead

hello:
    .ascii  "Hello World!\n"            // string to print (put for now in .text section)
    .asciiz "Type <CTRL-C> on Terminal to stop the simulator\n"
