#ifndef _ECOSYS_H_
#define _ECOSYS_H_

#define SIZE_X 20
#define SIZE_Y 50


extern float p_ch_dir;
extern int gain_energie_proie;
extern int gain_energie_predateur;
extern float p_reproduce_proie;
extern float p_reproduce_predateur;
extern int temps_repousse_herbe;

typedef struct _animal {
  int x;
  int y;
  int dir[2]; /* direction courante sous la forme (dx, dy) */
  float energie;
  struct _animal *suivant;
} Animal;


Animal *creer_animal(int x, int y, float energie);
Animal *ajouter_en_tete_animal(Animal *liste, Animal *animal);
unsigned int compte_animal_rec(Animal *la);
unsigned int compte_animal_it(Animal *la);

void ajouter_animal(int x, int y, float energie, Animal **liste_animal);
void enlever_animal(Animal **liste, Animal *animal);
Animal* liberer_liste_animaux(Animal *liste);
void afficher_ecosys(Animal *liste_predateur, Animal *liste_proie);



void bouger_animaux(Animal *la);
Animal *animal_en_XY(Animal *l, int x, int y);
void reproduce(Animal **liste_animal, float p_reproduce);
void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie);
void rafraichir_proies(Animal **liste_proie, int monde[SIZE_X][SIZE_Y]) ;
void rafraichir_monde(int monde[SIZE_X][SIZE_Y]);

void clear_screen();

#endif
