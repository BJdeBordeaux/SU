#include <stdarg.h>
#include <stdlib.h>
#include "liste.h"
#include "devel.h"

void inserer_debut(PListe pliste, void *data) {
  PElement newe=malloc(sizeof(Element));
  if (newe==NULL) {
    affiche_message("Erreur d'allocation");
  }
  newe->data=pliste->dupliquer(data);
  newe->suivant=pliste->elements;
  pliste->elements=newe;
}

void inserer_fin(PListe pliste, void *data){
  PElement newe=malloc(sizeof(Element));
  if (newe==NULL) {
    affiche_message("Erreur d'allocation");
  }
  newe->data=pliste->dupliquer(data);
  newe->suivant=NULL;
  
  PElement tmp=pliste->elements;
  if(tmp==NULL) {
    pliste->elements=newe;
  }
  else {
    while(tmp->suivant!=NULL)
      tmp=tmp->suivant;
    tmp->suivant=newe;
  }
}

void inserer_place(PListe pliste, void *data){  

  PElement newe=malloc(sizeof(Element));
  if (newe==NULL) {
    affiche_message("Erreur d'allocation");
  }
  newe->data=pliste->dupliquer(data);
  newe->suivant=NULL;
  
  PElement tmp=pliste->elements;

  // si la liste est vide: ajout immediat
  if((tmp==NULL)||(pliste->comparer(data, tmp->data)<0)) {
    newe->suivant=pliste->elements;
    pliste->elements=newe;
  }
  else {
    while(tmp->suivant!=NULL) {
      int comp=pliste->comparer(data,tmp->suivant->data);
      if (comp<=0) {
	// insertion avant le suivant
	newe->suivant=tmp->suivant;
	tmp->suivant=newe;
	return;
      }
      // sinon, on passe au suivant
      tmp=tmp->suivant;
    }
    // on est arrive a la fin sans trouver la bonne place: la bonne place est donc a la fin
    tmp->suivant=newe;
  }
  return;
}








PElement chercher_liste(PListe pliste, void *data) {
  PElement tmp=pliste->elements;
  while(tmp) {
    if (pliste->comparer(data, tmp->data)==0)
      return tmp;
    tmp=tmp->suivant;
  }
  return NULL;
}

PElement chercher_liste_triee(PListe pliste, void *data) {
  PElement tmp=pliste->elements;
  while(tmp) {
    int comp=pliste->comparer(data, tmp->data);
    if (comp==0)
      return tmp;
    if (comp<0)
      return NULL;
    tmp=tmp->suivant;
  }
  return NULL;

}

void detruire_liste(PListe pliste) {
  PElement tmp=pliste->elements;
  PElement tmp2;
  while (tmp) {
    tmp2=tmp->suivant;
    pliste->detruire(tmp->data);
    free(tmp);
    tmp=tmp2;
  }
  free(pliste);  
}

void afficher_liste(PListe pliste) {
  PElement tmp=pliste->elements;
  while (tmp) {
    pliste->afficher(tmp->data);
    printf("\n");
    tmp=tmp->suivant;
  }
}

int ecrire_liste(PListe pliste, const char *nom_fichier) {
  FILE *f=fopen(nom_fichier,"w");
  if (f==NULL) {
    printf("Erreur lors de l'ouverture du fichier %s\n",nom_fichier);
    return 0;
  }
  PElement tmp=pliste->elements;
  while (tmp) {
    pliste->ecrire(tmp->data,f);
    fprintf(f,"\n");
    tmp=tmp->suivant;
  }
  fclose(f);
  return 1;
}

int lire_liste(PListe pliste, const char * nom_fichier) {
  FILE *f=fopen(nom_fichier, "r");
  if (f==NULL) {
    printf("Erreur lors de l'ouverture du fichier %s\n",nom_fichier);
    return 0;
  }
  void *data=pliste->lire(f);
  while(data!=NULL) {
    inserer_fin(pliste,data);
    free(data);
    data=pliste->lire(f);
  }
  fclose(f);
  return 1;
}


void ajouter_liste(PListe pliste, int nb_data, ...) {
  va_list args;
  va_start(args,nb_data);
  int i;
  for (i=0;i<nb_data;i++) {
    void *data=va_arg(args,void *);
    inserer_fin(pliste,data);
  }
  va_end(args);
}

void map(PListe pliste, void (*fonction)(void *data, void *oa), void *optarg) {
  PElement elt=pliste->elements;
  while(elt) {
    fonction(elt->data,optarg);
    elt=elt->suivant;
  }
}


PElement extraire_en_tete(PListe pl) {
  if (pl->elements==NULL) return NULL;
  PElement tete=pl->elements;
  pl->elements = tete->suivant;
  tete->suivant=NULL;
  return tete;
}
