#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Othello.h"


int Autre_joueur(int joueur)
{
 	if(NOIR){return BLANC;}
 	else{return NOIR;}
}

/*Le plateau est numéroté à partor de 0,0 qui représente la case en haut à gauche*/

void Initialiser_plateau(int plateau[H][H])
{
	int tf = 0;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < H; j++){
			tf = (i == 3 || i == 4) && (j == 3 || j == 4);
			if(!tf){
				plateau[i][j] = 0;
			}
		}
	}
}


//Compter et renvoyer le nombre de pions qui seront retournés pour une direction donnée
int Gain_dir(int plateau[H][H], int iLigne, int iCol, int dirLigne, int dirCol, int couleurQuiJoue)
{
	 	/* A COMPLETER */
	return 0;
}

//Compter et renvoyer le nombre de pions qui seront retournés dans les 8 directions
int Est_jouable_gain(int plateau[H][H], int iLigne, int iCol, int couleurQuiJoue)
{
	int nbPionsGagnes = 0;
 	/* A COMPLETER */
	return nbPionsGagnes;
}

//Renvoie la liste des position jouables, associée chacune avec le gain (nb de pions retournés)
cellule_t *Trouver_liste_pos_jouables(int plateau[H][H], int couleurQuiJoue)
{

	cellule_t *listePos=NULL; 	
	/* A COMPLETER */
	return listePos;

}

//Retourner les pions dans une direction donnée

void Retourner_pions(int plateau[H][H], int iLigne, int iCol, int dirLigne, int dirCol, int couleurQuiJoue)
{
 	/* A COMPLETER */

}

void Jouer_pion(int plateau[H][H], int iLigne, int iCol, int couleurQuiJoue)
{
 	/* A COMPLETER */

}

void Nb_pions(int plateau[H][H], int *NbN, int *NbB)
{
 	/* A COMPLETER */
}

void Joueur_Auto_2(int plateau[H][H], int *pi, int*pj,cellule_t *listeJouable)
{
	 	/* A COMPLETER */
}

/* Il faudra ajouter Nb_pions */



