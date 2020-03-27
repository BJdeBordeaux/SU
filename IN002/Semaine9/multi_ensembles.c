#include <stdio.h>
#include <stdlib.h>
#include "multi_ensembles.h"

  
/* Retourne un pointeur sur le premier element de valeur val, retourne NULL si aucun �l�ment n'a la valeur val */
element_t * Recherche_val(element_t *ensemble, int val) {
  element_t *res = ensemble;
  while(res != NULL){
    if(res->valeur == val){
      return res;
    }
    res = res->suivant;
  }
  return NULL;
}

/* Ajoute l'element val en tete de l'ensemble s'il n'apparait pas dans l'ensemble, augmente sa frequence de 1 sinon */
element_t * Ajout_tete_ensemble(element_t *ensemble, int val, int freq) {
  element_t *tem = Recherche_val(ensemble, val);
  if(tem){
    tem->frequence += freq;
    return ensemble;
  }else{
    element_t *tete = (element_t*) malloc(sizeof(element_t));
    tete->valeur = val;
    tete->frequence = freq;
    tete->suivant = ensemble;
    return tete;
  }
}


/* Affche tous les elements d'un ensemble avec leur frequence */
void Affiche_ensemble(element_t *ensemble) {
  element_t *ptr = ensemble;
  
  while (ptr != NULL) {
    printf("val : %d, frequence : %d\n",ptr->valeur,ptr->frequence);
    ptr=ptr->suivant;
  }
}

/* Saisie des n elements d'un ensemble */
element_t * Creation_ensemble(int n) {
  element_t *ensemble=NULL;
  
  int i = 0;
  int val;
  
  for (i=0; i < n; i++) {
    printf("Saisie d'un entier: ");
    scanf("%d",&val);
    ensemble=Ajout_tete_ensemble(ensemble,val,1);
  }
  return ensemble;
}

element_t *Supprime_total_element_ensemble(element_t *ensemble, int val){
  if(ensemble == NULL){
    return NULL;
  }
  if (ensemble->valeur == val){
    return ensemble->suivant;
  }
  element_t *tem = ensemble;
  element_t *next = ensemble->suivant;
  while(next != NULL){
    // printf("marque %d, n_v %d, t_v %d\n",2, next->valeur, tem->valeur);
    if(next->valeur == val){
      tem->suivant = next->suivant;
      // printf("marque %d\n",1);
      free(next);
      return ensemble;
    }
    next = next->suivant;
    tem = tem->suivant;
  }
  return ensemble;
}

element_t *Supprime_element_ensemble(element_t *ensemble, int val){
  if(ensemble == NULL){
    return NULL;
  }
  if (ensemble->valeur == val){
    if(ensemble->frequence == 1){
      return ensemble->suivant;
    }else{
      ensemble->frequence -= 1;
      return ensemble;
    }
  }
  element_t *tem = ensemble;
  element_t *next = ensemble->suivant;
  while(next != NULL){
    if(next->valeur == val){
      if(next->frequence == 1){
        tem->suivant = next->suivant;
        free(next);
        return ensemble;
      }else{
        next->frequence -= 1;
        return ensemble;
      }
    }
    next = next->suivant;
    tem = tem->suivant;
  }
  return ensemble;
}

element_t *Ajout_ensemble_trie(element_t *ensemble, int val, int freq){
  if(ensemble == NULL){
    return Ajout_tete_ensemble(ensemble, val, freq);
  }else if(val < ensemble->valeur){
    return Ajout_tete_ensemble(ensemble, val, freq);
  }
  element_t *tem = Recherche_val(ensemble, val);
  if(tem){
    tem->frequence += freq;
    return ensemble;
  }
  tem = ensemble;
  element_t *next = ensemble->suivant;
  while(next != NULL && tem->valeur < val){
    if(next->valeur > val){
      next = Ajout_tete_ensemble(next, val, freq);
      tem->suivant = next;
      return ensemble;
    }
    next = next->suivant;
    tem = tem->suivant;
  }
  next = Ajout_tete_ensemble(next, val, freq);
  tem->suivant = next;
  return ensemble;
}

element_t *Supprime_element_ensemble_trie(element_t *ensemble, int val){
  if(ensemble == NULL){
    return NULL;
  }else if(ensemble->valeur == val){
    return NULL;
  }
  element_t *tem = ensemble;
  element_t *next = ensemble->suivant;
  while(next != NULL){
    if(val< next->valeur){
      next = next->suivant;
      tem = tem->suivant;
    }else if(val == next->valeur){
      if(next->frequence == 1){
        tem->suivant = next->suivant;
        free(next);
        return ensemble;
      }else{
        next->frequence--;
        return ensemble;
      }
    }
  }
  return ensemble;
}
element_t *Supprime_total_ensemble_trie(element_t *ensemble, int val){
  if(ensemble == NULL){
    return NULL;
  }else if(ensemble->valeur == val){
    return NULL;
  }
  element_t *tem = ensemble;
  element_t *next = ensemble->suivant;
  while(next != NULL){
    if(val< next->valeur){
      next = next->suivant;
      tem = tem->suivant;
    }
    if(val == next->valeur){
        tem->suivant = next->suivant;
        free(next);
        return ensemble;
    }
  }
  return ensemble;
}

int Inclus(element_t *e1, element_t *e2){
  if(e1 == NULL){
    return 1;
  }else if(e2 == NULL){
    return 0;
  }
  element_t *t1 = e1, *t2 = e2;
  while(t1 != NULL && t2 != NULL){
    if(t1->valeur < t2->valeur){
      return 0;
    }else if(t1->valeur == t2->valeur){
      if(t1->frequence < t2->frequence){
        return 0;
      }
      t1 = t1->suivant;
      t2 = t2->suivant;
    }else{
      t2 = t2->suivant;
    }
  }
  if(t1 == NULL){
    return 1;
  }else{
    return 0;
  }
  
}

int Intersection_vide(element_t *e1, element_t *e2){
  if(e1 == NULL || e2 == NULL){
    return 1;
  }
  element_t *t1 = e1, *t2 = e2;
  while(t1 != NULL && t2 != NULL){
    if(t1->valeur < t2->valeur){
      t1 = t1->suivant;
    }else if(t1->valeur == t2->valeur){
      return 0;
    }else{
      t2 = t2->suivant;
    }
  }
  return 1;
}