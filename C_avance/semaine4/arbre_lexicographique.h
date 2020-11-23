#ifndef _ARBRE_LEXICOGRAPHIQUE_H_
#define _ARBRE_LEXICOGRAPHIQUE_H_

#include "commun.h"

typedef struct noeud *PNoeud;
typedef struct noeud {
  char lettre;
  FDM fin_de_mot;
  PNoeud fils;
  PNoeud frere_suivant;
} Noeud;

PNoeud creer_noeud(char lettre);
void inserer_lettre(PNoeud *racine, PNoeud *n_lettre, char lettre);
PNoeud ajouter_mot(PNoeud racine, char *mot);
void afficher_mots(PNoeud n, char mot_en_cours[], int index);
void afficher_dico(PNoeud racine);
void detruire_dico(PNoeud dico);
int rechercher_mot(PNoeud dico, char *mot);

PNoeud lire_dico(const char *nom_fichier);

#endif
