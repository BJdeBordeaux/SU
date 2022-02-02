#include <stdio.h>
#include <string.h>
#include "fonctions.h"

int main(int argc, char *argv[])
{

    for (int i = 1; i < argc; i++)
    {
        lance_commande2(argv[i]);
    }
    
    
    return 0;
}
