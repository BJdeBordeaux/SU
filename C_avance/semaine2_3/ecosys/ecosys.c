#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecosys.h"
#define PP printf("here")


float p_ch_dir=0.01;
int gain_energie_proie=6;
int gain_energie_predateur=20;
float p_reproduce_proie=0.4;
float p_reproduce_predateur=0.5;
int temps_repousse_herbe=-15;
float p_manger = 1;



/* PARTIE 1*/
/* Fourni: Part 1, exercice 3, question 2 */
Animal *creer_animal(int x, int y, float energie){
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
  ajouter_en_tete_animal(*liste_animal, a);
}

/* A Faire. Part 1, exercice 5, question 5 */

void enlever_animal(Animal **liste, Animal *animal) {
  Animal *current;
  if (*liste == NULL || animal == NULL) return;
  while ((current = *liste) != NULL && current->suivant != animal &&
         *liste != animal) {
    liste = &current->suivant;
  }
  *liste = current->suivant;
  free(current);
}


/* A Faire. Part 1, exercice 5, question 2 */

Animal* liberer_liste_animaux(Animal *liste) {
   /*A Completer*/
  Animal *tmp;
  Animal *nxt = liste;
  while((tmp = nxt) != NULL){
    nxt = tmp->suivant;
    free(tmp);
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
  unsigned int cpt=0;
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

  /* on ajoute les proies */
  pa= liste_proie;
  while(pa){
    nbproie++;
    assert(pa->x >= 0 && pa->y >= 0 && pa->x <= SIZE_X && pa->y <= SIZE_Y);
    ecosys[pa->x][pa->y] = '*';
    pa = pa->suivant;
  }

  /* on ajoute les predateurs */
  pa = liste_predateur;
  while(pa){
    nbpred++;
    assert(pa->x >= 0 && pa->y >= 0 && pa->x <= SIZE_X && pa->y <= SIZE_Y);
    if(ecosys[pa->x][pa->y] == ' ' || ecosys[pa->x][pa->y] == 'O')
      {ecosys[pa->x][pa->y] = 'O';}
    else
      {ecosys[pa->x][pa->y] = '@';}
    // if(ecosys[pa->x][pa->y] == '@' || ecosys[pa->x][pa->y] == '*')
    //   {ecosys[pa->x][pa->y] = '@';}
    // else
    //   {ecosys[pa->x][pa->y] = 'O';}
    pa = pa->suivant;
  }

  /* on affiche le tableau */
  printf("+");
  for(j = 0; j<SIZE_Y; j++){
    printf("-");
  }
  printf("+\n");

  for(i = 0; i<SIZE_X; i++){
    printf("|");
    for(j = 0; j<SIZE_Y; j++){
      printf("%c",ecosys[i][j]);
    }
    printf("|\n");
  }

  printf("+");
  for(j = 0; j<SIZE_Y; j++){
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
  while(la){

    if(rand()*1./RAND_MAX < p_ch_dir){
    	int a = la->dir[0];
    	int b = la->dir[1];
    	while(a == la->dir[0] && b == la->dir[1]){
    		la->dir[0] = (la->dir[0] - 1)%3;
      		la->dir[1] = (la->dir[1] - 1)%3;
    	}
    }
    la->x += la->dir[0];
    if(la->x >= SIZE_X){la->x -= SIZE_X;}
    else if(la->x < 0){la->x += SIZE_X;}
    la->y += la->dir[1];
    if(la->y >= SIZE_Y){la->y -= SIZE_Y;}
    else if(la->y < 0){la->y += SIZE_Y;}
    assert(la->x >= 0 && la->y >= 0 && la->x <= SIZE_X && la->y <= SIZE_Y);
    la = la->suivant;
  }
}

/* Part 2. Exercice 5, question 3 */
void reproduce(Animal **liste_animal, float p_reproduce) {
   /*A Completer*/
  if(liste_animal){
    Animal *ani = *liste_animal;
    while(ani != NULL){
      if(rand()*1./RAND_MAX < p_reproduce){
          Animal *enfant = creer_animal(ani->x, ani->y, ani->energie/2);
          ani->energie /= 2;
          *liste_animal = ajouter_en_tete_animal(*liste_animal, enfant);
      }
      ani = ani->suivant;
    }    
  }

}


/* Part 2. Exercice 7, question 1 */
void rafraichir_proies(Animal **liste_proie, int monde[SIZE_X][SIZE_Y]) {
  if(liste_proie != NULL){
    Animal *a = *liste_proie;
    bouger_animaux(a); 
    a = *liste_proie;
    while(a){
      a->energie -= 1;
      if(monde[a->x][a->y] >= 0){
        a->energie += gain_energie_proie;
        monde[a->x][a->y] = temps_repousse_herbe;
      }
      if(a->energie < 0){
        Animal *tem = a;
        a = a->suivant;
        enlever_animal(liste_proie, tem);
      }else{
        a = a->suivant;
      } 
    }    
  }
}

/* Part 2. Exercice 8, question 1 */
Animal *animal_en_XY(Animal *l, int x, int y) {
  while(l != NULL){
    if(l->x == x && l->y == y){
      return l;
    }
    l = l->suivant;
  }
  return NULL;
} 

/* Part 2. Exercice 8, question 2 */
void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie) {
  if(liste_predateur != NULL){
    Animal *a = *liste_predateur;
    bouger_animaux(a);
    a = *liste_predateur;
    Animal *b;
    while(a != NULL){
      a->energie -= 1;
      if(liste_proie != NULL){
        b=animal_en_XY(*liste_proie, a->x, a->y);
        if((b != NULL)&& rand()*1./RAND_MAX < p_manger){
          a->energie += gain_energie_predateur;
          enlever_animal(liste_proie, b);
        }  
      }
      
      if(a->energie < 0){
        Animal *tem = a;
        a = a->suivant;
        enlever_animal(liste_predateur, tem);
      }else{
        a = a->suivant;
      } 
    }  
  }
  
}

/* Part 2. Exercice 6, question 2 */
void rafraichir_monde(int monde[SIZE_X][SIZE_Y]){
  int i, j;
  for(i = 0; i < SIZE_X; i++){
    for(j = 0; j < SIZE_Y; j++){
      monde[i][j]++;
    }
  }
}

