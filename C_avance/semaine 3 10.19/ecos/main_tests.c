#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ecosys.h"


#define NB_PROIES 20
#define NB_PREDATEURS 20
#define ENERGIE 10





int main(void) {

	srand(time(NULL));
	int i;
	int x, y, energie;
	Animal *liste_proie = NULL;
	Animal *liste_predateur = NULL;


	for(i = 0; i < NB_PROIES; i++){
		x = rand()%SIZE_X;
		y = rand()%SIZE_Y;
		energie = ENERGIE;
		// energie = rand()%10;
		liste_proie = ajouter_en_tete_animal(liste_proie,  creer_animal(x, y, energie));
	}

	// for(i = 0; i < NB_PREDATEURS; i++){
	// 	x = rand()%SIZE_X;
	// 	y = rand()%SIZE_Y;
	// 	energie = rand()%10;
	// 	liste_predateur = ajouter_en_tete_animal(liste_predateur, creer_animal(x, y, energie));
	// }
	
	/* COMENT ZONES ARE FOR TESTING FUNCTION enlever_animal;
	 * void enlever_animal(Animal **liste, Animal *animal)
	 * NO NEED TO UNCOMENT THIS BLOC
	 */



	for(i = 0; i < NB_PREDATEURS/2; i++){
		x = rand()%SIZE_X;
		y = rand()%SIZE_Y;
		energie = rand()%10;
		liste_predateur = ajouter_en_tete_animal(liste_predateur, creer_animal(x, y, energie));
	}

	Animal *ani = creer_animal(5,5,5);
	liste_predateur = ajouter_en_tete_animal(liste_predateur, ani);

	for(i = 0; i < NB_PREDATEURS/2; i++){
		x = rand()%SIZE_X;
		y = rand()%SIZE_Y;
		energie = rand()%10;
		liste_predateur = ajouter_en_tete_animal(liste_predateur, creer_animal(x, y, energie));
	}

	int npo = compte_animal_it(liste_proie);
	int npd = compte_animal_it(liste_predateur);
	afficher_ecosys(liste_proie, liste_predateur);
	printf("proies, predateurs: %d, %d\n",npo,npd );

	enlever_animal(&liste_predateur, ani);
	npo = compte_animal_it(liste_proie);
	npd = compte_animal_it(liste_predateur);
	afficher_ecosys(liste_proie, liste_predateur);
	printf("proies, predateurs: %d, %d\n",npo,npd );

	liberer_liste_animaux(liste_predateur);
	liberer_liste_animaux(liste_proie);

  	return 0;
}
