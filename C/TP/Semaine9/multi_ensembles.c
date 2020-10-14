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
  if(!ptr){printf("NULL\n");}
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

int taille(element_t *e){
  int r = 0;
  while(e){
    e = e->suivant;
    r++;
  }
  return r;
}

element_t *Supprime_frequence_inf_seuil(element_t *e, int seuil){
  if(!e->suivant && e->frequence<=seuil){
    return NULL;
  }
  element_t *tem=e;
  element_t *d;
  while(tem->suivant){
    if(tem->suivant->frequence<=seuil){
      printf("before tem->suivant: v=%d,f=%d\n",tem->suivant->valeur,tem->suivant->frequence);
      d = tem->suivant;
      tem->suivant = tem->suivant->suivant;
      free(d);
      // if(tem->suivant){printf("after tem->suivant: v=%d,f=%d\n",tem->suivant->valeur,tem->suivant->frequence);}
    }else{
      tem = tem->suivant;
    }
  }
  return e;
}

int Inclus_rec(element_t *e1, element_t *e2){
  if(!e1){return 1;}
  else if(!e2){return 0;}
  else if(e1->valeur != e2->valeur || e1->frequence < e2->frequence){return 0;}
  else{return Inclus_rec(e1->suivant,e2->suivant);}
}

element_t *Union(element_t *e1, element_t *e2){
  if(!e1){return e2;}
  if(!e2){return e1;}
  element_t *r = NULL;
  while(e1 || e2){
    if((!e2 && e1) || (e2 && e1 && e1->valeur < e2->valeur)){
      r = Ajout_tete_ensemble(r, e1->valeur, e1->frequence);
      e1 = e1->suivant;
    }else if((!e1 && e2) || (e2 && e1 && e2->valeur < e1->valeur)){
      r = Ajout_tete_ensemble(r, e2->valeur, e2->frequence);
      e2 = e2->suivant;
    }else{
      r = Ajout_tete_ensemble(r, e1->valeur, e1->frequence + e2->frequence);
      e1 = e1->suivant;
      e2 = e2->suivant;
    }
  }
  return r;
}

element_t *Ajout_suivant(element_t *e, int val, int freq){
  element_t *new = Ajout_tete_ensemble(NULL, val, freq);
  if(!e){return new;}
  element_t *suivant = e->suivant;
  e->suivant = new;
  new->suivant = suivant;
  return e;
}

element_t *Union_triee(element_t *e1, element_t *e2){
  if(!e1){return e2;}
  if(!e2){return e1;}
  element_t *r = malloc(sizeof(element_t));
  if(e1->valeur < e2->valeur){
    r = Ajout_tete_ensemble(NULL, e1->valeur, e1->frequence);
    e1 = e1->suivant;
  }else if(e1->valeur > e2->valeur){
    r = Ajout_tete_ensemble(NULL, e2->valeur, e2->frequence);
    e2 = e2->suivant;
  }else{
    r = Ajout_tete_ensemble(NULL, e1->valeur, e1->frequence + e2->frequence);
    e1 = e1->suivant;
    e2 = e2->suivant;
  }
  element_t *tem = r;
  while(e1 || e2){
    //if we code as while(e1 || e2)
    //...if(!e2 || e1->valeur < e2->valeur)
    //and delete the while outside the circle
    //a segmentation fault will be reported
    //just consider the situation of e1 == NULL and e2 !=NULL
    if((!e2 && e1)|| (e1 && e2 && e1->valeur < e2->valeur)){
      tem = Ajout_suivant(tem, e1->valeur, e1->frequence);
      e1 = e1->suivant;
    }else if((e2 && !e1)|| (e1 && e2 && e2->valeur < e1->valeur)){
      tem = Ajout_suivant(tem, e2->valeur, e2->frequence);
      e2 = e2->suivant;
    }else{
      tem = Ajout_suivant(tem, e1->valeur, e1->frequence + e2->frequence);
      e1 = e1->suivant;
      e2 = e2->suivant;
    }
    tem = tem->suivant;
  }
  return r;
}

element_t *Union_triee_rec(element_t *e1, element_t *e2){
  if(!e1 && !e2){
    return NULL;
  }
  if(!e1){
    return Ajout_tete_ensemble(Union_triee_rec(e1, e2->suivant), e2->valeur, e2->frequence);
  }else if(!e2){
    return Ajout_tete_ensemble(Union_triee_rec(e1->suivant,e2), e1->valeur, e1->frequence);
  }else if(e1->valeur < e2->valeur){
    return Ajout_tete_ensemble(Union_triee_rec(e1->suivant, e2), e1->valeur, e1->frequence);
  }else if(e2->valeur < e1->valeur){
    return Ajout_tete_ensemble(Union_triee_rec(e1, e2->suivant), e2->valeur, e2->frequence);
  }else{
    return Ajout_tete_ensemble(Union_triee_rec(e1->suivant, e2->suivant), e2->valeur, e2->frequence + e1->frequence);
  }
}

