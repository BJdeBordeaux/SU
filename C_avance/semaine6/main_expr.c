#include "arbre_expr.h"

int main(void) {
  printf("Saisir l'expression: ");
  PArbreBinaire pabe=construire_arbre_expr(stdin);
  float var_lue[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,
		     0,0,0,0,0,0,0,0,0,0,0,0,0};
  demander_variables(pabe,var_lue);
  printf("Resultat de l'evaluation de l'arbre: %f\n",evaluer(pabe->racine,var_lue));

  ecrire_ab(pabe,"arbre_expr.txt");
  detruire_ab(pabe);

  FILE *f=fopen("arbre_expr.txt", "r");
  if (f==NULL) {
    printf("Erreur lors de l'ouverture du fichier\n");
    return 1;
  }
  pabe=construire_arbre_expr(f);
  fclose(f);
  afficher_ab_prefixe(pabe);
  printf("\n");
  printf("Resultat de l'evaluation de l'arbre (apres lecture): %f\n",evaluer(pabe->racine,var_lue));

  detruire_ab(pabe);

  
  return 0;
}
