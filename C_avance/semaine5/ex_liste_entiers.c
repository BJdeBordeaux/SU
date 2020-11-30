
#include <stdlib.h>
#include "liste.h"
#include "devel.h"
#include "fonctions_entiers.h"
#include <assert.h>

int main(void) {

  /* a completer. Exercice 4, question 1 */
  PListe pliste = malloc(sizeof(Liste));
  pliste->dupliquer = dupliquer_int;
  pliste->copier = copier_int;
  pliste->afficher = afficher_int;
  pliste->comparer = comparer_int;
  pliste->ecrire = ecrire_int;
  pliste->lire = lire_int;
  pliste->detruire = detruire_int;

  FILE *file = NULL;
  int* tmp, *tmp2;
  int i;

  for (i = 5; i >= 0; i--)
  {
    tmp = malloc(sizeof(int));
    *tmp = i;
    inserer_debut(pliste, tmp);
  }
  

  for (i = 11; i < 16; i++)
  {
    tmp = malloc(sizeof(int));
    *tmp = i;
    inserer_fin(pliste, tmp);
  }
  
  for (i = 6; i < 11; i++)
  {
    tmp = malloc(sizeof(int));
    *tmp = i;
    inserer_place(pliste, tmp);
  }
  
  *tmp = 100;
  PElement pEl = pliste->elements;
  pliste->copier(tmp, pEl->data);
  *tmp = *(int*) pliste->dupliquer(pEl->data);
  assert(*tmp == 100);

  tmp2 = malloc(sizeof(int));
  *tmp2 = 200;
  assert(pliste->comparer(tmp, tmp2) < 0);

  file = fopen("entier_entree.txt", "r");
  tmp = (int*) pliste->lire(file);
  fclose(file);
  assert(*tmp == 1000);

  file = fopen("entier_sortie.txt", "w");
  pliste->ecrire(tmp, file);
  fclose(file);

  afficher_liste(pliste);

  detruire_liste(pliste);

  return 0;
}
