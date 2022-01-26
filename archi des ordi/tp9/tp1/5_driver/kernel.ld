/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

/* Description of the physical memory map 
 * -----------------------------------------------------------------------------------------------*/

/* Device segments definition */

__tty_regs_map   = 0xd0200000 ;     /* tty's registers map */

/* Memory segments definition */

__boot_origin    = 0xbfc00000 ; /* first byte address of boot region */
__boot_length    = 0x00001000 ; /* boot region size */
__ktext_origin   = 0x80000000 ; /* first byte address of kernel code region */
__ktext_length   = 0x00020000 ;
__kdata_origin   = 0x80020000 ; /* first byte address of kernel data region */
__kdata_length   = 0x003E0000 ;
__kdata_end      = __kdata_origin + __kdata_length ; /* first address after data region */

MEMORY {
    boot_region  : ORIGIN = __boot_origin,  LENGTH = __boot_length
    ktext_region : ORIGIN = __ktext_origin, LENGTH = __ktext_length
    kdata_region : ORIGIN = __kdata_origin, LENGTH = __kdata_length
}

/* Description of the output sections and in which region they are put
 * -----------------------------------------------------------------------------------------------*/

SECTIONS {
    .boot : { 
        *(.boot)            /* boot code in boot region */
    } > boot_region
    .ktext : {
        *(.text)            /* code of any object file (except boot) in kernel code region) */
    } > ktext_region
    .kdata : {
        *(.*data*)          /* initialized global variables */
    } > kdata_region
}
