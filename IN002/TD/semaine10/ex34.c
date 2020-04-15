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
    cellule_t *res = Creer_cellule(d);
    res->suivant = cell;
    return res;
}

cellule_t *Creer_liste_positive(cellule_t *liste){
    cellule_t *res = NULL;
    while(liste){
        if(liste->donnee > 0){res = Inserer_tete(liste->donnee,res);}
        liste = liste->suivant;
    }
    return res;
}

cellule_t *Creer_liste_positive_rec(cellule_t *liste){
    if(!liste){return NULL;}
    if(liste->donnee>0){
        return Inserer_tete(liste->donnee,Creer_liste_positive_rec(liste->suivant));
    }else{
        return Creer_liste_positive_rec(liste->suivant);
    }
}

cellule_t *Garder_positifs(cellule_t *liste){
    cellule_t *tete = liste;
    while(tete && tete->donnee<=0){
        cellule_t *tem = tete;
        tete = tete->suivant;
        free(tem);
    }
    liste = tete;
    if(liste){
        while(liste->suivant){
            if(liste->suivant->donnee<=0){
                cellule_t *tem = liste->suivant->suivant;
                free(liste->suivant);
                liste->suivant = tem;
            }else{
                liste = liste->suivant;
            }
        }
    }
    return tete;
}

void AfficherListeInt(cellule_t *l){
    int cpt = 0;
    cellule_t *cur_l = l;
    while(cur_l != NULL){
        printf("%d  ", cur_l->donnee);
        cur_l = cur_l->suivant;
        cpt++;
        if(cpt > 5){break;}
    }
    printf("\n");
}



int main(){
    cellule_t *tete = Creer_cellule(1);
    tete = Inserer_tete(-2,tete);
    tete = Inserer_tete(3,tete);
    // cellule_t *t4 = Creer_liste_positive(tete);
    // AfficherListeInt(t4);
    // cellule_t *t5 = Creer_liste_positive_rec(tete);
    // AfficherListeInt(t5);
    AfficherListeInt(tete);
    cellule_t *t6 = Garder_positifs(tete);
    AfficherListeInt(t6);
    return 0;
}