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

cellule_t *Renvoyer_element_debut_rec(int val, cellule_t *liste){
    if(!liste){
        return NULL;
    }else if(liste->donnee == val){
        return liste;
    }else{
        return Renvoyer_element_debut_rec(val, liste->suivant);
    }
}

cellule_t *Inserer_fin_rec(int val, cellule_t *liste){
    if(!liste){return Creer_cellule(val);}
    liste->suivant = Inserer_fin_rec(val, liste->suivant);
    return liste;
}

cellule_t *Supprimer_en_pos_rec(int pos, cellule_t *liste){
    if(!liste){
        return NULL;
    }
    if(!pos){
        cellule_t *tem = liste->suivant;
        free(liste);
        return tem;
    }
    liste->suivant = Supprimer_en_pos_rec(pos-1, liste->suivant);
    return liste;
}

cellule_t *Creer_liste_positive(cellule_t *liste){
    cellule_t *res = NULL;
    cellule_t *tem2 = liste;
    while(tem2){
        if(tem2->donnee > 0){
            res = Inserer_fin_rec(tem2->donnee,res);
        }
        tem2 = tem2->suivant;
    }
    return res;
}

cellule_t *Inserer_fin_it(int d, cellule_t *cell){
    cellule_t *res = Creer_cellule(d);
    if(!cell){
        return res;
    }
    cellule_t *tem = cell;
    while(tem->suivant){
        tem = tem->suivant;
    }
    tem->suivant = res;
    return cell;
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
    tete = Inserer_fin_it(-2,tete);
    tete = Inserer_fin_it(3,tete);
    // cellule_t *t1 = Renvoyer_element_debut_rec(1, tete);
    // AfficherListeInt(t1);
    // cellule_t *t2 = Inserer_fin_rec(2,tete);
    // AfficherListeInt(t2);
    // cellule_t *t3 = Supprimer_en_pos_rec(2,tete);
    // AfficherListeInt(t3);
    cellule_t *t4 = Creer_liste_positive(tete);
    AfficherListeInt(t4);
    AfficherListeInt(tete);
    return 0;
}