#ifndef _OTHELLO_H_
#define _OTHELLO_H_ 
#include "ListePos.h"

#define H 8 //Taille du plateau

#define VIDE 0
#define NOIR 1
#define BLANC 2

int Autre_joueur(int joueur);
void Initialiser_plateau(int plateau[H][H]);


cellule_t *Trouver_liste_pos_jouables(int plateau[H][H], int couleurQuiJoue);
void Jouer_pion(int plateau[H][H], int iLigne, int iCol, int couleurQuiJoue);

void Joueur_Auto_2(int plateau[H][H], int *pi, int*pj,cellule_t *listeJouable);

/* Il faudra ajouter Nb_pions */

#endif
