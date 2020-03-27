#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define TAILLE1 7
#define TAILLE2 5

int *fusion_tableau_trie(int tab1[], int taille1, int tab2[], int taille2){
    int len = taille1+taille2;
    int *res = malloc(len*sizeof(int));
    int cpt1 = 0;
    int cpt2 = 0;
    for (int i = 0; i < len; i++)
    {
        if(cpt1 < taille1 && cpt2 < taille2){
            if(tab1[cpt1]<=tab2[cpt2]){
                *(res + i)=tab1[cpt1];
                    cpt1++;
            }
            else{//(tab1[cpt1]>tab2[cpt2])
                *(res + i)=tab2[cpt2];
                    cpt2++;
                }
        }else{
            if (cpt1 == taille1)
            {
                res[i] = tab2[cpt2];
                cpt2++;
            }else if(cpt2 == taille2){
                res[i] = tab1[cpt1];
                cpt1++;
            }
            
        }
        // printf("cpt1,2, tab1[cpt1], tab2[cpt2] i:%d, %d, %d, %d, %d\n",cpt1, cpt2,tab1[cpt1], tab2[cpt2], i);
    }
    return res;
}

int main(){
    // int tab1[] = {1,3,5,7,9};
    // int tab2[] = {2,4,6,8,10,12,14};
    int tab1[] = {1,3,5,7,9,11,13};
    int tab2[] = {2,4,6,8,10};
    int *tab3 = fusion_tableau_trie(tab1, TAILLE1, tab2, TAILLE2);
    for (int i = 0; i < TAILLE1+TAILLE2-1; i++)
    {
        assert(tab3[i]<=tab3[i+1]);
        // printf("i, tab[i]: %d, %d\n",i, tab3[i]);
    }
    printf("success.\n");
    
    return 0;
}