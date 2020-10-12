#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecosys.h"

/* PARTIE 1*/
/* Fourni: Part 1, exercice 3, question 2 */
Animal *creer_animal(int x, int y, float energie) {
  Animal *na = (Animal *)malloc(sizeof(Animal));
  assert(na);
  na->x = x;
  na->y = y;
  na->energie = energie;
  na->dir[0] = rand() % 3 - 1;
  na->dir[1] = rand() % 3 - 1;
  na->suivant = NULL;
  return na;
}


/* Fourni: Part 1, exercice 3, question 3 */
Animal *ajouter_en_tete_animal(Animal *liste, Animal *animal) {
  assert(animal);
  assert(!animal->suivant);
  animal->suivant = liste;
  return animal;
}

/* A faire. Part 1, exercice 5, question 1 */
void ajouter_animal(int x, int y,  float energie, Animal **liste_animal) {
  assert(x < SIZE_X && x > 0);
  assert(y < SIZE_Y && y > 0);
  Animal *a = creer_animal(x, y, energie);
  liste_animal[x][y] = *a;
}

/* A Faire. Part 1, exercice 5, question 5 */
// void enlever_animal(Animal **liste, Animal *animal) {
//   if(*liste){
//     Animal *tmp = (*liste)->suivant;
//     if(*liste == animal){
//       free(liste);
//       *liste = tmp;
//     }else{
//       if(tmp == animal){
//         (*liste)->suivant = tmp->suivant;
//         free(tmp);
//       }else if(tmp->suivant){
//         Animal *na = tmp->suivant;
//         while(na){
//           if(na == animal){
//             tmp->suivant = na->suivant;
//             free(na);
//           }
//           tmp = tmp->suivant;
//           na = na->suivant;
//         }
//       }
//     }
//   }
// }

void enlever_animal(Animal **liste, Animal *animal) {
  if(*liste){
    Animal *tmp = *liste;
    if(*liste == animal){
      *liste = (*liste)->suivant;
      free(tmp);
    }else{
      Animal *na = tmp->suivant;
      while(na){
        if(na == animal){
          tmp->suivant = na->suivant;
          free(na);
        }
        tmp = tmp->suivant;
        na = na->suivant;
      }
    }
  }
}

/* A Faire. Part 1, exercice 5, question 2 */
Animal* liberer_liste_animaux(Animal *liste) {
   /*A Completer*/
  if(!liste){
    return NULL;
  }

  Animal *tmp;
  while(liste){
    tmp = liste->suivant;
    free(liste);
    liste = tmp;
  }
  return NULL;
}

/* Fourni: part 1, exercice 3, question 4 */
unsigned int compte_animal_rec(Animal *la) {
  if (!la) return 0;
  return 1 + compte_animal_rec(la->suivant);
}

/* Fourni: part 1, exercice 3, question 4 */
unsigned int compte_animal_it(Animal *la) {
  int cpt=0;
  while (la) {
    ++cpt;
    la = la->suivant;
  }
  return cpt;
}



/* Part 1. Exercice 4, question 1 */
void afficher_ecosys(Animal *liste_proie, Animal *liste_predateur) {
  unsigned int i, j;
  char ecosys[SIZE_X][SIZE_Y];
  int nbpred=0,nbproie=0;
  Animal *pa=NULL;
  /* on initialise le tableau */
  for(i = 0; i<SIZE_Y; i++){
    for(j = 0; j<SIZE_X; j++){
      ecosys[j][i] = ' ';
    }
  }

  int x, y;
  /* on ajoute les proies */
  Animal *tmp = liste_proie;
  while(tmp){
    // strcpy(ecosys[x][y], 'O');
    ecosys[tmp->x][tmp->y] = '*';
    tmp = tmp->suivant;
  }

  /* on ajoute les predateurs */
  tmp = liste_predateur;
  while(tmp){
    if(ecosys[tmp->x][tmp->y] == ' ')
      // {strcpy(ecosys[tmp->x][tmp->y], 'O');}
      {ecosys[tmp->x][tmp->y] = 'O';}
    else
      // {strcpy(ecosys[tmp->x][tmp->y], '@');}
      {ecosys[tmp->x][tmp->y] = '@';}
    tmp = tmp->suivant;
  }

  /* on affiche le tableau */
  printf("+");
  for(i = 0; i<SIZE_X; i++){
    printf("-");
  }
  printf("+\n");

  for(i = 0; i<SIZE_Y; i++){
    printf("|");
    for(j = 0; j<SIZE_X; j++){
      printf("%c",ecosys[j][i]);
    }
    printf("|\n");
  }

  printf("+");
  for(i = 0; i<SIZE_X; i++){
    printf("-");
  }
  printf("+\n");


}


void clear_screen() {
  printf("\x1b[2J\x1b[1;1H");  /* code ANSI X3.4 pour effacer l'ecran */
}

/* PARTIE 2*/

/* Part 2. Exercice 5, question 1 */
void bouger_animaux(Animal *la) {
    /*A Completer*/

}

/* Part 2. Exercice 5, question 3 */
void reproduce(Animal **liste_animal, float p_reproduce) {
   /*A Completer*/

}


/* Part 2. Exercice 7, question 1 */
void rafraichir_proies(Animal **liste_proie, int monde[SIZE_X][SIZE_Y]) {
    /*A Completer*/

}

/* Part 2. Exercice 8, question 1 */
Animal *animal_en_XY(Animal *l, int x, int y) {
    /*A Completer*/

  return NULL;
} 

/* Part 2. Exercice 8, question 2 */
void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie) {
   /*A Completer*/

}

/* Part 2. Exercice 6, question 2 */
void rafraichir_monde(int monde[SIZE_X][SIZE_Y]){

   /*A Completer*/


}

