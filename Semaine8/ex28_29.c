#include<stdio.h>
#include "liste_entiers.h"
#include<stdlib.h>

cellule_t *Creer_cellule(int d){
    cellule_t *cellule = (cellule_t*) malloc(sizeof(cellule_t));
    if(cellule){
        cellule->donnee = d;
        cellule->suivant = NULL;
    }
    return cellule;
}

int len_cellule(cellule_t *l){
    int cpt = 0;
    cellule_t *cell = l;
    while(cell != NULL){
        cpt++;
        cell = cell->suivant;
    }
    return cpt;
}

int exist(int val, cellule_t *l){
    cellule_t *tem = l;
    while(l != NULL){
        if(l->donnee == val){
            return 1;
        }
        tem = tem->suivant;
    }
    return 0;
}

cellule_t *Renvoyer_element_debut(int val, cellule_t *l){
    cellule_t *res = l;
    while (res != NULL){
        if(res->donnee == val){
            return res;
        }
        res = res->suivant;
    }
    return res;
}

cellule_t *Renvoyer_element_fin(int val, cellule_t *l){
    cellule_t *tem = l;
    cellule_t *res = NULL;
    while (tem != NULL){
        if(tem->donnee == val){
            res = tem;
        }
        tem = tem->suivant;
    }
    return res;
}

cellule_t *Renvoyer_dernier_element(cellule_t *l){
    if(l == NULL){return NULL;}
    cellule_t *res = l;
    while(res->suivant != NULL){
        res = res->suivant;
    }
    return res;
}

cellule_t *Modifier_element(int val, int pos, cellule_t *l){
    int cpt = pos;
    cellule_t *tem = l;
    while(tem != NULL && cpt > 0){
        tem = tem->suivant;
        cpt--;
    }
    if(tem != NULL){tem->donnee = val;}
    return l;
}

int main(){
    cellule_t *cell1 = Creer_cellule(5);
    printf("%d \n",cell1->donnee);
    return 0;
}