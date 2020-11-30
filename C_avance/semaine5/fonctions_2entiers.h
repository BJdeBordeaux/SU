#ifndef _FONCTIONS_2ENTIERS_H_
#define _FONCTIONS_2ENTIERS_H_

#include <stdio.h>

typedef struct double_int {
  int a;
  int b;
} Double_int;


void *dupliquer_2int(const void *src);
void copier_2int(const void *src, void *dst);
void detruire_2int(void *data);
void afficher_2int(const void *data);
int comparer_2int(const void *a, const void *b);
int ecrire_2int(const void *data, FILE *f);
void * lire_2int(FILE *);

#endif
