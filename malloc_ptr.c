#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define MAX 100

int Chercher_val(int * tab, int len, int val);
int Chercher_val2(int * tab, int len, int val);
int *tab_carre(int t[], int len);
int *Ita(int len);
int *Ita2(int len);
void print_value(int *t, int len);
int Indice_ValMax(int tab[], int taille);
void Trier_Tab_SelMax(int tab[], int taille);


int main(){
	// int *ptr = malloc(5*sizeof(int));
	// for(int i = 0; i < 5; i++){
	// 	ptr[i] = i;
	// }

	// int *tab2 = tab_carre(ptr, 5);
	// printf("%d, %d\n", ptr[4], tab2[4]);
	
	srand(time(NULL));
	int len;
	printf("Please enter a length of the array.\n");
	scanf("%d",&len);
	int *ita = Ita2(len);

	print_value(ita, len);

	free(ita);
	// print_value(ita, len);
	return 0;
}


// int main1(){

// }

int *tab_carre(int t[], int len){
	int *r =malloc(len * sizeof(int));
	for(int i = 0; i < len; i++){
		r[i] = t[i] * t[i];
	}
	return r;
}


int *Ita(int len){

	int *res = malloc(len*sizeof(int));

	for(int i = 0; i < len; i++){
		int val;
		do{
			val = rand() % MAX;
		} while (Chercher_val(res, i, val));
		res[i] = val;
	}

	return res; 
}

int *Ita2(int len){

	int *res = malloc(len*sizeof(int));
	int *dejatire = malloc(len*sizeof(int));
	for(int i = 0; i < len; i++){
		dejatire[i] = 0;
	}

	for(int i = 0; i < len; i++){
		int val;
		do{
			val = rand() % MAX;
		} while (dejatire[val]);
		res[i] = val;
		dejatire[val] = 1;
	}

	return res; 
}

int *Ita3(int len){

	int *res = malloc(len*sizeof(int));

	for(int i = 0; i < len; i++){
		int val;
		do{
			val = rand() % MAX;
		} while (Chercher_val2);
		res[i] = val;
		dejatire[val] = 1;
	}

	return res; 
}

void print_value(int *t, int len){
	for(int i = 0; i < len; i++){
			printf("%d  (%d)\n",t[i], i);
	}
}

int Chercher_val(int * tab, int len, int val){
	int i;
	for(i = 0; i < len; i++){
		if(tab[i]==val){
			return 1;
		}
	}
	return 0;
}

int Chercher_val2(int * tab, int len, int val){
	if(len == 0){
		return 0;
	}
	if(len == 1){
		return (*tab == val)? 1:0;
	}

	if(tab[len/2] < val){
		return Chercher_val2(tab, len/2, val);
	}
	return Chercher_val2(tab+len/2, len/2, val);
}

int Indice_ValMax(int tab[], int taille)
	{
	int i;
	int imax=0;

	for(i=1; i<taille; i++)
		if (tab[i] > tab[imax])
			imax = i;

	return imax;
	}

void Trier_Tab_SelMax(int tab[], int taille)
	{
	while (taille > 1)
		{
		int tmp = tab[taille - 1];
		int imax = Indice_ValMax(tab, taille);
		tab [taille - 1] = tab[imax];
		tab[imax] = tmp;
		taille--;
		}
	}