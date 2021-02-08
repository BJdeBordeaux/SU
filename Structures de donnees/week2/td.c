#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// exo1
int **allouerMatrice(int n, int m){
    int** res = (int**) malloc(sizeof(int*)*n);
    if(!res){
        return NULL;
    }
    for (int i = 0; i < n; i++){
        res[i] = (int*) malloc(sizeof(int)*m);
        if(!res[i]){
            for (int k = 0; k < i; k++){
                free(res[k]);
            }
            return NULL;
        }
        memset(res[i], 0, sizeof(int)*m);
    }
    return res;
}

int allouerMatrice2(int ***matrice, int n, int m){
    int** res = (int**) malloc(sizeof(int*)*n);
    if(!res){
        return 0;
    }
    for (int i = 0; i < n; i++){
        res[i] = (int*) malloc(sizeof(int)*m);
        if(!res[i]){
            for (int k = 0; k < i; k++){
                free(res[k]);
            }
            return 0;
        }
        memset(res[i], 0, sizeof(int)*m);
    }
    *matrice = res;
    return 1;
}

// exo2
typedef struct _matT{
    int **matrice;
    int taille;
    int orientation; // 1: sup; 0: inf
} matT;

int alloue_matrice_tri(int *** T, int n){
    int **res = (int **) malloc(sizeof(int*)*n);
    if(!res){
        return 0;
    }    
    for(int i = 0 ; i< n; i++ ){
         res[i]= (int *)malloc(sizeof(int)*(i+1));
         if(!res[i]){
            for (int k = 0; k < i; k++){
                free(res[k]);
            }
            return 0;
         }
    }
    *T = res;
    return 1;
}

matT *allouerMatriceT(int taille, int orientation){
    // à faire
    return NULL;
}

// exo3
typedef struct _personne{
    char* nom;
    long tel;
} Personne;

typedef struct _repertoire{
    Personne* tab;
    int taill;
} Repertoire;

void ecrirePersonnes(char *nomFichier, Repertoire* r){
    FILE* f = fopen(nomFichier,"a");
    if(!f){
        printf("Not able to open the file.\n");
        exit(1);
    }
    // Personne p;
    // for (int i = 0; i < r->taill; i++){   
    //     // p = (r->tab)[i];
    //     fprintf(f, "%s:%ld\n", (r->tab)[i].nom, (r->tab)[i].tel);
        
    // }
    Personne* p = r->tab;
    for (int i = 0; i < r->taill; i++)
    {
        fprintf(f, "%s:%ld\n", p->nom, p->tel);
        p++;
    }
    fclose(f);
}

Repertoire* lirePersonnes(char *nomFichier, Repertoire* r){
    FILE* f = fopen(nomFichier,"r");
    if(!f){
        printf("Not able to open the file.\n");
        exit(1);
    }
    
    Repertoire* res = malloc(sizeof(Repertoire));
    if(!res){
        fclose(f);
        printf("Erreur d'allocation.\n");
        exit(1);
    }

    Personne* p = NULL;
    int taille = 0;
    int lenMax = 256;
    char buffer[lenMax];
    while(fgets(buffer, lenMax, f)){
        taille++;
    }
    r->taill = taille;
    rewind(f);
    Personne *tab = (Personne*) malloc(sizeof(Personne)*taille);
    if(!tab){
        free(res);
        fclose(f);
        printf("Erreur d'allocation.\n");
        exit(1);
    }

    for (int i = 0; i < taille && fgets(buffer, lenMax, f); i++){;
        sscanf(buffer, "%s:%ld", tab[i].nom, &(tab[i].tel));
    }
    r->tab = tab;

    fclose(f);
    return r;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
