#include<string.h>
#define TAILLES_STOCK 2

typedef struct article {
    int ref;
    float prix;
    int quantite;
} article;

article stock[TAILLES_STOCK];

void augmenter_prix(article *ar, float taux){
    (*ar).prix *= (1+taux/100);
    // ou ar->prix *= (1+taux/100);
}

void augmentationGenerale(article stock[], int taille, float taux){
    for (int i = 0; i < taille; i++)
    {
        augmenter_prix(stock+i, taux);
    }
}

int main(){

    return 0;
}