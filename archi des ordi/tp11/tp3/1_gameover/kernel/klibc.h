/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

#ifndef _KLIBC_H_
#define _KLIBC_H_

#ifndef __DEPEND__      /// this condition allows to not include stdarg.h when makedepend is used
#include <stdarg.h>     // gcc's builtin include to use variadic function (https://bit.ly/3hLXjyC)
#include <stddef.h>     // gcc's builtin include with NULL, size_t, (https://bit.ly/3lBw3p6)
#endif//__DEPEND__
#include <hcpu.h>       // functions CPU dependant
#include <harch.h>      // functions ARCH dependant

#define RAND_MAX 32767  /* maximum random value by default, must be < 0x7FFFFFFE */
#define PRINTF_MAX 256  /* largest printed message */

/**
 * \brief     random int generator
 * \return    a random int between 0 and RAND_MAX
 * \details   https://en.wikipedia.org/wiki/Linear_congruential_generator (glibc generator)
 */
extern int rand (void);

/**
 * \brief     allow to define a specific random suite
 * \param     seed  any integer 
 */
extern void srand (unsigned seed);

/**
 * \brief     copies buffer src to the buffer dest (the buffers must be disjoints)
 * \param     dest destination buffer 
 * \param     src  source buffer
 * \param     n  number of bytes to copy 
 * \return    the dest buffer address
 */
void *memcpy (char *dest, char *src, unsigned n);

/**
 * \brief     copies the string src, included the ending byte '\0', to the buffer dest
 * \param     dest buffer where the source string must be copied 
 * \param     src  the source string
 * \param     n    size of the dest buffer
 * \return    the dest buffer address
 */
void *strncpy (char *dest, char *src, unsigned n);

/**
 * \brief     stop execution until a delay has elapsed measured in cycles
 * \param     nbcycles number of cycle to wait
 */
extern void delay (unsigned nbcycles);

/**
 * \brief     ascii to integer
 * \param     val   string to translate, with a decimal number
 * \return    the integer corresponding to val
 * \details   the number can be negative, the space at beginning are ignored
 */
extern int atoi (char *val);

/**
 * \brief     print a formated string to the TTY0 
 * \param     fmt   formated string 
 * \param     ...   variadic arguments, i.e. variable number of arguments
 * \return    number of printed char
 * \details   this a simplified version which handles only: %c, %s, $d, %x and %p
 */
extern int kprintf (char *fmt, ...);

/**
 * \brief     
 * \param     str   buffer of chars where string is formed 
 * \param     size  size of buffer
 * \param     fmt   formated string 
 * \param     ...   variadic arguments, i.e. variable number of arguments
 * \return    number of printed char
 * \details   this a simplified version which handles only: %c, %s, $d, %x and %p
 */
extern int snprintf(char *buffer, unsigned size, char *fmt, ...);

/** 
 * \brief     exit the application, thus never returns
 * \param     status return value of the application
 */
extern void exit (int status);

#endif//_KLIBC_H_
