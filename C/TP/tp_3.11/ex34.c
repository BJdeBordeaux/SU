#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
#define W 10

void init(char plateau[N][N]);
void afficher(char plateau[N][N]);
int choisir_menul2q();
void jouer(char plateau[N][N], int joueur);
void jouerOrdinateur(char plateau[N][N]);
int partie_gagnee(char plateau[N][N]);
void jouer_a(char plateau[N][N], int nb_joueur);

int main(){
    char plateau[N][N];
    init(plateau);
    afficher(plateau);
    int mode = choisir_menul2q();
    printf("mode : %d\n",mode);
    // printf("marque : %d\n",1);
    if(mode == 1){
        jouer_a(plateau, 2);
    }else if(mode == 2){
        srand(time(NULL));
        jouer_a(plateau, 1);
    }else{
        printf("Goodbye!\n");
    }
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
    printf("   ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ",i+1);
    }
    printf("\n");
    
    for (int i = 0; i < N; i++)
    {
        printf("%-3d", i+1);
        for (int j = 0; j < N; j++)
        {
            printf("%c ",plateau[i][j]);
        }
        printf("\n");
    }
}

int choisir_menul2q(){
    int choix;
    printf("Veuillez choisir un jeu:\n");
    printf("1. joueur contre joueur\n");
    printf("2. joueur contre ordinateur\n");
    printf("3. quitter\n");
    // while((choix>3) || (choix<0))
    while(!scanf("%d",&choix) && choix>3 && choix<0)
    {
        // while(!scanf("%d",&choix) && choix>3 && choix<0)
        printf("La saisir n'est pas correcte.\nPlease retry\n");
        scanf("%d",&choix);
    }
    return choix;
}

void jouer(char plateau[N][N], int joueur){
    printf("Veuillez entrer les coordonnees dont vous allez mettre un pion.\n");
    int x, y;
    printf("la premiere coordonne y\n");
    scanf("%d",&x);
    while(x<=0 || x>N){
        printf("La saisir n'est pas correcte.\nPlease retry a y value\n");
        scanf("%d",&x);
    }
    printf("la deuxieme coordonne x\n");
    scanf("%d",&y);
    while(y<=0 || y>N){
        printf("La saisir n'est pas correcte.\nPlease retry a x value\n");
        scanf("%d",&y);
    }
    while(plateau[x-1][y-1] != '_'){
        printf("La position est occupee.\nVeuille reessayer\n");
        afficher(plateau);
        printf("Veuillez entrer les coordonnees dont vous allez mettre un pion.\n");
        printf("la premiere coordonne\n");
        scanf("%d",&x);
        while(x<=0 || x>N){
            printf("La saisir n'est pas correcte.\nPlease retry a x value\n");
            scanf("%d",&x);
        }
        printf("la deuxieme coordonne\n");
        scanf("%d",&y);
        while(y<=0 || y>N){
            printf("La saisir n'est pas correcte.\nPlease retry a y value\n");
            scanf("%d",&y);
        }
    }
    if (joueur % 2 == 0){
        plateau[x-1][y-1] = 'X';
    }else{
        plateau[x-1][y-1] = 'O';
    }
}

void jouerOrdinateur(char plateau[N][N]){
    int x = rand()%N, y = rand()%N;
    while(plateau[x][y] != '_'){
        x = rand()%N;
        y = rand()%N;
    }
    plateau[x][y] = 'X';
}

int partie_gagnee(char plateau[N][N]){
    afficher(plateau);
    int i = 0, j = 0;
    int cpt = 0;
    while(i < N  && cpt < N)
    {
        cpt = 0;
        if(plateau[i][0] != '_'){
            while(j < N && plateau[i][j] == plateau[i][0])
            {
                cpt++;
                j++;
            }
        }
        i++;
        j = 0;
    }
    if(cpt == N){
        if(plateau[i-1][0] == 'X'){
            printf("Le joueur %d gagne\n", 0);
        }else{
            printf("Le joueur %d gagne\n", 1);
        }
        return 1;
    }

    cpt = 0;
    i = 0;
    j = 0;
    while(j < N && cpt < N){
        cpt = 0;
        if(plateau[i][j] != '_'){
            while(i < N && plateau[i][j] == plateau[0][j])
            {   
                cpt++;
                i++;
            }
        }
        i = 0;
        j++;
    }
    if(cpt == N){
        if(plateau[0][j-1] == 'X'){
            printf("Le joueur %d gagne\n", 0);
        }else{
            printf("Le joueur %d gagne\n", 1);
        }
        return 1;
    }

    i = 0;
    j = 0;
    cpt = 0;
    if(plateau[i][j] != '_'){
        while(i < N && plateau[i][j] == plateau[0][0]){
            cpt++;
            i++;
            j++;
        }
    }
    if(cpt == N){
        if(plateau[0][0] == 'X'){
            printf("Le joueur %d gagne\n", 0);
        }else{
            printf("Le joueur %d gagne\n", 1);
        }
        return 1;
    }

    i = 0;
    j = N;
    cpt = 0;
    if(plateau[i][j] != '_'){
        while(i < N && plateau[i][j] == plateau[9][0]){
            cpt++;
            i++;
            j--;
        }
    }
    if(cpt == N){
        if(plateau[0][0] == 'X'){
            printf("Le joueur %d gagne\n", 0);
        }else{
            printf("Le joueur %d gagne\n", 1);
        }
        return 1;
    }

    int cpt2 = 0;
    i = 0; 
    while(i < N){
        j = 0;
        while(j < N){
            if(plateau[i][j] != '_'){
                cpt2++;
            }
            j++;
        }
        i++;
    }
    if (cpt2 == N*N)
    {
        printf("match nul.\n");
        return 0;
    }
    return -1;
}

void jouer_a(char plateau[N][N], int nb_joueur){
    int joueur1 = 0;
    int joueur2 = 1;
    int winner = -1;
    if(nb_joueur == 2){
        int cur_joueur = 0;
        while(winner != 0 && winner != 1){
            jouer(plateau, cur_joueur);
            cur_joueur++;
            winner = partie_gagnee(plateau);
        }
    }else if(nb_joueur == 1){
        while(winner != 0 && winner != 1){
            jouerOrdinateur(plateau);
            winner = partie_gagnee(plateau);
            jouer(plateau, joueur2);
            winner = partie_gagnee(plateau);
        }
    }else{
        printf("Exit the game\n");
    }
}

