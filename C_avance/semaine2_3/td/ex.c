#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define DIM1 5
#define DIM2 6
#define PP printf("here\n")

void InitTab(char tab[][DIM2]){
	int i, j;
	for(i = 0; i < DIM1; i++){
		for(j = 0; j < DIM2; j++){
			tab[i][j] = '0';
		}
	}
}

void InitTab2(char **tab, int nba, int nbb){
	int i, j;
	for(i = 0; i < nba; i++){
		for(j = 0; j < nbb; j++){
			tab[i][j] = 0;
		}
	}
}

void print_char_table(char t[][DIM2]){
    int i, j;
    for(i = 0; i < DIM1; i++){
        for(j = 0; j < DIM2; j++){
        	printf("%c  ",t[i][j]);	
        } 
        printf("\n");
    }
    printf("\n");
}

void print_char_table2(char **t){
    int i, j;
    for(i = 0; i < DIM1; i++){
        for(j = 0; j < DIM2; j++){
        	printf("\t%d",t[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
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
	
	int verif = fscanf(f, "%d", nb_etu);
	if(verif != 1){
		printf("Erreur en lecture de nombre d'étudiant\n");
		fclose(f);
		return NULL;
	}

	// // or this version from corrige
	// int verif;
	// verif = fscanf(f, " %d", nb_etu);
	// assert(verif == 1);

	tab_etu = (ty_etu*) malloc(*nb_etu*sizeof(ty_etu));
	assert(tab_etu);
	
	int j;
	for(i = 0; i < *nb_etu; i++){
		fscanf(f, " %d %s %s %d", &(tab_etu[i].id_etu), tab_etu[i].nom, tab_etu[i].prenom, &(tab_etu[i].nb_ue));
		for(j = 0; j < tab_etu[i].nb_ue; j++){
			fscanf(f, " %s %d", tab_etu[i].codes_ue[j], &(tab_etu[i].notes[j]));
		}
	}
	return tab_etu;
	
}

void ecriture_binaire_etu(char *nomFi, ty_etu *tEtu, int nb_etu){
	FILE *f;

	f = fopen(nomFi, "w");
	if(f == NULL){
		fprintf(stderr, "Impossible d'ouvrir le fichier %s\n", nomFi);
		return ;
	}

	fwrite(&nb_etu, sizeof(int), 1, f);
	fwrite(tEtu, sizeof(ty_etu), nb_etu, f);

	fclose(f);
	return ;
}

ty_etu* lecture_binaire_etu(char *nomFi, int *nb_etu){

	FILE *f;
	int i;
	
	f = fopen(nomFi, "r");
	if(f == NULL){
		printf("Impossible d'ouvrir le fichier %s\n", nomFi);
		exit(1);
	}

	fread(nb_etu, sizeof(int), 1, f);
	ty_etu *tab = malloc(*nb_etu*sizeof(ty_etu));
	assert(tab);
	fread(tab, sizeof(ty_etu), *nb_etu, f);

	fclose(f);
	return tab;

}



int main(void){
	
	// ex1
	char tab2D[DIM1][DIM2];
	char** tab2D2 = malloc(sizeof(char*)*DIM1);
	int i;
	for(i = 0; i < DIM1; i++){
		tab2D2[i] = malloc(sizeof(char)*DIM2);
	}
	InitTab2(tab2D2,DIM1,DIM2);
	print_char_table2(tab2D2);
	
	for(i = 0; i < DIM1; i++){
		free(tab2D2[i]);
	}
	free(tab2D2);

	// ex3
	int nb_etu;
	ty_etu* tab_etu = lecture_ascii_etu("etu.txt", &nb_etu);
	// printf("nb etu : %d\n", nb_etu);
	// printf("id, nom, prenom, nb_ue, ue1 et notes:\n%d %s %s %d %s %d\n",
	// 	tab_etu[0].id_etu, tab_etu[0].nom, tab_etu[0].prenom, tab_etu[0].nb_ue, 
	// 	tab_etu[0].codes_ue[0], tab_etu[0].notes[0]);

	ecriture_binaire_etu("etu_binaire.txt", tab_etu, nb_etu);
	
	int j;
	ty_etu* tab_etu2 = lecture_binaire_etu("etu_binaire.txt", &nb_etu);
	printf("nb etu : %d\n", nb_etu);
	printf("id, nom, prenom, nb_ue, code ue et notes :\n");
	for(i = 0; i < nb_etu; i++){
		printf("%d %s %s %d",
		tab_etu[i].id_etu, tab_etu[i].nom, tab_etu[i].prenom, tab_etu[i].nb_ue);
		for(j = 0; j < tab_etu[i].nb_ue; j++){
			printf("%s %d ", tab_etu[i].codes_ue[j], tab_etu[i].notes[j]);
		}
		printf("\n");
	}
	
	return 0;
}