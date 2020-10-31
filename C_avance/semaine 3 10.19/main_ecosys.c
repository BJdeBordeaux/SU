#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <strings.h>
#include "ecosys.h"



#define NB_PROIES 20
#define NB_PREDATEURS 20
#define T_WAIT 40000
#define ENERGIE 20


/* Parametres globaux de l'ecosysteme (externes dans le ecosys.h)*/



int main(void) {

	srand(time(NULL));

	// Animal* aa = creer_animal(0,0,10);
	// afficher_ecosys(aa, NULL);
	// reproduce(&aa, 1);
	// bouger_animaux(aa);
	// afficher_ecosys(NULL, NULL);
	
	int monde[SIZE_X][SIZE_Y];
	int i, j;
	for(i = 0; i < SIZE_X; i++){
		for(j = 0; j < SIZE_Y; j++){
			monde[i][j] = 0;
		}
	}

	int x, y;
	float energie;
	Animal *liste_proie;
	for(i = 0; i < NB_PROIES; i++){
		x = rand()%SIZE_X;
		y = rand()%SIZE_Y;
		energie = ENERGIE;
		liste_proie = ajouter_en_tete_animal(liste_proie,  creer_animal(x, y, energie));
	}

	Animal *liste_predateurs;
	for(i = 0; i < NB_PREDATEURS; i++){
		x = rand()%SIZE_X;
		y = rand()%SIZE_Y;
		energie = ENERGIE;
		liste_predateurs = ajouter_en_tete_animal(liste_predateurs,  creer_animal(x, y, energie));
	}

	i = 0;
	FILE *f = fopen("Evol_Pop.txt", "w");
	while(i<200 && (liste_proie != NULL)){
		afficher_ecosys(liste_proie, liste_predateurs);
		rafraichir_proies(&liste_proie, monde);
		rafraichir_predateurs(&liste_predateurs, &liste_proie);
		// reproduce(&liste_proie, p_reproduce_proie);
		// reproduce(&liste_predateurs, p_reproduce_predateur);
		rafraichir_monde(monde);
		// usleep(T_WAIT);
		fprintf(f, "%d %d %d\n", i, compte_animal_it(liste_proie), compte_animal_it(liste_predateurs));
		i++;
		
		
		
	}
	fclose(f);

	int npo = compte_animal_it(liste_proie);
	int npd = compte_animal_it(liste_predateurs);
	printf("proies, predateurs: %d, %d\n",npo,npd );

	liberer_liste_animaux(liste_proie);
	liberer_liste_animaux(liste_predateurs);

  return 0;
}

