// Q1 
// arbre (racine) ? connexe ? cycle ?

#include <stdlib.h>
#include <stdio.h>
typedef struct cellule {
    int v ; /* indice d’un sommet de tabS */
    struct cellule * suiv ; /* pointeur sur le lien suivant */
} Cellule ;

typedef struct {
    int nbsom ;/* Nombre de sommets */
    Cellule ** tabS ;/* Tableau de listes chainees de sommets */
} GrapheSimple ;


void cree_graphe(GrapheSimple *G , int n ) {
    int i;
    G->nbsom = n ;
    G->tabS = ( Cellule **) malloc ( n * sizeof ( Cellule *) ) ;
    for ( i=0; i< n ; i++)
    G->tabS[i]= NULL ;
}

void ajoute_lien ( GrapheSimple *G , int i, int j ) { // ajoute le lien orient’e (i,j)
    Cellule * nouv =( Cellule *) malloc ( sizeof ( Cellule ) ) ;
    nouv->v = j ;
    nouv->suiv =G->tabS[i];
    G->tabS[i]= nouv ;
}

void aff_graphe ( GrapheSimple * G ) {
    printf ("\n\nGraphe : \n") ;
    int i;
    for (i = 0; i < G->nbsom ; i++) {
        printf ("%d :", i) ;
        Cellule * cour =G->tabS[i];
        while (cour != NULL) {
            printf ("%d, ", cour->v ) ;
            cour = cour->suiv ;
        }
       printf ("\n") ;
    }
}

void aff_parcours_1 ( GrapheSimple * G , int r ) {
    printf ("%d, " ,r ) ;
    Cellule * cour = G->tabS [ r ];
    while ( cour != NULL ) {
        int v = cour->v ;
        aff_parcours_1 (G , v ) ;
        cour = cour->suiv ;
    }
}

void aff_parcours_2(GrapheSimple* G, int r, int u) {
    printf("%d \n", r);
    Cellule* cour = G->tabS[r];
    while(cour != NULL) {
        int v = cour->v;
        if(u!=v) aff_parcours_2(G,v,r);
        cour = cour->suiv;
    }
}

void aff_parcours_3(GrapheSimple* G, int r, int* visit) {
    visit[r] = 1;
    printf("%d ", r);
    Cellule* cour = G->tabS[r];
    while(cour!=NULL) {
        if(visit[cour->v] == 0) { 
            aff_parcours_3(G, cour->v, visit);
        }
        cour = cour->suiv;
    }
}

int detecte_circuit_descendant(GrapheSimple* G, int r, int* visit) {
    int detect = 0;
    visit[r] = 1;
    
    Cellule* cour = G->tabS[r];
    while(cour && !detect) {
        int v = cour->v;
        if(visit[v] == 0) {
            detect = detecte_circuit_descendant(G,v,visit);
        }
        else if(visit[v] == 1) {
            detect = 1;
        }        
        cour = cour->suiv;
    }
    visit[r] = 2;
    return detect;
}

int detecte_circuit(GrapheSimple* G) {
    int* visit = malloc(sizeof(int) * G->nbsom);
    int r = 0;
    int detect = 0;
    
    for(int i=0; !detect && i<G->nbsom;i++) {
        visit[i] = 0;
        detect = detecte_circuit_descendant(G, i, visit);
    }
    
    free(visit);
    return detect;
}

int main()
{
    GrapheSimple *g1 = malloc(sizeof(GrapheSimple));
    cree_graphe(g1, 6);
    ajoute_lien(g1, 0, 1);
    ajoute_lien(g1, 0, 4);
    ajoute_lien(g1, 1, 2);
    ajoute_lien(g1, 1, 3);
    ajoute_lien(g1, 1, 5);
    // aff_graphe(g1);

    GrapheSimple *g2 = malloc(sizeof(GrapheSimple));
    cree_graphe(g2, 6);
    ajoute_lien(g2, 0, 1);
    ajoute_lien(g2, 1, 0);
    ajoute_lien(g2, 0, 4);
    ajoute_lien(g2, 4, 0);
    ajoute_lien(g2, 1, 2);
    ajoute_lien(g2, 2, 1);
    ajoute_lien(g2, 1, 3);
    ajoute_lien(g2, 3, 1);
    ajoute_lien(g2, 1, 5);
    ajoute_lien(g2, 5, 1);
    // aff_graphe(g2);

    GrapheSimple* g3 = malloc(sizeof(GrapheSimple));
    cree_graphe(g3, 6);
    ajoute_lien(g3, 0, 1);
    ajoute_lien(g3, 0, 4);
    ajoute_lien(g3, 1, 2);
    ajoute_lien(g3, 1, 3);
    ajoute_lien(g3, 1, 5);
    ajoute_lien(g3, 3, 4);
    ajoute_lien(g3, 4, 5);
    ajoute_lien(g3, 5, 3);
    ajoute_lien(g3, 2, 3);
    aff_graphe(g3);

    GrapheSimple *g4 = malloc(sizeof(GrapheSimple));
    cree_graphe(g4, 6);
    ajoute_lien(g4, 0, 1);
    ajoute_lien(g4, 1, 0);
    ajoute_lien(g4, 0, 4);
    ajoute_lien(g4, 4, 0);
    ajoute_lien(g4, 1, 2);
    ajoute_lien(g4, 2, 1);
    ajoute_lien(g4, 1, 3);
    ajoute_lien(g4, 3, 1);
    ajoute_lien(g4, 1, 5);
    ajoute_lien(g4, 5, 1);
    ajoute_lien(g4, 3, 4);
    ajoute_lien(g4, 4, 3);
    ajoute_lien(g4, 4, 5);
    ajoute_lien(g4, 5, 4);
    ajoute_lien(g4, 5, 3);
    ajoute_lien(g4, 3, 5);
    ajoute_lien(g4, 2, 3);
    ajoute_lien(g4, 3, 2);
    // aff_graphe(g4);

    // aff_parcours_1(g1, 0);
    // aff_parcours_1(g2, 0);

    // aff_parcours_2(g2, 0, 0);
    
    int parcours3[6] = {0, }; 
    aff_parcours_3(g3, 0, parcours3);
    return 0;
}
