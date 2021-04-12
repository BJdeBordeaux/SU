#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// EXO1

typedef struct arete {
    float distance; 
    int u;
    int v;
}Arete;

typedef struct liste_arete{
    Arete *a;
    struct liste_arete *suiv;
}ListeArete;

typedef struct sommet{
    char* nom_ville; 
    int num;
    float x, y; 
    ListeArete* L_adj;
}Sommet; 

typedef struct graph
{
    int n; //nb ville 
    int m; //nb route
    Sommet **tabSommet ; 
} Graph;

Graph* creer_graphe(int nb_vill){
    Graph* g = (Graph*) calloc(1,sizeof(Graph));
    g->m = 0;
    g->n = nb_vill;
    g->tabSommet = (Sommet**) calloc(nb_vill, sizeof(Sommet*));
    for (int i = 0; i < nb_vill; i++)
    {
        g->tabSommet[i] = (Sommet*) calloc(1,sizeof(Sommet));
        g->tabSommet[i]->num = i+1;
    }
    return g;
}

void miseAJourSommet(Graph*  g, int num, char *nom ,float x ,float y){
    g->tabSommet[num]->nom_ville = strdup(nom);   
    g->tabSommet[num]->x = x;
    g->tabSommet[num]->y = y;
}

Arete* creer_arete(int u, int v, double distance){
    Arete* a = (Arete*) calloc(1, sizeof(Arete));
    a->distance = distance;
    a->u = u;
    a->v = v;
    return a;
}

void insererTete_ListeArete(ListeArete** LA, Arete* a)
{
    ListeArete* ela = malloc(sizeof(ListeArete));
    ela->a    = a;
    ela->suiv = *LA; // tete actuelle devient le suivant
    *LA       = ela;  // nouvel element devient la tete
}

void ajouterArete(Graph* g, int u, int v, double dist)
{
    Arete *a = creer_arete(u, v, dist);
    insererTete_ListeArete(&(g->tabSommet[u]->L_adj), a);
    insererTete_ListeArete(&(g->tabSommet[v]->L_adj), a);
    // Graphe non oriente : il faut inserer l'arete pour les deux sommets
}

void afficherListeArete(ListeArete* la){
    while(la){
        printf("(%d, %d), ",la->a->u, la->a->v);;
        la = la->suiv;
    }
    putchar('\n');
}

void afficherListeGraph(Graph* g){
    Sommet* tmp = NULL;
    for (int i = 0; i < g->n; i++)
    {
        tmp = g->tabSommet[i];
        printf("%d, %s : (%.2lf, %.2lf) : ", tmp->num, tmp->nom_ville, tmp->x, tmp->y);
        afficherListeArete(tmp->L_adj);
    }
}

void libere_listeA2(ListeArete *l){
    // mettre u a -1, une fois on rencontre une arete
    //      avec u = -1, on le libere
    ListeArete *tmp_suiv = NULL;
    while (l){ 
        tmp_suiv = l->suiv;
        if(l->a->u != -1){
            l->a->u = -1;
        }else{
            free(l->a);
        }
        free(l);
        l = tmp_suiv;
    }
}

void libere_listeA(ListeArete* la)
{
    // ATTENTION : l'arrete est partagee entre deux listes chainees
    while(la != NULL) {
        ListeArete* suiv = la->suiv;

        if(la->a->u != -1) { // c'est la première fois qu'on rencontre cette arête
            la->a->u = -1;
        } else { // c'est la deuxième fois que l'on rencontre cette arête donc on peut faire free
            free(la->a);
        }
        free(la);
        la = suiv;
    }
}

void free_graph(Graph* g){
    for (int i = 0; i < g->n; i++)
    {
        free(g->tabSommet[i]->nom_ville);
        libere_listeA(g->tabSommet[i]->L_adj);
        free(g->tabSommet[i]);
    }
    free(g->tabSommet);
    free(g);
}

// EXO2
void degre_matrice(int n, int** M, int u, int* deg_s, int* deg_e){
    int e = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        s += M[u][i];
        e += M[i][u];
    }
    *deg_s = s;
    *deg_e = e;
}

int degre_liste_sortant(Graph* g, int u)
{
    int deg = 0;
    ListeArete* cur = g->tabSommet[u]->L_adj;
    while(cur != NULL) {
        deg++;
        cur = cur->suiv;
    }
    return deg;
}

int degre_liste_entrant(Graph* g, int u)
{
    int deg = 0;
    for(int i = 0; i< g->n ; i++) {
        ListeArete* cur = g->tabSommet[i]->L_adj;
        while(cur != NULL && cur->a->v != u) {
            cur = cur->suiv;
        }
        if(cur != NULL) deg++;
    }
    
    return deg;
    
}


int main()
{
    int nb_villes = 4; 
    Graph* g = creer_graphe(nb_villes);
    miseAJourSommet(g, 0, "Ville A", 100, 200);
    miseAJourSommet(g, 1, "Ville B", 200, 400);
    miseAJourSommet(g, 2, "Ville C", 300, 600);
    miseAJourSommet(g, 3, "Ville D", 400, 800);
    ajouterArete(g, 0, 1, 0.15);
    ajouterArete(g, 2, 1, 0.15);
    afficherListeGraph(g);
    free_graph(g);

    return 0;
}
