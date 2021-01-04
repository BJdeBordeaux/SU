#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"arbre_expr.h"
#include"devel.h"

void *dupliquer_expr(const void *src) {
  DataExpr *isrc = (DataExpr*) src;
  DataExpr *idst = (DataExpr*) malloc(sizeof(DataExpr));
  if (idst==NULL) {
    affiche_message("Erreur d'allocation");
    return NULL;
  }
  *idst = *isrc;
  return (void *)idst; 
}

void copier_expr(const void *src, void *dst) {
  DataExpr *isrc = (DataExpr*) src;
  DataExpr *idst = (DataExpr*) dst;
  *idst = *isrc; 
}

void detruire_expr(void *data) {
  free(data);
}

void afficher_expr(const void *data) {
  DataExpr* idata = (DataExpr*) data;
  if(idata){
    if (idata->indice_var >= 0)
    {
      fprintf(stdout, " %c ", idata->indice_var + 'A');
    }else if(idata->operateur){
      fprintf(stdout, " %c ", idata->operateur);
    }else if (idata->constante){
      fprintf(stdout, " %f ", idata->constante);
    }else{
      affiche_message("Erreur de valeur.");
    }
  }
}

int comparer_expr(const void *a, const void *b) {
  // On ne s'en servira pas...
  return 0;
}

int ecrire_expr(const void *data, FILE *f) {
  DataExpr* idata = (DataExpr*) data;
  if(idata){
    if (idata->type_noeud == VAR)
    {
      fprintf(f, " %c ", idata->indice_var + 'A');
    }else if(idata->type_noeud == OP){
      fprintf(f, " %c ", idata->operateur);
    }else if (idata->type_noeud == CST){
      fprintf(f, " %f ", idata->constante);
    }else{
      affiche_message("Erreur de valeur.");
    }
  }
  return 1;
}

void * lire_expr(FILE *f) {
  DataExpr *res = (DataExpr*) malloc(sizeof(DataExpr));
  char *buffer = malloc(sizeof(char));
  // float float_buffer;
  if(buffer){
    affiche_message("Erreur d'allocation.");
    return NULL;
  }
  do
  {
    *buffer = fgetc(f);
  } while (isspace(buffer));    
  if (isdigit(buffer)){
    res->type_noeud = CST;
    res->constante = atof(buffer);
  }else if (isupper(buffer)){
    res->type_noeud = VAR;
    res->indice_var = *buffer-'A';
  }else{
    res->type_noeud = OP;
    res->operateur=*buffer;
  }
  return res;
}  

PNoeudBinaire construire_arbre_expr_rec(FILE *f, PArbreBinaire pab) {
  /* a completer. Exercice 5, question 4 */
  PNoeudBinaire pn = malloc(sizeof(NoeudBinaire));
  DataExpr *data = lire_expr(f);
  // a completer un jour 
  if(data->type_noeud == OP){
    pn->gauche = construire_arbre_expr_rec(f, pab);
    pn->data = data;
    pn->droit = construire_arbre_expr_rec(f, pab);
  }else if(data->type_noeud == CST){

  }else if(data->type_noeud == VAR)  {
    /* code */
  }else{
    affiche_message("Erreur de type de noeud.");
  }
  
  
  
  

  return pn; // pour que cela compile
}

PArbreBinaire construire_arbre_expr(FILE *f) {
  /* a completer. Exercice 5, question 4 */
  PArbreBinaire pab = creer_arbre(0 ,dupliquer_expr, copier_expr, detruire_expr, afficher_expr, comparer_expr, ecrire_expr, lire_expr);
  construire_arbre_expr_rec(f, pab);
  pab->copie=1;
  return pab;
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
