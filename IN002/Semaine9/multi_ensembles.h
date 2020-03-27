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