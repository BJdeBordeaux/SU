#include <stdlib.h>
#include <stdio.h>

typedef struct _noeud{
    int valeur;
    struct _noeud* fg;
    struct _noeud* fd;
    int hauteur; // ajout pour AVL
} Noeud;

typedef Noeud* ABR;

Noeud* rechercherValeur(ABR ab, int val){
    if(!ab){
        return NULL;
    }
    if(ab->valeur == val){
        return ab;
    }
    if(val<ab->valeur){
        return rechercherValeur(ab->fg, val);
    }
    return rechercherValeur(ab->fd, val);
}

ABR creeAB(int val){
    ABR res = (ABR) calloc(1, sizeof(Noeud));
    res->valeur = val;
    return res;
}

void insereElem_ss_eq(ABR* ab, int val){
    if(!*ab){
        *ab = creeAB(val);
    }
    if((*ab)->valeur < val){
        insereElem_ss_eq(&(*ab)->fg, val);
    }else if((*ab)->valeur > val){
        insereElem_ss_eq(&(*ab)->fd, val);
    }
    return;
}

// Si l'arbre n'est pas equilibre, alors l'algo n'est pas efficace;

int max(int a, int b){
    return a>b ? a:b;
}

int hauteur(ABR t){
    return (!t)?-1:t->hauteur;
}

void majHauteur(ABR t){
    if(!t) return;
    t->hauteur = 1+max(hauteur((t->fd)),hauteur(t->fg));
}

void rotationDroite(ABR* ab){
    if(!*ab || !(*ab)->fg) return;
    ABR g = (*ab)->fg;
    (*ab)->fg = g->fd;
    g->fd = *ab;
    *ab = g;
    majHauteur((g->fd));
    majHauteur(g);
}

void rotationGauche(ABR* ab){
    if(!*ab || !(*ab)->fd) return;
    ABR d = (*ab)->fd;
    (*ab)->fd = d->fg;
    d->fg = *ab;
    *ab = d;
    majHauteur(d->fg);
    majHauteur(d);
}

void doubleRotationDroite(ABR* ab){
    rotationGauche(&(*ab)->fg);
    rotationDroite(ab);
}

void doubleRotationGauche(ABR* ab){
    rotationDroite(&(*ab)->fd);
    rotationGauche(ab);
}

void insere_Elem_avec_eq(ABR* ab, int v){
    if(!*ab){
        *ab = creeAB(v);
    }
    if((*ab)->valeur < v){
        insere_Elem_avec_eq(&(*ab)->fg, v);
    }else if((*ab)->valeur > v){
        insere_Elem_avec_eq(&(*ab)->fd, v);
    }
    majHauteur(*ab);
    int diff = hauteur((*ab)->fg) - hauteur((*ab)->fd);
    if(diff < 2 && diff > -2)return;
    if(diff == -2){
        doubleRotationGauche(ab);
        majHauteur(*ab);
    }else{
        doubleRotationDroite(ab);
        majHauteur(*ab);
    }
}

void parcours_pre(ABR a){
    if(!a) return;
    printf("%d,", a->valeur);
    parcours_pre(a->fg);
    parcours_pre(a->fd);
}

// Q2
// Dans un ARN, 

typedef enum{rouge, noir} Couleur;
struct _arn
{
    int 
    struct _arn* fg;
    struct _arn* fd;
};

// FOR ALL tests
int main()
{
    ABR a1 = creeAB(1);
    ABR a2 = creeAB(1);
    for (int i = 2; i < 7; i++)
    {
        insereElem_ss_eq(&a1, i);
        insere_Elem_avec_eq(&a2, i);
    }

    parcours_pre(a1);
    putchar('\n');
    parcours_pre(a2);
    putchar('\n');
    
    return 0;
}
