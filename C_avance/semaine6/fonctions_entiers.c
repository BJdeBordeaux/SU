#include <stdlib.h>
#include <stdio.h>
#include "devel.h"

void *dupliquer_int(const void *src) {
  int *isrc=(int *)src;
  int *idst=malloc(sizeof(int));
  if (idst==NULL) {
    affiche_message("Erreur d'allocation");
    return NULL;
  }
  *idst=*isrc;
  return (void *)idst;
}

void copier_int(const void *src, void *dst) {
  int *isrc=(int *)src;
  int *idst=(int *)dst;
  *idst=*isrc;
}

void detruire_int(void *data) {
  free(data);
}

void afficher_int(const void *data) {
  int *idata=(int *)data;
  printf("%d",*idata);
}

int comparer_int(const void *a, const void *b) {
  int *ia=(int *)a;
  int *ib=(int *)b;
  return (*ia>*ib)-(*ia<*ib);
}

int ecrire_int(const void *data, FILE *f) {
  const int *idata=(const int *)data;
  return fprintf(f, "%d", *idata);
}

void * lire_int(FILE *f) {
  int i;
  int r=fscanf(f," %d",&i);
  if (r<1) return NULL;
  int *pi=(int *)malloc(sizeof(int));
  *pi=i;
  return pi;
}
