/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-11-21
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

#include <libc.h>

int main (void)
{
    char name[64];

    fprintf (0,"[%d] Hello World!\n", clock());
    
    fprintf (0, "What's your name? ");
    fgets (name, sizeof(name), 0);
    if (name[strlen(name)-1] == '\n')
        name[strlen(name)-1] = 0;

    do {
        fprintf (0, "\n[%d] app is alive\n", clock());
        fprintf (0, "%s, do I stop (Y/N)?", name);
    } while ( fgetc(0) != 'Y');
    return 0;
}

