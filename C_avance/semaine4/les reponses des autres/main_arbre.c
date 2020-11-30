#include <stdio.h>
#include "arbre_lexicographique.h"

int main(int argc, char **argv) {
  PNoeud l=lire_dico("french_za");
  char mot1[]="abcde";
  char mot2[]="marin";
  int i;

  int n =atoi(argv[1]);
 
    if(rechercher_mot(l,mot1)) 
        printf("Le mot est dans le dictionnaire ! \n");
    else 
        printf("Le mot  n'est pas dans le dictionnaire ! \n");
  
     if(rechercher_mot(l,mot2)) 
        printf("Le mot est dans le dictionnaire ! \n");
    else 
        printf("Le mot  n'est pas dans le dictionnaire ! \n");

  for (i=0;i<n;i++) {rechercher_mot(l,mot2);}

	
	printf("%d \n",argc);
	printf("%d \n",n);
  return 0;

}

/*pour 1 millions d'appels 
			real	0m0,204s
			user	0m0,200s
			sys	0m0,000s

*/

