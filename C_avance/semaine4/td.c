#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Nd_mot_ 
{
    char *mot;
    struct Nd_mot_ *g;
    struct Nd_mot_ *d;
} Nd_mot;

typedef struct Lm_mot_ {
    char *mot;
    struct Lm_mot_ *suiv;
} Lm_mot;

int lenth_Lmot(Lm_mot* l){
    int cpt = 0;
    while(l != NULL){
        cpt++;
        l = l->suiv;
    }
    return cpt;
}

Lm_mot *part_Lmot(Lm_mot **pl){
    Lm_mot *p = *pl;
    Lm_mot *pivot;

    if(lenth_Lmot(*pl) < 3){
        *pl = NULL;
        return p;
    }

    int length = lenth_Lmot(*pl);

    return NULL;
}

Nd_mot *Lm2abr(Lm_mot *l){
    Nd_mot *nd;
    Lm_mot *pivot;

    if(l == NULL){
        return NULL;
    }

    nd = malloc(sizeof(Nd_mot));
    pivot = part_Lmot(&l);

    nd->mot = pivot->mot;
    nd->g = Lm2abr(pivot->suiv); // fils droit
    nd->d = Lm2abr(l); // fils gauche

    free(pivot->mot);
    free(pivot);
    return nd;
}

Nd_mot *chercher_Nd_mot(Nd_mot *abr, const char *mot){
    if(abr == NULL){
        return NULL;
    }
    if(strcmp(mot, abr->mot) == 0){
        return abr;
    }else if (strcmp(mot, abr->mot) < 0){
        return chercher_Nd_mot(abr->g, mot);
    }else{
        return chercher_Nd_mot(abr->d, mot);
    }
}


void detruire_abr_mot(Nd_mot *abr){
    if(abr == NULL){
        return;
    }
    detruire_abr_mot(abr->g);
    detruire_abr_mot(abr->d);
    
    free(abr->mot);
    free(abr);
}

typedef struct noeud *PNoeud;
typedef enum _FDM {fin, non_fin} FDM;

typedef struct noeud{
    char lettre;
    FDM fin_de_mot;
    PNoeud fils;
    PNoeud frere_suivant;
} Noeud;


PNoeud creer_noeud(char lettre){

    PNoeud pn = malloc(sizeof(Noeud));
    assert(pn);

    pn->lettre = lettre;
    pn->fin_de_mot = non_fin;
    pn->fils = NULL;
    pn->frere_suivant = NULL;

    return pn;
}

PNoeud chercher_lettre(PNoeud n, char lettre){
    if(n == NULL){
        return NULL;
    }
    if(n->lettre == lettre){
        return n;
    }
    if(n->lettre > lettre){
        return NULL;
    }else{
        return chercher_lettre(n->frere_suivant, lettre);
    }
}

int rechercher_mot(PNoeud dico, char *mot){
    PNoeud n = rechercher_mot(dico, mot[0]);

    if(n == NULL){
        return 0;
    }
    if(strlen(mot) == 1){
        return n->fin_de_mot = fin;
    }
    return rechercher_mot(n->fils, mot+1);
}
