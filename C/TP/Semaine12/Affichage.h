#ifndef AFFICHAGE
#define AFFICHAGE
#include  "Othello.h"

void Afficher_plateau_text(int plateau[H][H]);

void Creer_fenetre(char *ModeStr);
void Detruire_fenetre();

int Loop_until_play(int plateau[H][H], int *pi, int *pj, int joueurCourant);
#endif
