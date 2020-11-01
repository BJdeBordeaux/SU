#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM1 5
#define DIM2 6
#define PP printf("here\n")

void InitTab(char tab[DIM1][DIM2]){
	int i, j;
	for(i = 0; i < DIM1; i++){
		for(j = 0; j < DIM2; j++){
			tab[i][j] = '0';
		}
	}
}

void InitTab2(char *tab){
	int i, j;
	for(i = 0; i < DIM1; i++){
		for(j = 0; j < DIM2; j++){
			*((tab+i)+j) = '0';
		}
	}
}

void print_char_table(char t[DIM1][DIM2]){
    int i, j;
    for(i = 0; i < DIM1; i++){
        for(j = 0; j < DIM2; j++){
        	printf("%c  ",t[i][j]);	
        } 
        printf("\n");
    }
    printf("\n");
}

void print_char_table2(char *t){
    int i, j;
    for(i = 0; i < DIM1; i++){
        for(j = 0; j < DIM2; j++){
        	printf("%c  ",*((t+i)+j));
        }
        printf("\n");
    }
    printf("\n");
}

typedef struct _ty_etu{
	int id_etu;
	char nom[200], prenom[200];
	int nb_ue;
	char codes_ue[9][20];
	int notes[20];
}ty_etu;

ty_etu *lecture_ascii_etu(char *fichier, int *nb_etu){
	int i;
	ty_etu* tab_etu;
	FILE *f;
	
	f = fopen(fichier, "r");
	if(f == NULL){
		printf("Impossible de lire le fichier %s\n", fichier);
		return NULL;
	}
	
	if(fscanf(f, "%d", nb_etu) != 1){
		printf("Erreur en lecture de nombre d'étudiant\n");
		fclose(f);
		return NULL;
	}

	tab_etu = (ty_etu*) malloc(*nb_etu*sizeof(ty_etu));
	
	int j;
	for(i = 0; i < *nb_etu; i++){
		fscanf(f, " %d %s %s %d", &(tab_etu[i].id_etu), tab_etu[i].nom, tab_etu[i].prenom, &(tab_etu[i].nb_ue));
		for(j = 0; j < tab_etu[i].nb_ue; j++){
			fscanf(f, " %s %d", tab_etu[i].codes_ue[j], &(tab_etu[i].notes[j]));
		}
	}
	return tab_etu;
	
}

int main(void){
	
	// ex1
	char tab2D[DIM1][DIM2];
	char* tab2D2 = (char*) malloc(sizeof(char)*DIM1*DIM2);
	InitTab2(tab2D2);
	print_char_table2(tab2D2);


	// ex3
	int nb_etu;
	ty_etu* tab_etu = lecture_ascii_etu("etu.txt", &nb_etu);
	printf("nb etu : %d\n", nb_etu);
	printf("id, nom, prenom, nb_ue, ue1 et notes:\n%d %s %s %d %s %d\n",
		tab_etu[0].id_etu, tab_etu[0].nom, tab_etu[0].prenom, tab_etu[0].nb_ue, 
		tab_etu[0].codes_ue[0], tab_etu[0].notes[0]);

	return 0;
}