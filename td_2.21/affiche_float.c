#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main1();
void main2();
void affichage_tableau_float(float tab[], int len);
float *generate_float(int len, int max, int min);
void affichage_tableau_float_p(float tab[], int len, int p);
void echange_tableau(float *tab, int i, int j);
int *generate_int(int min, int max);
void affichage_tableau_int_p(float tab[], int len);

int main(){
	srand(time(NULL));
	float *tab = generate_float(50, 0, 1000);
	main1();
	main2();
	return 0;
}

void main1(){
	// affichage_tableau_float(tab, 50);
	affichage_tableau_float_p(tab, 50, 5);
	echange_tableau(tab, 0, 49);
	affichage_tableau_float_p(tab, 50, 5);
}

void main2(){
	int *tab = generate_int(1,5,1);
	affichage_tableau_int_p(tab, 5, 1);

	affichage_tableau_int_p(tab, 5, 1);
}

void affichage_tableau_float(float tab[], int len){
	for(int i = 0; i < len; i++){
		printf("%.2f (%d)\n", tab[i], i);
	}
}

void affichage_tableau_float_p(float tab[], int len, int p){
	for(int i = 0; i < len; i++){
		printf("%.2f	(%d)	", tab[i], i);
		if((i+1)%p == 0){
			printf("\n");
		} 
	}
}

void echange_tableau(float *tab, int i, int j){
	int tem;
	tem  = tab[i];
	*(tab+i) =  *(tab + j);
	*(tab + j) = tem;
}

float *generate_float(int len, int min, int max){
	float *tab = malloc(len*sizeof(float));
	for(int i = 0; i < len; i++){
		*(tab + i) = rand()%(max-min+1);
	}
	return tab;
}

int *generate_int(int min, int max, int length){
	int len = (max - min)/length + 1;
	int * tab = malloc(len*sizeof(int));
	for (int i = 0; i < len; i++)
	{
		*tab[i] = min + i*length;
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