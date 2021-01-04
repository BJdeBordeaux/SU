#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arbre_binaire.h"
#include "fonctions_entiers.h"

int main(void) {

  /* a completer. Exercice 4, question 1 */
  PArbreBinaire pab = creer_arbre(1, dupliquer_int,copier_int, detruire_int, afficher_int, comparer_int, ecrire_int, lire_int);
  int i, a;
  int nbEntierAleatoire = 15;
  
  // ajout d'entiers aleatoire
  for (i = 0; i < nbEntierAleatoire; i++)
  {
    a = rand()%100;
    ajouter_abr(pab, &a);
  }
  afficher_ab_prefixe_map(pab);
  printf("Check point 1\n");

  // recherche des entiers entre 0 et 99
  for (i = 0; i < 100; i++)
  {
    // printf("%d\ ", i);
    if(chercher_abr(pab, &i) != NULL){
      printf("%d ok, ", i);
    }
  }

  printf("Check point 2\n");
  detruire_ab(pab);
  

  // lecture et ecriture
  PArbreBinaire pabb = creer_arbre(0, dupliquer_int,copier_int, detruire_int, afficher_int, comparer_int, ecrire_int, lire_int);
  lire_abr(pabb, "int_arbre_in.txt");
  afficher_ab_prefixe_map(pabb);
  ecrire_ab(pabb, "int_arbre_out.txt");
  detruire_ab(pabb);
  printf("Check point 3\n");
  return 0;
}
