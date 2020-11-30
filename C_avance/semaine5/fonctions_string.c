#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "devel.h"

void *dupliquer_str(const void *src) {
  char **isrc = (char **)src;
  char *idest = strdup(*isrc);
  if(idest == NULL){
    affiche_message("Erreur de strdup().");
    return NULL;
  }
  *idest = **isrc;
  return (void*) idest;
}

void copier_str(const void *src, void *dst) {
  char** isrc = (char**) src;
  char** idst = (char**) dst;
  char* tmp = strdup(*isrc);
  *idst = tmp;
}

void detruire_str(void *data) {
  free(data);
}

void afficher_str(const void *data) {
  char* isrc = (char* ) data;
  printf("%s", isrc);
}

int comparer_str(const void *a, const void *b) {
  return strcmp(a, b);
}

int ecrire_str(const void *data, FILE *f) {
  char** idata = (char**) data;
  return fprintf(f, "%s ", *idata);
}

void * lire_str(FILE *f) {
  char* str = malloc(sizeof(char)*255);
  if(str == NULL){
    affiche_message("Erreur d'allocation.");
    return NULL;
  }

  int reussi = fscanf(f, " %s", str);
  if(reussi < 1){
    affiche_message("Erreur de lecture.");
    return NULL;
  }

  char* res = strdup(str);
  free(str);
  return (void*) res;
}
