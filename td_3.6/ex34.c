#include<stdio.h>
#include<stdlib.h>

#define N 10

void init(char plateau[N][N]);
void afficher(char plateau[N][N]);

int main(){
    char plateau[N][N];
    init(plateau);
    afficher(plateau);
    return 0;
}

void init(char plateau[N][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            plateau[i][j] = '_';
        }   
    }
}

void afficher(char plateau[N][N]){
    printf("  ");
    for (int i = 0; i < N; i++)
    {
        printf("%c ",'a'+i);
    }
    printf("\n");
    
    for (int i = 0; i < N; i++)
    {
        printf("%c ",'A'+i);
        for (int j = 0; j < N; j++)
        {
            printf("%c ",plateau[i][j]);
        }
        printf("\n");
    }
}