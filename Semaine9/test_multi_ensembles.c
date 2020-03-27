#include <stdio.h>
#include <stdlib.h>
#include "multi_ensembles.h"

// #include "multi_ensembles.c"

int main() {
  element_t *ens1 =  Creation_ensemble(5);
  Affiche_ensemble(ens1);
  printf("\n");
  // ens1 = Ajout_ensemble_trie(ens1, 0, 3);
  // Affiche_ensemble(ens1);
  element_t *ens2 = Creation_ensemble(3);
  Affiche_ensemble(ens2);
  // printf("%d\n",Inclus(ens1,ens2));
  printf("%d\n", Intersection_vide(ens1,ens2));
  return 0;
}