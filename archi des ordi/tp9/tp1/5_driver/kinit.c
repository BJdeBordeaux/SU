/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

#include <harch.h>

char hello[] = "\nHello ";
char end[] = "\n\nAu revoir\n";
char ask[] = "Entrez votre nom : ";
char cont[] = "Continue [Y]/N : ";
char name[] = { [0 ... 63] = 'x' };             // table of 64 bytes filled by 'x' character

void kinit (void)
{
    char c;

    tty_puts (0, ask);
    tty_gets (0, name, sizeof(name));

    do {
        tty_puts (0, hello);                    // print hello string
        tty_puts (0, name);
        tty_puts (0, cont);
        c = tty_getc (0);                       // read one char (with loopback)
    }
    while (c != 'N');                           // until the char is 'q'

    tty_puts (0, end);                          // print end string on terminal 0

    while (1);                                  // infinite loop
}
