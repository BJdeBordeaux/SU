#include <stdlib.h>
#include <assert.h>
#include "arbre_binaire.h"
PArbreBinaire creer_arbre(char copie,
			  void *(*dupliquer)(const void *src),
			  void (*copier)(const void *src, void *dst),
			  void (*detruire)(void *data),
			  void (*afficher)(const void *data),
			  int (*comparer)(const void *a, const void *b),
			  int (*ecrire)(const void *data, FILE *f),
			  void *(*lire)(FILE *f)
			  ) {
  PArbreBinaire pab=(PArbreBinaire)malloc(sizeof(ArbreBinaire));
  if(pab==NULL) {
    printf("Probleme d'allocation de l'arbre binaire.\n");
    return NULL;
  }
  pab->racine=NULL;
  pab->copie=copie;
  pab->dupliquer=dupliquer;
  pab->copier=copier;
  pab->detruire=detruire;
  pab->afficher=afficher;
  pab->comparer=comparer;
  pab->ecrire=ecrire;
  pab->lire=lire;
  return pab;
}


PNoeudBinaire creer_noeud_binaire(PArbreBinaire pab, void *data){
  PNoeudBinaire n=(PNoeudBinaire)malloc(sizeof(NoeudBinaire));
  if (n==NULL) {
    printf("Probleme lors de l'allocation d'un noeud binaire.\n");
    return NULL;
  }
  if (pab->copie)
    n->data=pab->dupliquer(data);
  else
    n->data=data;
  n->gauche=NULL;
  n->droit=NULL;
  return n;
}

void detruire_noeud_binaire(PNoeudBinaire pnb, PArbreBinaire pab) {
  if (pnb) {
    detruire_noeud_binaire(pnb->gauche, pab);
    detruire_noeud_binaire(pnb->droit, pab);
    if (pab->copie)
      pab->detruire(pnb->data);
    free(pnb);
  }
}

void detruire_ab(PArbreBinaire pab) {
  detruire_noeud_binaire(pab->racine, pab);
  free(pab);
}

void afficher_ab_prefixe_rec(PNoeudBinaire pnb, PArbreBinaire pab) {
  if (pnb) {
    printf("( ");
    pab->afficher(pnb->data);
    afficher_ab_prefixe_rec(pnb->gauche,pab);
    afficher_ab_prefixe_rec(pnb->droit,pab);
    printf(") ");
  }
}
  
void afficher_ab_prefixe(PArbreBinaire pab) {
  afficher_ab_prefixe_rec(pab->racine,pab);
}

void afficher_ab_infixe_rec(PNoeudBinaire pnb, PArbreBinaire pab) {
  if (pnb) {
    printf("( ");
    afficher_ab_infixe_rec(pnb->gauche,pab);
    pab->afficher(pnb->data);
    afficher_ab_infixe_rec(pnb->droit,pab);
    printf(") ");
  }
}
  
void afficher_ab_infixe(PArbreBinaire pab) {
  afficher_ab_infixe_rec(pab->racine,pab);
}

void afficher_ab_postfixe_rec(PNoeudBinaire pnb, PArbreBinaire pab) {
  if (pnb) {
    printf("( ");
    afficher_ab_postfixe_rec(pnb->gauche,pab);
    afficher_ab_postfixe_rec(pnb->droit,pab);
    pab->afficher(pnb->data);
    printf(") ");
  }
}
  
void afficher_ab_postfixe(PArbreBinaire pab) {
  afficher_ab_postfixe_rec(pab->racine,pab);
}
 
void map_ab_prefixe_rec(PNoeudBinaire pnb, void (*fonction)(void *data, void *oa), void *optarg) {
  if (pnb) {
    fonction(pnb->data,optarg);
    map_ab_prefixe_rec(pnb->gauche,fonction, optarg);
    map_ab_prefixe_rec(pnb->droit,fonction, optarg);
  }
}
  
void map_ab_prefixe(PArbreBinaire pab, void (*fonction)(void *data, void *oa), void *optarg) {
  map_ab_prefixe_rec(pab->racine,fonction, optarg);
}

void map_ab_infixe_rec(PNoeudBinaire pnb, void (*fonction)(void *data, void *oa), void *optarg) {
  if (pnb) {
    map_ab_infixe_rec(pnb->gauche, fonction, optarg);
    fonction(pnb->data,optarg);
    map_ab_infixe_rec(pnb->droit, fonction, optarg);
  }
}

void map_ab_infixe(PArbreBinaire pab, void (*fonction)(void *data, void *oa), void *optarg) {
  map_ab_infixe_rec(pab->racine,fonction, optarg);
}

void map_ab_postfixe_rec(PNoeudBinaire pnb, void (*fonction)(void *data, void *oa), void *optarg) {
  if (pnb) {
    map_ab_postfixe_rec(pnb->gauche, fonction, optarg);
    map_ab_postfixe_rec(pnb->droit, fonction, optarg);
    fonction(pnb->data,optarg);
  }
}

