#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* tab; // le vrai tableau
    int free; // première case libre
    int taille; // taille du tableau
} Tableau;

// EX1
// Q1
int rang(Tableau* t, int x, int deb, int fin){
    if(deb == fin){
        if(t->tab[deb] < x){
            return deb;
        }
        return deb-1;
    }
    if(deb == fin-1){
        if(t->tab[fin] > x){
            return fin;
        }
        return fin+1;
    }
    int milieu = deb + (fin-deb)/2;
    if(x == t->tab[milieu]){
        return milieu;
    }
    if(x < t->tab[milieu]){
        return rang(t, x, deb, milieu-1);
    }
    return rang(t, x, milieu, fin);
}

// en O(log n)
// car le tableau est de taille n, on divise par 2 a chaque appel
// jusqu'a ce que sa taille soit <= 1
// on peut definir p qui est le nombre d'appel de la fonction
// donc la taille du tableau est environ n/(2^p)
// on veut p le plus petit possible pour attendre un tableau de taille 1
// n/(2^p) <= 1 <=> p >= log2(n)

// Q2
void decaler(Tableau* t, int indice_a_decaler);
Tableau* triInsertDicho(Tableau* t){
    int elt, indice_a_inserer;
    Tableau* tri = (Tableau*) malloc(sizeof(Tableau));
    tri->taille = t->taille;
    tri->tab = (int*) malloc(sizeof(int)*t->taille);
    tri->free = 0;
    for (int i = 0; i < t->taille; i++)
    {
        elt = t->tab[i];
        // on fait l'ajout trié
        if(tri->free == 0){
            tri->tab[0] = elt;
            tri->free++;
        }else{
            indice_a_inserer = rang(tri, elt, 0, t->taille-1);
            decaler(tri, indice_a_inserer);
            tri->tab[indice_a_inserer] = elt;
            tri->free++;
        }
        
    }
    
    return tri;
}

// en O(n²) car deux boucles une qui parcourt tout le tableau
// l'autre dans le pire des cas parcourt presque tout le tableau

void decaler(Tableau* t, int indice_a_decaler){
    for (int i = t->taille-1; i > indice_a_decaler; i--){
        t->tab[i] = t->tab[i-1];
    }
}

// Q3
// recherche dans une liste O(i)
// méthode de tri O(n²)
// pas possible d'utiliser la recherche dicho dans les listes

// EX2
// Q1
void tri(Tableau* t, int min, int max){
    assert(max>=min);
    int length = max-min+1;
    int k[length];
    for (int i = 0; i < length; i++)
    {
        k[i] = 0;
    }
    for (int i = 0; i < length; i++)
    {
        k[t->tab[i]-min]++;
    }
    int j =0;
    for (int i = 0; i < length; i++){
        while(k[i--]>0){
            t->tab[j] = i + min;
        }
    }
}

// Q2
// complexite temps et memoire O(n+(max-min)) = O(n)
// ne peut pas atteindre une val quelconque. 
// Il faut etre assimilees pour calculer l'indice 
// et il faut que max-min soit petit pour tenir en memoire

// Q3
// au lieu d'utiliser un tab on utilise un tab de hachage
// avec gestion de collisions par chainage
// on choisir N correspondant au nb de case de la table et stock de maniere suiv
// case 0 on met toutes les val entre min + (max-min)/N
// case 1 on met toutes les val entre min + 2*(max-min)/N
// case 2 on met toutes les val entre min + 3*(max-min)/N
// ......
// on va trier chaque liste chainee et on concatener les listes