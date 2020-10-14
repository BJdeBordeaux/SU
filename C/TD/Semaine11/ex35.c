#include <stdio.h>
#include <stdlib.h>
#include "liste_entiers.h"
#include "multi_ensembles.h"

element_t *Creer_multi_ensemble_liste(cellule_t *liste){
    if(!liste){return NULL;}
    element_t *res = Ajout_tete_ensemble(NULL, liste->donnee, 1);
    element_t *tem = res;
    while(liste->suivant){
        liste = liste->suivant;
        if(liste->donnee == tem->valeur){tem->frequence++;}
        else{
            tem->suivant = Ajout_ensemble_trie(NULL, liste->donnee, 1);
            tem = tem->suivant;
        }
    }
    return res;
}

int main(){
    cellule_t *a = malloc(sizeof(cellule_t));a->donnee=3;a->suivant=NULL;
    cellule_t *b = malloc(sizeof(cellule_t));b->donnee=2;b->suivant=a;
    cellule_t *c =  malloc(sizeof(cellule_t));c->donnee=1;c->suivant=b;
    cellule_t *c2 =  malloc(sizeof(cellule_t));c2->donnee=0;c2->suivant=c;
    cellule_t *ma_liste=creerListe(5);
    AfficherListeInt(ma_liste);
    Affiche_ensemble(Creer_multi_ensemble_liste(ma_liste));
    return 0;
}