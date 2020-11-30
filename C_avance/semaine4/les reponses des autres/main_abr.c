#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "abr.h"

int main(int argc, char **argv)
{
  	Lm_mot *p=lire_dico_Lmot("french_za");
	Nd_mot *a = Lm2abr(p);
	
	char* mot = argv[1];
	if(chercher_Nd_mot(a, mot))	
	printf("Le mot  est dans le dictionnaire ! \n");
	else printf("Le mot  n'est pas dans le dictionnaire ! \n");
 
	
	int n =atoi(argv[2]);
	int i=0;
	for (i=0; i< n;i++){
	chercher_Nd_mot(a, "marin");
	}
		
	printf("%d \n",argc);
	printf("%d \n",n);



  return 0;
}


/*pour 1 millions d'appels 
		real	0m0,148s
		user	0m0,148s
		sys	0m0,000s
*/
