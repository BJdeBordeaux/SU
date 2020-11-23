#ifndef _ARBRE_LEXICOGRAPHIQUE_TAB_H_
#define _ARBRE_LEXICOGRAPHIQUE_TAB_H_

#include "commun.h"

typedef struct noeudTab *PNoeudTab;
typedef struct noeudTab {
  char lettre;
  FDM fin_de_mot;
  PNoeudTab fils[26];
} NoeudTab;

PNoeudTab creer_noeud(char lettre);
PNoeudTab ajouter_mot(PNoeudTab racine, char *mot);
void afficher_mots(PNoeudTab n, char mot_en_cours[LONGUEUR_MAX_MOT], int index);
void afficher_dico(PNoeudTab racine);
void detruire_dico(PNoeudTab dico);
int rechercher_mot(PNoeudTab dico, char *mot);

PNoeudTab lire_dico(const char *nom_fichier);

#endif
