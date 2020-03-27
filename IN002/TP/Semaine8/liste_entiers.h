typedef struct _cellule_t cellule_t;

struct _cellule_t {
  int donnee;
  cellule_t *suivant;
};

cellule_t * creerListe(int n);

void AfficherListeInt(cellule_t *l);
int nb_occurrence(int val, cellule_t *l);
int tous_plus_grand(int val, cellule_t *l);
cellule_t *Maximum(cellule_t *l);
int Renvoyer_val_pos(int pos, cellule_t *l);
cellule_t *Concatener_it(cellule_t *l1, cellule_t *l2);
int nb_maximum(cellule_t *l);