#include <stdio.h>
#include <stdlib.h>
#include "multi_ensembles.h"

// #include "multi_ensembles.c"

int main() {
  // element_t *ens1 =  Creation_ensemble(5);
  // Affiche_ensemble(ens1);
  // printf("\n");
  // ens1 = Ajout_ensemble_trie(ens1, 0, 3);
  // Affiche_ensemble(ens1);
  // element_t *ens2 = Creation_ensemble(3);
  // Affiche_ensemble(ens2);
  // printf("%d\n",Inclus(ens1,ens2));
  // printf("%d\n", Intersection_vide(ens1,ens2));
  element_t *a = malloc(sizeof(element_t));a->valeur=3;a->frequence=1;a->suivant=NULL;
  a = NULL;
  element_t *b = malloc(sizeof(element_t));b->valeur=2;b->frequence=2;b->suivant=a;
  element_t *c =  malloc(sizeof(element_t));c->valeur=1;c->frequence=3;c->suivant=b;
  element_t *c2 =  malloc(sizeof(element_t));c2->valeur=0;c2->frequence=3;c2->suivant=c;
  
  element_t *d =  malloc(sizeof(element_t));d->valeur=5;d->frequence=3;d->suivant=NULL;
  element_t *d2 =  malloc(sizeof(element_t));d2->valeur=0;d2->frequence=3;d2->suivant=d;
  // c = Supprime_frequence_inf_seuil(c,2);
  // printf("cpt(c) = %d\n",taille(c));
  // d = Union(d, c);
  // Ajout_suivant(b, 55, 2);
  // d = Union(c2,d2);
  // d = Union_triee_rec2(c2,d2);
  // d = Intersection_triee_rec(c2,d2);
  // d = Intersection_triee(c2,d2);
  // d = Difference_triee_rec(c2, d2);
  // d = Difference_triee(c2, d2);
  // d = Xor_triee(c2, d2);
  Detruire(c2);
  Affiche_ensemble(c2);
  // Affiche_ensemble(d);
  // printf("%d\n",Inclus_rec(d,c));
  return 0;
}

