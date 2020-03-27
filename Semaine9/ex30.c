#include <stdio.h>
#include <stdlib.h>

typedef struct _cellule_t cellule_t;

struct _cellule_t {
  int donnee;
  cellule_t *suivant;
};

void AfficherListeInt(cellule_t *l);

cellule_t *Creer_cellule(int d){
    cellule_t *res = (cellule_t *) malloc(sizeof(cellule_t));
    res->donnee = d;
    res->suivant = NULL;
    return res;
}

cellule_t *Inserer_tete(int d, cellule_t *cell){
    // AfficherListeInt(cell);
    cellule_t *res = (cellule_t *) malloc(sizeof(cellule_t));
    res->donnee = d;
    res->suivant = cell;
    return res;
}

cellule_t *Inserer_fin_it(int d, cellule_t *cell){
    cellule_t *res = (cellule_t *) malloc(sizeof(cellule_t));
    res->donnee = d;
    res->suivant = NULL;
    if(cell == NULL){
        return res;
    }
    cellule_t *tem = cell;
    while(tem->suivant != NULL){
        tem = tem->suivant;
    }
    tem->suivant = res;
    return cell;
}

void AfficherListeInt(cellule_t *l){
    // int cpt = 1;
    cellule_t *cur_l = l;
    while(cur_l != NULL){
        printf("Le element courant: %d\n", cur_l->donnee);
        cur_l = cur_l->suivant;
        // cpt++;
    }
}

int main(){
    cellule_t *tete = Creer_cellule(2);
    // tete = Inserer_fin_it(1,tete);
    // tete = Inserer_tete(3,tete);
    Inserer_fin_it(1,tete);
    Inserer_tete(3,tete);
    AfficherListeInt(tete);
    return 0;
}