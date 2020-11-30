#ifndef _ARBRE_EXPR_H_
#define _ARBRE_EXPR_H_

#include "arbre_binaire.h"

typedef enum _type_noeud {VAR, CST, OP} TypeNoeud;

typedef struct _dataExpr
{
  TypeNoeud type_noeud;
  unsigned int indice_var; 
  char operateur;
  float constante;
} DataExpr;

void *dupliquer_expr(const void *src);
void copier_expr(const void *src, void *dst);
void detruire_expr(void *data);
void afficher_expr(const void *data);
int comparer_expr(const void *a, const void *b);
int ecrire_expr(const void *data, FILE *f);
void * lire_expr(FILE *);

PNoeudBinaire construire_arbre_expr_rec(FILE *f, PArbreBinaire pab);
PArbreBinaire construire_arbre_expr(FILE *f);

void demander_variables(PArbreBinaire pabe, float var_lue[]);

float evaluer(PNoeudBinaire pabe, float var_lue[]);



#endif
