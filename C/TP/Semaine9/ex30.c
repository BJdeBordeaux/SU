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
    // printf("mark %d\n",1);
    cellule_t *res = Creer_cellule(d);
    res->suivant = cell;
    // AfficherListeInt(res);
    // printf("mark %d\n",2);
    return res;
}

cellule_t *Inserer_fin_it(int d, cellule_t *cell){
    cellule_t *res = Creer_cellule(d);
    // AfficherListeInt(res);
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

cellule_t *Inserer_en_pos(int d, int pos, cellule_t *liste){
    if(liste == NULL || pos == 0){
        return Inserer_tete(d, liste);
    }
    cellule_t *new = Creer_cellule(d);
    cellule_t *tem = liste;
    while(tem->suivant && pos>1){
        tem = tem->suivant;
        pos--;
    }
    new->suivant = tem->suivant;
    tem->suivant = new;
    return liste;
}

// EX31
cellule_t *Liberer_liste(cellule_t *liste){
    cellule_t *tem;
    while(liste){
        tem = liste;
        liste = liste->suivant;
        free(tem);
    }
    return NULL;
}

cellule_t *Supprimer_en_pos(int pos, cellule_t *liste){
    // if(liste == NULL){return NULL;}
    // cellule_t *d = liste;
    // cellule_t *tem = liste->suivant;
    // if(pos == 0){free(d);return tem;}
    // while(pos > 1 && tem){
    //     d = d->suivant;
    //     tem = tem->suivant;
    //     pos--;
    // }
    // if(tem){
    //     d->suivant = tem->suivant;
    //     free(tem);
    // }
    cellule_t *d;
    cellule_t *tem;
    if(pos == 0){
        tem = liste->suivant;
        free(liste);
        return tem;
    }
    d = liste;
    while(d->suivant && pos >1){
        d = d->suivant;
        pos--;
    }
    if(d->suivant){
        tem = d->suivant;
        d->suivant = tem->suivant;
        free(tem);
    }
    return liste;
}

int main(){
    cellule_t *tete = Creer_cellule(2);
    // AfficherListeInt(tete);

    tete = Inserer_fin_it(1,tete);
    // AfficherListeInt(tete);

    tete = Inserer_tete(3,tete);
    tete = Inserer_en_pos(4, 2, tete);
    
    Liberer_liste(tete);
    // AfficherListeInt(tete);
    // tete = Supprimer_en_pos(8,tete);
    AfficherListeInt(tete);
    return 0;
}