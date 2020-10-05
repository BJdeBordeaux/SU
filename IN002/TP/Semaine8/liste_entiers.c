#include <stdio.h>
#include <stdlib.h>
#include "liste_entiers.h"

cellule_t * creerListe(int n) {
/* cree une liste de n entiers saisi par l'utilisateur
  renvoie l'adresse du premier element de la liste */
  int i;
  int val;
  cellule_t *tete=NULL;
  cellule_t *ptr;
  
  printf("Saisie des %d elements de la liste\n",n);
  for (i=0; i < n; i++) {
    printf("Element %d :",i+1);
    scanf("%d",&val);
    ptr=malloc(sizeof(cellule_t));
    ptr->donnee = val;
    ptr->suivant = tete;
    tete = ptr;
  }
  return tete;
}

cellule_t * creerCellule(int n, cellule_t *l) {
/* cree une cellule d'une liste*/
  cellule *res = malloc(sizeof(cellule_t));
  int res->donnee = i;
  int res->suivant;
  return res;
}

void AfficherListeInt(cellule_t *l){
    // int cpt = 1;
    cellule_t *cur_l = l;
    while(cur_l != NULL){
        printf("Le element courant: %d\n", cur_l->donnee);
        cur_l = cur_l->suivant;
        // cpt++;
    }
}

int nb_occurrence(int val, cellule_t *l){
    int cpt = 0;
    cellule_t *cur_l = l;
    while(cur_l != NULL){
      if(cur_l->donnee == val){cpt++;}
      cur_l = cur_l->suivant;
    }
    return cpt;
}

int tous_plus_grand(int val, cellule_t *l){
    cellule_t *cur_l = l;
    while(cur_l != NULL){
      if(cur_l->donnee < val){return 0;}
      cur_l = cur_l->suivant;
    }
    return 1;
}

cellule_t *Maximum(cellule_t *l){
    cellule_t *cur_l = l;
    cellule_t *res_l = l;
    int max_d = cur_l->donnee;
    while(cur_l != NULL){
      if(cur_l->donnee > max_d){
        max_d = cur_l->donnee;
        res_l = cur_l;
        // res_l->suivant = cur_l->suivant;
        // printf("marque %d\n",2);
        // AfficherListeInt(res_l);
        // printf("marque %d\n",2);
      }
      cur_l = cur_l->suivant;
    }
    // AfficherListeInt(res_l);
    // printf("marque %d\n",1);
    return res_l;
}

int Renvoyer_val_pos(int pos, cellule_t *l){
    cellule_t *cur_l = l;
    while(pos > 0){
      cur_l = cur_l->suivant;
      pos--;
    }
    return cur_l->donnee;
}

cellule_t *Concatener_it(cellule_t *l1, cellule_t *l2){
    if(l1 == NULL){
      return l2;
    }else if(l2 == NULL){
      return l1;
    }

    cellule_t *cur_l = l1;
    cellule_t *res = cur_l;
    while(cur_l->suivant != NULL){
      cur_l = cur_l->suivant;
    }
    cur_l->suivant = l2;
    return res;
}

int nb_maximum(cellule_t *l){
    if(l== NULL){return 0;}
    cellule_t *cur_l = l;
    int cpt = 0;
    int max_v = cur_l->donnee;
    while(cur_l != NULL){
      if(cur_l->donnee > max_v){
        max_v = cur_l->donnee;
        cpt = 1;
      }else if(cur_l->donnee == max_v){cpt++;}
      cur_l = cur_l->suivant;
    }
    return cpt;
}