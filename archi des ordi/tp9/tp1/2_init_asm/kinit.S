/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

.text                                   // open the section .text

.globl kinit                            // tell the compiler that init is an external symbol
                                        // in order to the boot code find it
kinit:
    la      $4, hello                   // $4 <- address of string: "hello..."
    la      $5, __tty_regs_map          // $5 <- address of tty's registers map (cf. ldscript)

print:
    lb      $8, 0($4)                   // get current char
    sb      $8, 0($5)                   // send the current char to the tty
    addiu   $4, $4, 1                   // point to the next char
    bne     $8, $0, print               // check that it is not null, if ok it must be printed

exit:                                   // infinite loop
    j       exit

.data                                   // open the section .data

hello:
    .asciiz "Hello World!\n"
