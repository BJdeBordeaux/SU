#ifndef _API_LISTE_H_
#define _API_LISTE_H_

#include <stdio.h>

typedef struct _element *PElement;
typedef struct _element {
  void *data;
  PElement suivant;
} Element;

typedef struct _liste *PListe;
typedef struct _liste {
  PElement elements;
  void *(*dupliquer)(const void *src);
  void (*copier)(const void *src, void *dst);
  void (*detruire)(void *data);
  void (*afficher)(const void *data);
  int (*comparer)(const void *a, const void *b);
  int (*ecrire)(const void *data, FILE *f);
  void *(*lire)(FILE *f);
} Liste;

// insere en debut de liste
void inserer_debut(PListe pliste, void *data);

// insere en fin de liste
void inserer_fin(PListe pliste, void *data);

// insere en place, par ordre strictement croissant (pas d'ajout si l'element est deja dans la liste)
void inserer_place(PListe pliste, void *data);

// chercher une donnee dans une liste. Renvoie NULL si non trouve
PElement chercher_liste(PListe pliste, void *data);

// chercher dans une liste triee (plus rapide dans certains cas)
PElement chercher_liste_triee(PListe pliste, void *data);

// detruire une liste
void detruire_liste(PListe pliste);

// afficher une liste
void afficher_liste(PListe pliste);

// ecrire une liste dans un fichier (renvoie 0 en cas d'echec, 1 si succes)
int ecrire_liste(PListe pliste, const char *nom_fichier);

// lire une liste depuis un fichier
int lire_liste(PListe pliste, const char * nom_fichier);

// creation d'une liste a partir d'un ensemble de donnees
void ajouter_liste(PListe pliste, int nb_data, ...);

// appliquer une fonction a tous les elements d'une liste
void map(PListe pliste, void (*fonction)(void *data, void *oa), void *optarg);

// Extraction en tete
PElement extraire_en_tete(PListe pl);



#endif
