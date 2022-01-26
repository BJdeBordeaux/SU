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

__boot_origin    = 0xbfc00000 ;     /* first byte address of boot region */
__boot_length    = 0x00001000 ;     /* boot region size */

MEMORY {
    boot_region : ORIGIN = __boot_origin, LENGTH = __boot_length
}

/* Description of the output sections and in which region they are put
 * -----------------------------------------------------------------------------
 */

SECTIONS {
    .boot : {                       /* output section with boot code */
        hcpua.o(.text)              /* add the .text section of hcpua.o */
    } > boot_region                 /* in the boot_region described above */
}
