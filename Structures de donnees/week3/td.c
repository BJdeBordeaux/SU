#include <stdlib.h>
#include <stdio.h>
#include "td.h"
PCellule creer_ldc(int data){
    PCellule res = (PCellule) malloc(sizeof(Cellule));
    res->data = data;
    res->suivant = NULL;
    res->precedent = NULL;
    return res;
}

PListe creer_liste(){
    PListe res = (PListe) malloc(sizeof(Liste));
    res->debut = NULL;
    res->fin = NULL;
    return res;
}

int listeVide(PListe l){
    return (!l->debut && !l->fin);
}

void insererEnTete(PListe l, PCellule c){
    if(listeVide(l)){
        l->debut = c;
        l->fin = c;
        return;
    }

    PCellule tete = l->debut;
    c->precedent = NULL;
    c->suivant = tete;
    tete->precedent = c;
    l->debut = c;
}

void insererEnFin(PListe l, PCellule c){
    if(listeVide(l)){
        l->debut = c;
        l->fin = c;
        return;
    }
    PCellule fin = l->fin;
    c->precedent = fin;
    c->suivant = NULL;
    fin->suivant = c;
    l->fin = c;
}

void afficher(PListe l){
    PCellule tmp = l->fin;
    while(tmp){
        printf("%d ", tmp->data);
        tmp = tmp->precedent;
    }
}

PCellule rechercher(PListe l, int val){
    if(!l) return NULL;
    if(listeVide(l)) return NULL;
    PCellule tmp = l->debut;
    while (tmp)
    {
        if (tmp->data == val)
        {
            return tmp;
        }
        tmp = tmp->suivant;
    }
    return NULL;
}

void supprimerElement(PListe l, PCellule target){
    PCellule prec = target->precedent;
    PCellule next = target->suivant;
    
    if(prec){
        prec->suivant = next;
    }else{
        l->debut = next;
    }
    if(next){
        next->precedent = prec;
    }else{
        l->fin = prec;
    }
    free(target);
}

int supprimerTete(PListe l){
    if(l->debut){
        int res = l->debut->data;
        supprimerElement(l, l->debut);
        return res;
    }
    return 0;
}

int supprimerFin(PListe l){
    if(l->fin){
        int res = l->fin->data;
        supprimerElement(l, l->fin);
        return res;
    }
    return 0;
}

void desallouerListe(PListe l){
    PCellule prec = l->debut;
    PCellule next = NULL;
    while (prec)
    {
        next = prec->suivant;
        free(prec);
        prec = next;
    }
    free(l);
}

struct _bureauDePoste
{
    int nb;
    PListe *guichets;
} bureauDePoste;
typedef struct _bureauDePoste *PBureauDePoste;

PBureauDePoste creerBureauDePoste(int n){
    PBureauDePoste res = (PBureauDePoste) malloc(sizeof(bureauDePoste));
    if(!res)return NULL;
    res->nb = n;
    res->guichets = (PListe*) malloc((n+1)*sizeof(Liste));
    if(!res->guichets){
        free(res);
        return NULL;
    }
    for (int i = 0; i <= n; i++)
    {
        res->guichets[i] = creer_liste();
    }
    return res;
}

void afficherPoste(PBureauDePoste bdp){
    int i;
    for ( i = 0; i < bdp->nb; i++)
    {
        afficher(bdp->guichets[i]);
    }
}

void ajouterAuGichet(PBureauDePoste poste, int num_gichet, int id){
    insererEnTete(poste->guichets[num_gichet],creer_Cellule(id));
}

int appelerAuGichet(PListe guichet){
    if(listeVide(guichet))return -1;
    int res = guichet->fin->data;
    supprimerFin(guichet);
    return res;
}
