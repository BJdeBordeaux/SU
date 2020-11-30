#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(int argc, char **argv)
{
	Lm_mot *p=lire_dico_Lmot("french_za");
	Lm_mot *fatou=chercher_Lm_mot(p,"Fatou");
	Lm_mot *marin=chercher_Lm_mot(p,"marin");
	if ( fatou != NULL)
		printf("Le mot Fatou est dans le dictionnaire ! \n");
	printf("Le mot Fatou n'est pas dans le dictionnaire ! \n");	
	
	if ( marin != NULL)
		printf("Le mot marin est dans le dictionnaire ! \n");
	printf("Le mot marin n'est pas dans le dictionnaire ! \n");		
	

	int n =atoi(argv[1]);
	for (int i=0; i< n;i++){
	Lm_mot *meuble=chercher_Lm_mot(p,"meuble");
	}
	printf("%d \n",argc);
	printf("%d \n",n);
  return 0;
}

/*pour 100 appels real	0m0,070s
                   user	0m0,064s
                    sys	0m0,004s


*pour 1000 appels
		real	0m4,332s
		user	0m4,320s
		sys	0m0,008s


*pour 10000 appels

		real	0m0,468s
		user	0m0,468s
		sys	0m0,000s


*pour 1 millions d'appels 
		real	7m12,739s
		user	7m12,728s
		sys	0m0,000s
*/