void map_ab_postfixe(PArbreBinaire pab, void (*fonction)(void *data, void *oa), void *optarg) {
  map_ab_postfixe_rec(pab->racine,fonction, optarg);
}

/* Arbres binaires de recherche */

PNoeudBinaire ajouter_abr_rec(PNoeudBinaire pnb, PArbreBinaire pab,void *data) {
  if(pnb) {
    if (pab->comparer(pnb->data,data)>0) 
      pnb->gauche=ajouter_abr_rec(pnb->gauche,pab,data);
    else if (pab->comparer(pnb->data,data)<0) 
     pnb->droit=ajouter_abr_rec(pnb->droit,pab,data);
    return pnb;
  }
  else {
    return creer_noeud_binaire(pab, data);
  }
}
  
void ajouter_abr(PArbreBinaire pab,void *data) {
  pab->racine=ajouter_abr_rec(pab->racine,pab,data);
}

PNoeudBinaire chercher_abr_rec(PNoeudBinaire pnb, PArbreBinaire pab, void *data) {
  if(pnb) {
    if (pab->comparer(pnb->data,data)>0)
      return chercher_abr_rec(pnb->gauche,pab,data);
    else if (pab->comparer(pnb->data,data)<0)
      return chercher_abr_rec(pnb->droit,pab,data);
    else
      return pnb;
  }
  else
    return NULL;
}

PNoeudBinaire chercher_abr(PArbreBinaire pab, void *data) {
  return chercher_abr_rec(pab->racine,pab,data);
}

/* version de la fonction d'affichage s'appuyant sur la fonction map. Il faut commencer par "ajouter" optarg à des fonctions. Pour cela, on peut définir une nouvelle fonction générique... */

void afficher_optarg(void *data, void *optarg) {
  PArbreBinaire pab=(PArbreBinaire)optarg;
  pab->afficher(data);
  printf(" ");
}

void afficher_ab_prefixe_map(PArbreBinaire pab) {
  map_ab_prefixe(pab,&afficher_optarg,pab);
}
void afficher_ab_infixe_map(PArbreBinaire pab) {
  map_ab_infixe(pab,&afficher_optarg,pab);
}
void afficher_ab_postfixe_map(PArbreBinaire pab) {
  map_ab_postfixe(pab,&afficher_optarg,pab);
}

void lire_abr(PArbreBinaire pab, const char *nom_fichier) {
  FILE *f=fopen(nom_fichier,"r");
  if (f==NULL) {
    printf("Probleme lors de l'ouverture du fichier.\n");
    return;
  }
  pab->copie=0;
  void *data;
  while((data=pab->lire(f))) {
    ajouter_abr(pab,data);
  }
  fclose(f);
  pab->copie=1; // pour que la memoire allouee pendant la lecture soit liberee correctement a la fin...
}

void ecrire_ab_rec(PNoeudBinaire pnb, PArbreBinaire pab, FILE *f) {
  if (pnb) {
    pab->ecrire(pnb->data,f);
    fprintf(f,"\n");
    ecrire_ab_rec(pnb->gauche,pab,f);
    ecrire_ab_rec(pnb->droit,pab,f);
  }
}

void ecrire_ab(PArbreBinaire pab, const char *nom_fichier) {
  FILE *f=fopen(nom_fichier,"w");
  if (f==NULL) {
    printf("Probleme lors de l'ouverture du fichier.\n");
    return;
  }
  ecrire_ab_rec(pab->racine,pab,f);
  fclose(f);
}

typedef struct _arbre_binaire_file {
  PArbreBinaire pab;
  FILE *f;
} ArbreBinaireFile;

void ecrire_optarg(void *data, void *optarg) {
  ArbreBinaireFile *paf=(ArbreBinaireFile *)optarg;
  paf->pab->ecrire(data,paf->f);
  fprintf(paf->f,"\n");
}

void ecrire_ab_map(PArbreBinaire pab, const char *nom_fichier) {
  FILE *f=fopen(nom_fichier,"w");
  if (f==NULL) {
    printf("Probleme lors de l'ouverture du fichier.\n");
    return;
  }
  ArbreBinaireFile af={pab,f};
  map_ab_prefixe(pab,ecrire_optarg,&af);
  fclose(f);
}

void ecrire_ab_map_infixe(PArbreBinaire pab, const char *nom_fichier) {
  FILE *f=fopen(nom_fichier,"w");
  if (f==NULL) {
    printf("Probleme lors de l'ouverture du fichier.\n");
    return;
  }
  ArbreBinaireFile af={pab,f};
  map_ab_infixe(pab,ecrire_optarg,&af);
  fclose(f);
}

void ecrire_ab_map_postfixe(PArbreBinaire pab, const char *nom_fichier) {
  FILE *f=fopen(nom_fichier,"w");
  if (f==NULL) {
    printf("Probleme lors de l'ouverture du fichier.\n");
    return;
  }
  ArbreBinaireFile af={pab,f};
  map_ab_postfixe(pab,ecrire_optarg,&af);
  fclose(f);
}

