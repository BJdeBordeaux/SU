#include <stdlib.h>
#include <stdio.h>
#include "arbre_lexicographique_tab.h"

int main(int argc, char **argv) {
	PNoeudTab alex=lire_dico("french_za");
	char *mot1 = "abcde";
	char *mot2 = "marin";
	int i;
	int pm1;
	int pm2;
	int nbr;
	
	if (argc != 2)
		{
		fprintf(stderr, "Usage : main_arbre_tab nb_recherches\n");
		exit(1);
		}
	
	nbr = atoi(argv[1]);

	printf("-------- Arbre Lexico construit --------\n");

	for (i=0;i<nbr;i++) {
		pm1 = rechercher_mot(alex,mot1);
		pm2 = rechercher_mot(alex,mot2);
	}
	if ((pm1 == 0) && (pm2!= 1))
	 	printf("Resultat recherche OK!\n");
	else
	 	printf("Resultat eronne KO!\n");

	detruire_dico(alex);
	printf("n=%d",nbr);
	return 0;
}
/*pour 1 millions d'appels
		real	0m0,010s
		user	0m0,008s
		sys	0m0,000s
*/
