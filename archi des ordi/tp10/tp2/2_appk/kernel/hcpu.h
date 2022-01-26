/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

#ifndef _HCPU_H_
#define _HCPU_H_

/**
 * \brief   clock cycle counter
 * \return  the number of cycles from the reset
 */
extern unsigned clock (void);

/**
 * \brief   start the user application when there is not threads yet, which is in .start section
 * \param   fun is the entry point of the user application
 */
extern void app_load (void * fun);

#endif//_HCPU_H_
