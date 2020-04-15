typedef struct _element_t element_t;
struct _element_t{
  int valeur;
  int frequence;
  element_t *suivant;
};


element_t *Recherche_val(element_t *ensemble, int val);
element_t *Ajout_tete_ensemble(element_t *ensemble, int val, int freq);
void Affiche_ensemble(element_t *ensemble);
element_t * Creation_ensemble(int n);
element_t *Supprime_total_element_ensemble(element_t *ensemble, int val);
element_t *Supprime_element_ensemble(element_t *ensemble, int val);
element_t *Ajout_ensemble_trie(element_t *ensemble, int val, int freq);
element_t *Supprime_element_ensemble_trie(element_t *ensemble, int val);
element_t *Supprime_total_ensemble_trie(element_t *ensemble, int val);
int Inclus(element_t *e1, element_t *e2);
int Intersection_vide(element_t *e1, element_t *e2);
int taille(element_t *e);
element_t *Supprime_frequence_inf_seuil(element_t *e, int seuil);
int Inclus_rec(element_t *e1, element_t *e2);
element_t *Union(element_t *e1, element_t *e2);
element_t *Ajout_suivant(element_t *e, int val, int freq);
element_t *Union_triee(element_t *e1, element_t *e2);
element_t *Union_triee_rec(element_t *e1, element_t *e2);
element_t *Intersection_triee_rec(element_t *e1, element_t *e2);
element_t *Intersection_triee(element_t *e1, element_t *e2);
element_t *Difference_triee(element_t *e1, element_t *e2);
element_t *Difference_triee_rec(element_t *e1, element_t *e2);
int min(int a, int b);
element_t *Xor_triee(element_t *e1, element_t *e2);
void Detruire(element_t *l);
