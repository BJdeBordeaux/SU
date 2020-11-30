#ifndef _FONCTIONS_STRING_H_
#define _FONCTIONS_STRING_H_

#include <stdio.h>

void *dupliquer_str(const void *src);
void copier_str(const void *src, void *dst);
void detruire_str(void *data);
void afficher_str(const void *data);
int comparer_str(const void *a, const void *b);
int ecrire_str(const void *data, FILE *f);
void * lire_str(FILE *);

#endif
