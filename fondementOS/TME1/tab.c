#include <stdio.h>
#include "tab.h"

void InitTab(int* tab, int size){
    for (int i = 0; i < size; i++)
    {
        tab[i] = rand()%10;
    }
}

void PrintTab(int *tab, int size){
    int i;
    for (i = 0; i < size - 1; i++)
    {
        printf("%d, ", tab[i]);
    }
    printf("%d\n", tab[i]);
}

int SumTab(int* tab, int size){
    int res = 0;

    for (int i = 0; i < size; i++)
    {
        res += tab[i];
    }

    return res;
}

int MinSumTab(int* min, int *tab, int size){
    int res = 0;
    int minTab = tab[0];
    for (int i = 0; i < size; i++)
    {
        res += tab[i];
        if(tab[i] < minTab){
            minTab = tab[i];
        }
    }
    *min = minTab;
    return res;
}