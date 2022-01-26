/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

#include <klibc.h>

/** \brief  Table filled by kpanic() and read by kdump
 *          this table cannot be static because it is used by hcpua.S file
 */
unsigned kpanic_regs_val[PANIC_REGS_NR];

/** \brief  register name, the order must the same as defined in hcpu.h files
 */
static char *kpanic_regs_name[PANIC_REGS_NR] = {
    "CR ", "AT ", "V0 ", "V1 ", "A0 ", "A1 ", "A2 ", "A3 ",
    "T0 ", "T1 ", "T2 ", "T3 ", "T4 ", "T5 ", "T6 ", "T7 ",
    "S0 ", "S1 ", "S2 ", "S3 ", "S4 ", "S5 ", "S6 ", "S7 ",
    "T8 ", "T9 ", "HI ", "LO ", "GP ", "SP ", "FP ", "RA ",
    "TSC", "BAR", "SR ", "EPC"
};

/** \brief  cause name
 */
static char *kpanic_cause_name[16] = {
    [0 ... 15] = "Other cause", // default value for all table case,
    [4] = "ADEL: Illegal load address",
    [5] = "ADES: Illegal store address",
    [6] = "IBE:  Segmentation fault for intruction",
    [7] = "DBE:  Segmentation fault for data",
    [10] = "RI:   Illegal instruction",
    [11] = "CPU:  coprocessor unreachable",
    [12] = "OVF:  Overflow",
    [13] = "OVF:  Overflow",    // It seems that it is a bug of the protoype
};

/** \brief  dump all registers values from a table filled by kpanic() then exit program
 *          this function cannot be static because it is used by hcpua.S file
 */
void kdump (unsigned reg_tab[])
{
    int nl = 0;
    int cause = (kpanic_regs_val[0] >> 2) & 0xF;

    kprintf ("\n[%d] <%p> KERNEL PANIC: %s\n\n",
            kpanic_regs_val[COUNT],             // TSC Time Stamp Counter
            kpanic_regs_val[EPC],               // faulty instruction address
            kpanic_cause_name[cause]);
    for (int i = 0; i < PANIC_REGS_NR; i++) {
        kprintf ("%s : %p     ", kpanic_regs_name[i], kpanic_regs_val[i]);
        if (++nl == 4) {
            kprintf ("\n");
            nl = 0;
        }
    }
    exit (1); // never returns
}
