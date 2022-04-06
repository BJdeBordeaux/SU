#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include "affiche_tas.h"

int pred_zone = -1;

int first_fit(int taille, int *pred)
{
    int pred_org = *pred;
    int i = libre;
    while ((tas[i] < taille) && (tas[i + 1] != -1))
    {
        *pred = i + tas[i] + 1;
        i = tas[i + 1];
    }
    if (tas[i] < taille)
    {
        i = -1;
        *pred = pred_org;
    }
    
    return i;
}

char *tas_malloc(unsigned int taille)
{

    int i = first_fit(taille, &pred_zone);
    if (i == -1)
    {
        return NULL;
    }

    int prochain_disponible = i + taille + 1;
    tas[prochain_disponible] = tas[i] - taille - 1;
    if (prochain_disponible < TAILTAS)
    {
        tas[prochain_disponible + 1] = tas[i + 1];
    }
    if (i == libre)
    {
        libre = prochain_disponible;
    }
    tas[i] = taille;
    return &tas[i + 1];
}

int tas_free(char *ptr)
{
    
    return 0;
}

int main(int argc, char **argv)
{
    pred_zone = -1;
    tas_init();
    char *p1, *p2, *p3, *p4, *p5;
    p1 = (char *)tas_malloc(10);
    p2 = (char *)tas_malloc(9);
    p3 = (char *)tas_malloc(5);
    strcpy(p1, "tp 1");
    strcpy(p2, "tp 2");
    strcpy(p3, "tp 3");
    tas_free(p2);
    p4 = (char *)tas_malloc(8);
    strcpy(p4, "systeme");
    afficher_tas();
}