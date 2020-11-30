#ifndef _FONCTIONS_ENTIERS_H_
#define _FONCTIONS_ENTIERS_H_

#include <stdio.h>

void *dupliquer_int(const void *src);
void copier_int(const void *src, void *dst);
void detruire_int(void *data);
void afficher_int(const void *data);
int comparer_int(const void *a, const void *b);
int ecrire_int(const void *data, FILE *f);
void * lire_int(FILE *);

#endif
