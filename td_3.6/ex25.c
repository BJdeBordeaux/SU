#include<stdio.h>

#define TAILLE 10
int tab[TAILLE] = {5,6,10,11,12,15,17,18,20,21};

int research_dich(int *tab, int len, int tar){
    int g = 0, d = len;
    int i = len/2, res = tab[i];
    while(g <= d){
        if(res<tar){
            g = i+1;
            i = (g+d)/2;
        }else if(res>tar){
            d = i-1;
            i = (g+d)/2;
        }else{
            return i;
        }
        res = tab[i];
    }
    return -1;
}

int research_dich_recu(int *tab, int len, int tar){
    int m = len/2;
    if (len == 0)
    {
        return 0;
    }else if (tab[m] == tar)
    {
        return 1;
    }else if (tab[m] > tar)
    {
        return research_dich_recu(tab, m, tar);
    }else if (tab[m] < tar)
    {
        return research_dich_recu(tab+m+1, len-m-1, tar);
    }
    
    
    

    return -1;
}

int main(){
    int tar;
    printf("Please enter a integer that you want to find.\n");
    if(scanf("%d",&tar)){
        printf("The indice of %d is %d\n", tar, research_dich(tab, TAILLE, tar));
    }
    // int tar = 7;
    // printf("The indice of %d is %d\n", tar, research_dich(tab, TAILLE, tar));
}