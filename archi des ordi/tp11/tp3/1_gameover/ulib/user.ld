/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

/* Description of the physical memory map 
 * -----------------------------------------------------------------------------
 */

/* Device segments definition */

__tty_regs_map   = 0xd0200000 ;     /* tty's registers map */

/* Memory segments definition */

__text_origin    = 0x7F400000 ; /* first byte address of user code region */
__text_length    = 0x00100000 ;
__data_origin    = 0x7F500000 ; /* first byte address of user data region */
__data_length    = 0x00B00000 ;
__data_end       = __data_origin  + __data_length  ; /* first addr after user data region */

MEMORY {
    text_region  : ORIGIN = __text_origin,  LENGTH = __text_length
    data_region  : ORIGIN = __data_origin,  LENGTH = __data_length
}

/* Description of the output sections and in which region they are put
 * -----------------------------------------------------------------------------
 */

SECTIONS {
    .text   : { 
        *(.start);          /* with _start() which calls main() expected at beginning of .text */
        *(.text)            /* all others codes */
     } > text_region
    .data : {
        *(.*data*)          /* initialized global variables */
        . = ALIGN(4);       /* move the filling pointer to an word aligned address */
        __bss_origin = .;   /* first byte of uninitialized global variables */
        *(.*bss*)           /* uninitialized global variables */
        . = ALIGN(4);       /* move the filling pointer to an word aligned address */
        __bss_end = .;      /* first byte after the bss section */
    } > data_region
}
