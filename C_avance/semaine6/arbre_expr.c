#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"arbre_expr.h"

void *dupliquer_expr(const void *src) {
  /* a completer. Exercice 5, question 1 */
  return NULL; // pour que cela compile
}

void copier_expr(const void *src, void *dst) {
  /* a completer. Exercice 5, question 1 */
}

void detruire_expr(void *data) {
  /* a completer. Exercice 5, question 1 */
}

void afficher_expr(const void *data) {
  /* a completer. Exercice 5, question 2 */
}

int comparer_expr(const void *a, const void *b) {
  // On ne s'en servira pas...
  return 0;
}

int ecrire_expr(const void *data, FILE *f) {
  /* a completer. Exercice 5, question 2 */
  return 1;
}

void * lire_expr(FILE *f) {
  /* a completer. Exercice 5, question 3 */
  return NULL; // pour que cela compile
}  

PNoeudBinaire construire_arbre_expr_rec(FILE *f, PArbreBinaire pab) {
  /* a completer. Exercice 5, question 4 */
  return NULL; // pour que cela compile
}

PArbreBinaire construire_arbre_expr(FILE *f) {
  /* a completer. Exercice 5, question 4 */
  return NULL; // pour que cela compile
}

void init_var_a_lire(void *data, void *oa) {
  int *val=(int *)oa;
  DataExpr *de=(DataExpr *)data;
  if (de->type_noeud==VAR)
    val[de->indice_var]=1;
}

void demander_variables(PArbreBinaire pabe, float var_lue[]) {
  int val[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0,0,0};
  map_ab_prefixe(pabe,init_var_a_lire,val);
  int i;
  float var;
  for (i=0;i<26;i++) 
    {
      if (val[i]) 
	{
	  printf("%c=", 'A'+i);
	  scanf("%f", &var);
	  var_lue[i]=var;
	}
    }	
}

float evaluer(PNoeudBinaire pabe, float var_lue[])
{
  /* a completer. Exercice 5, question 5 */
  return 42.; // pour que cela compile
}