element_t *Intersection_triee_rec(element_t *e1, element_t *e2){
  if(!e1 || !e2){
    return NULL;
  }else if(e1->valeur < e2->valeur){
    return Intersection_triee_rec(e1, e2->suivant);
  }else if(e2->valeur > e1->valeur){
    return Intersection_triee_rec(e1->suivant, e2);
  }else{
    return Ajout_tete_ensemble(Intersection_triee_rec(e1->suivant,e2->suivant), e1->valeur, min(e1->frequence, e2->frequence));
  }
}
//if we code a recursive function, the list should be added on head

element_t *Intersection_triee(element_t *e1, element_t *e2){
  if(!e1 || !e2){return NULL;}
  element_t *r = NULL;
  element_t *t = NULL;
  while(!r || (e1 && e2)){
    if(e1->valeur < e2->valeur){
      e1 = e1->suivant;
    }else if(e1->valeur > e2->valeur){
      e2 = e2->suivant;
    }else{
      if(!r){
        r = Ajout_tete_ensemble(r, e1->valeur, min(e1->frequence, e2->frequence));
        t = r;
      }else{
        t = Ajout_suivant(t, e1->valeur, min(e1->frequence, e2->frequence));
      }
      e1 = e1->suivant;
      e2 = e2->suivant;
    }
  }
  // printf("marque %d\n",0);
  return r;
}

element_t *Difference_triee_rec(element_t *e1, element_t *e2){
  if(!e1){
    return NULL;
  }else if(!e2){
    return e1;
  }else if(e1->valeur > e2->valeur){
    return Difference_triee_rec(e1, e2->suivant);
  }else if(e1->valeur == e2->valeur){
    if(e1->frequence > e2->frequence){
      return Ajout_tete_ensemble(Difference_triee_rec(e1->suivant, e2->suivant), e1->valeur, e1->frequence - e2->frequence);
    }else if(e1->frequence <= e2->frequence){
      return Difference_triee_rec(e1->suivant, e2->suivant);
    }
  }else if(e1->valeur < e2->valeur){
    return Ajout_tete_ensemble(Difference_triee_rec(e1->suivant, e2), e1->valeur, e1->frequence);
  }
}


element_t *Difference_triee(element_t *e1, element_t *e2){
  if(!e1){
    return e2;
  }else if(!e2){
    return e1;
  }
  element_t *r = NULL;
  while(!r){
    if(e1->valeur < e2->valeur){
      r = Ajout_tete_ensemble(NULL, e1->valeur, e1->frequence);
      e1 = e1->suivant;
    }else if(e1->valeur > e2->valeur){
      e2 = e2->suivant;
    }else{
      if(e1->frequence > e2->frequence){
        r = Ajout_tete_ensemble(r, e1->valeur, e1->frequence - e2->frequence);
      }
      e1 = e1->suivant;
      e2 = e2->suivant;
    }
  }
  element_t *t = r;
  int v1, v2, f1, f2;
  while(e1){
    if(!e2 || e1->valeur < e2->valeur){
      t = Ajout_suivant(t, e1->valeur, e1->frequence);
      e1 = e1->suivant;
    }else{
      v1 = e1->valeur, v2 = e2->valeur, f1 = e1->frequence; f2 = e2->frequence;
      if(e1->valeur > e2->valeur){
        e2 = e2->suivant;
      }else{
        if(f1>f2){
          // printf("marque %d\n",0);
          t = Ajout_suivant(t,v1, f1 - f2);
        }
        e1 = e1->suivant;
        e2 = e2->suivant;
      }
    }
  }
  return r;
}

int min(int a, int b){
  if(a>=b){return b;}
  else {return a;}
}

element_t *Xor_triee(element_t *e1, element_t *e2){
  element_t *r1 = Difference_triee_rec(e1, e2);
  element_t *r2 = Difference_triee_rec(e2, e1);
  return Union_triee(r1, r2);
}

void Detruire(element_t *l){
  element_t *t = l;
  while(l){
    // element_t *t = l;
    printf("free: l->d %d\n",l->valeur);
    l = l->suivant;
    free(t);
    t = l;
    if(!t){printf("t = NULL\n");}
  }
}