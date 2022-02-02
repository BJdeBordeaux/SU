#include <stdio.h>
#include <string.h>
#include "fonctions.h"

int main(int argc, char *argv[])
{
    // char buff[255];
    // while (1)
    // {
    //     printf ("Entrez votre command, 'q' pour quitter\n");
    //     scanf("%s", buff);
    //     printf("votre commande: %s\n", buff);
    //     if(strncmp(buff, "q", 1)==0){
    //         break;
    //     }
    //     lance_commande(buff);
    // }

    for (int i = 1; i < argc; i++)
    {
        lance_commande(argv[i]);
    }
    
    
    return 0;
}
