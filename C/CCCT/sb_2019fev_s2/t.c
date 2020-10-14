#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NB_LG  8
#define NB_COL 7


void print_int_table(int *t, int len){
    int i;
    for(i = 0; i < len; i++){
        if(i%10 == 0){printf("\n");}
        printf("(%d)  ",t[i]);
    }
    printf("\n");
}

void print_int_table_2d(int t[NB_LG][NB_COL], int l1, int l2){
    int i, j;
    for(i = 0; i < l1; i++){
        for(j = 0; j < l2; j++){
        	printf("(%d)  ",t[i][j]);	
        }
        printf("\n");
    }
    printf("\n");
}

int *somCumulee(int t[], int n){
	int *res = malloc(sizeof(int)*n);
	int s = 0;
	int i;
	for(i = 0; i < n; i++){
		s += t[i];
		res[i] = s;
	}
	return res;
}

int tirerSelonScore(int t[], int n){
	int *tCumul = somCumulee(t, n);
	int a = rand()%(tCumul[n-1]);
	int i;
	for(i = 0; i < n; i++){
		if(tCumul[i] > a){
			return i;
		}
	}
}

void initMonde(int monde[NB_LG][NB_COL]){
	int i, j;
	for(i = 0; i < NB_LG; i++){
		for(j = 0; j < NB_COL; j++){
			if((i == 0) || (j == 0) || (i == NB_LG-1) || (j == NB_COL-1)){
				monde[i][j] = 0;
			}else{
				monde[i][j] = 1;
			}
		}
	}
}

typedef struct _tyFourmi{
	int i; // coordonnee i (ligne) de la fourmi
	int j; // coordonnee j (colonne) de la fourmi
	char sens; //sens du trajet (’A’ pour aller ou ’R’ pour retour)
	int energie; //energie de la fourmi
	struct _tyFourmi *suiv; //pointeur vers la fourmi suivante
} tyFourmi;

#define MAX_E 10

// q4
tyFourmi *insererEnTete(tyFourmi *listeFourmis){
	tyFourmi *res = malloc(sizeof(tyFourmi));
	res->i = 1;
	res->j = 1;
	res->sens = 'A';
	res->energie = rand()%(MAX_E + 1);
	res->suiv = listeFourmis;
	return res;
}

void copiePheromone(int monde[NB_LG][NB_COL], tyFourmi fourmi, int tDir[]){
	int i = fourmi.i;
	int j = fourmi.j;
	// tDir[0] = monde[i-1];
	tDir[0] = monde[i-1][j];
	// tDir[1] = monde[j-1];
	tDir[1] = monde[i][j-1];
	
	if(fourmi.sens == 'R'){
		tDir[2] = 0;
		tDir[3] = 0;
	}else{
		// tDir[2] = monde[i+1];
		tDir[2] = monde[i+1][j];
		// tDir[3] = monde[j+1];
		tDir[3] = monde[i][j+1];
	}
}

void bougerUneFourmi(tyFourmi *unefourmi, int monde[NB_LG][NB_COL]){
	// int tDir[4] = copiePheromone(monde);
	int tDir[4];
	copiePheromone(monde, unefourmi, tDir);
	int s = tirerSelonScore(tDir);
	if(s == 0){
		unefourmi->i -= 1;
	}else if(s == 1){
		unefourmi->j -= 1;
	}else if(s == 2){
		unefourmi->i += 1;
	}else{
		unefourmi->j +=1;
	}
}


int main(){
	srand(time(NULL));
	int t[4] = {1, 2, 0, 3};
	// int *t2 = somCumulee(t, 4);
	// print_int_table(t2, 4);
	// printf("%d\n", tirerSelonScore(t, 4));
	int monde[NB_LG][NB_COL];
	initMonde(monde);
	print_int_table_2d(monde, NB_LG, NB_COL);
	return 0;
}