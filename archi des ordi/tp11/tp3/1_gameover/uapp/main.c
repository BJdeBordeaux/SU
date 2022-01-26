/*------------------------------------------------------------------------------------------------*\
   _     ___    __  
  | |__ /'v'\  / /      \date        2021-12-11
  | / /(     )/ _ \     \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
  |_\_\ x___x \___/ 
  
\*------------------------------------------------------------------------------------------------*/

#include <libc.h>

int main (void)
{
    int guess;
    int random;
    char buf[8];
    char name[16];

    fprintf(0,"Tapez votre nom : ");
    fgets(name, sizeof(name), 0);
    if (name[strlen(name)] == '\n')
        name[strlen(name)] = 0;
    srand(clock()); // start the random generator with a "random" seed.

    random = 1 + rand() % 99;
    fprintf(0,"Donnez un nombre entre 1 et 99: ");
    do {
        fgets(buf, sizeof(buf), 0);
        guess = atoi (buf);
        if (guess < random)
            fprintf(0,"%d est trop petit: ", guess);
        else if (guess > random)
            fprintf(0,"%d est trop grand: ", guess);
    } while (random != guess);

    fprintf(0,"\nGagné %s\n", name);
    return 0;
}
