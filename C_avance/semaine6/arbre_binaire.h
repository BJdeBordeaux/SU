#ifndef _API_ARBRE_BINAIRE_H_
#define _API_ARBRE_BINAIRE_H_

#include <stdio.h>

typedef struct _noeud_binaire *PNoeudBinaire;
typedef struct _noeud_binaire {
  void *data;
  PNoeudBinaire gauche;
  PNoeudBinaire droit;
} NoeudBinaire;

typedef struct _arbre_binaire *PArbreBinaire;
typedef struct _arbre_binaire {
  char copie;
  PNoeudBinaire racine;
  void *(*dupliquer)(const void *src);
  void (*copier)(const void *src, void *dst);
  void (*detruire)(void *data);
  void (*afficher)(const void *data);
  int (*comparer)(const void *a, const void *b);
  int (*ecrire)(const void *data, FILE *f);
  void *(*lire)(FILE *f);
} ArbreBinaire;

// creer un arbre vide
PArbreBinaire creer_arbre(char copie,
			  void *(*dupliquer)(const void *src),
			  void (*copier)(const void *src, void *dst),
			  void (*detruire)(void *data),
			  void (*afficher)(const void *data),
			  int (*comparer)(const void *a, const void *b),
			  int (*ecrire)(const void *data, FILE *f),
			  void *(*lire)(FILE *f)
			  );

// creer un noeud
PNoeudBinaire creer_noeud_binaire(PArbreBinaire pab, void *data);

// detruire arbre binaire
void detruire_ab(PArbreBinaire pab);

// affichage prefixe
void afficher_ab_prefixe(PArbreBinaire pab);

// affichage infixe
void afficher_ab_infixe(PArbreBinaire pab);

// affichage postfixe
void afficher_ab_postfixe(PArbreBinaire pab);

// appliquer une fonction a tous les elements d'une liste, parcours prefixe
void map_ab_prefixe(PArbreBinaire pab, void (*fonction)(void *data, void *oa), void *optarg);

// appliquer une fonction a tous les elements d'une liste, parcours infixe
void map_ab_infixe(PArbreBinaire pab, void (*fonction)(void *data, void *oa), void *optarg);

// appliquer une fonction a tous les elements d'une liste, parcours postfixe
void map_ab_postfixe(PArbreBinaire pab, void (*fonction)(void *data, void *oa), void *optarg);

/* Arbres binaires de recherche */

// ajouter dans un arbre binaire de recherche
void ajouter_abr(PArbreBinaire pab,void *data);

// chercher dans un arbre binaire de recherche
PNoeudBinaire chercher_abr(PArbreBinaire pab, void *data);

// affichage prefixe avec map
void afficher_ab_prefixe_map(PArbreBinaire pab);

// affichage infixe avec map
void afficher_ab_infixe_map(PArbreBinaire pab);
  
// affichage postfixe avec map
void afficher_ab_postfixe_map(PArbreBinaire pab);

// Lire un arbre binaire depuis un fichier. Un arbre vide doit etre fourni pour pouvoir recuperer la fonction de lecture d'un element.
void lire_abr(PArbreBinaire pab, const char *nom_fichier);

// Ecriture de l'arbre
void ecrire_ab(PArbreBinaire pab, const char *nom_fichier);

// Ecriture de l'arbre avec map
void ecrire_ab_map(PArbreBinaire pab, const char *nom_fichier);

// Ecriture de l'arbre avec map (infixe)
void ecrire_ab_map_infixe(PArbreBinaire pab, const char *nom_fichier);

// Ecriture de l'arbre avec map (postfixe)
void ecrire_ab_map_postfixe(PArbreBinaire pab, const char *nom_fichier);

// Fonction de destruction d'un noeud binaire
void detruire_noeud_binaire(PNoeudBinaire pnb, PArbreBinaire pab);

// Fonction recurrente de lecture
void ecrire_ab_rec(PNoeudBinaire pnb, PArbreBinaire pab, FILE *f);

#endif
