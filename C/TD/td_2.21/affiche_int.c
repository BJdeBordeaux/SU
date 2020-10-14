#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *generate_int(int min, int max, int length);
void affichage_tableau_int_p(int tab[], int len, int p);
void main2();

int main(){
	srand(time(NULL));
	main2();
	return 0;
}


void main2(){
	int *tab = generate_int(1,5,1);
	affichage_tableau_int_p(tab, 5, 1);

	affichage_tableau_int_p(tab, 5, 1);
}


int *generate_int(int min, int max, int length){
	int len = (max - min)/length + 1;
	int * tab = malloc(len*sizeof(int));
	for (int i = 0; i < len; i++)
	{
		tab[i] = min + i*length;
	}

	return tab;
}

void affichage_tableau_int_p(int tab[], int len, int p){
	for(int i = 0; i < len; i++){
		printf("%d	(%d)	", tab[i], i);
		if((i+1)%p == 0){
			printf("\n");
		} 
	}	
}