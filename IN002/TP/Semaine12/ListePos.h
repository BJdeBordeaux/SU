
#ifndef _LISTEPOS_H_
#define _LISTEPOS_H_ 


typedef struct _cellule_t cellule_t;
struct _cellule_t{
  int i,j;
  int val;
  cellule_t *suivant;
};


cellule_t *Creer_cellule(int i, int j, int val);
cellule_t *Inserer(int i, int j, cellule_t *liste, int val);
cellule_t *Trier_liste_decrois(cellule_t *liste);

cellule_t *Max_liste(cellule_t *liste);

void Afficher_liste(cellule_t *liste);

cellule_t *Detruire_liste(cellule_t *liste);
int Est_dans_liste(cellule_t *liste, int i, int j);


#endif
