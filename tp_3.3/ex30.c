#include<stdio.h>
#include<stdlib.h>
#define TAILLE 10

int *init(int taille){
    int *res = malloc(taille*(sizeof(int)));
    int i;
    for (i = 0; i < taille-1; i++)
    {
        res[i] = rand()%2;
    }
    res[i]=-1;
    return res;
}

void affiche_tableau(int *tab, int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d   ",tab[i]);
        if((i+1)%5==0){
            printf("\n");
        }
    }
    
}

int compress_tab(int tab_brut[], int *tab_compresse){
    int b = 0;
    int c = 0;
    int cpt = 1;
    while(tab_brut[b]!=-1){
        if(tab_brut[b]==tab_brut[b+1]){
            cpt++;
            b++;
        }
        else{
            if(cpt>1){
                *(tab_compresse+c)=cpt;
                *(tab_compresse+c+1)=tab_brut[b];
                cpt = 1;
                c += 2;
                b++;
            }else{
                *(tab_compresse+c)=tab_brut[b];
                c ++;
                b++;
            }
        }
    }
    tab_compresse[c]=-1;
    return c+1;
}

int decomporess_tab(int tab_compress[], int *tab_decompress){
    int c = 0;
    int d = 0;
    while(tab_compress[c]!=-1){
        if(tab_compress[c]>=2){
            for (int i = 0; i < tab_compress[c]; i++)
            {
                tab_decompress[d]=tab_compress[c+1];
                d++;
            }
            c += 2;
        }else{
            tab_decompress[d]=tab_compress[c];
            c++;
            d++;
        }
    }
    tab_decompress[d]=-1;
    return d+1;
}

int identique(int tab1[], int tab2[]){
    int i = 0;
    while(tab1[i]==-1){
        if(tab1[i]!=tab2[i]){
            return 0;
        }
        i++;
    }
    return 1;
}

int main(){
    int *brut = init(TAILLE);
    affiche_tableau(brut,TAILLE);
    int *compress = init(TAILLE);
    int nb = compress_tab(brut, compress);
    affiche_tableau(compress,TAILLE);
    printf("nb: %d\n",nb);
    int *decompress = init(TAILLE);
    int dc = decomporess_tab(compress,decompress);
    affiche_tableau(decompress,TAILLE);
    printf("dc: %d\n",dc);
    printf("%d\n",identique(brut,decompress));
    return 0;
}