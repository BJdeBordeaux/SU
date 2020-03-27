#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAILLE 4
#define TIRAGE 10000
int pct[]={17, 28, 50, 5};

int *calcul_borne_sup(int *tab, int len){
    int *res = malloc(len*sizeof(int));
    res[0] = tab[0]-1;
    for(int i = 1; i < len; i++)
    {
        res[i] = res[i-1]+tab[i];
    }
    return res;
}

int tire_non_equi(int *tab_de_borne, int len){
    
    int somme = tab_de_borne[len-1]+1;
    int x = rand() % somme;
    for(int i = 0; i < len; i++)
    {
        if(x<=tab_de_borne[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    srand(time(NULL));
    int *tab = calcul_borne_sup(pct, TAILLE);

    int res[TAILLE];
    for (int i = 0; i < TAILLE; i++)
    {
        res[i] = 0;
    }
    
    for(int i = 0; i < TIRAGE; i++)
    {
        int x = tire_non_equi(tab, TAILLE);
        res[tire_non_equi(tab, TAILLE)]++;
    }
    
    for(int j = 0; j < TAILLE; j++)
    {
        printf("j, res[j]: %d, %d\n", j, res[j]);
    }

    return 0;
}

//il reste question 4