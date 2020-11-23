#include <stdlib.h>
#include <string.h>
#include "liste.h"
#include "abr.h"

/* decoupe liste */
Lm_mot *part_Lmot(Lm_mot **pl)
{
  int nbm = taille_Lmot(*pl);
  Lm_mot *p = *pl;
  Lm_mot *pivot;

  if (nbm < 3)
    {
      *pl = NULL;
      return p;
    }

  nbm /= 2;
  for(p = *pl; nbm-- > 1; p = p->suiv);

  pivot = p->suiv;
  p->suiv = NULL;

  return pivot;
}

/* Creation de l ABR, destruction de la liste*/
Nd_mot *Lm2abr(Lm_mot *l)
{
  Lm_mot *p;
  Nd_mot *nd;

  if (l == NULL) return NULL;

  nd = malloc(sizeof(Nd_mot));
  p = part_Lmot(&l);
  nd->mot = p->mot;

  nd->d = Lm2abr(p->suiv);
  nd->g = Lm2abr(l);

  free(p);
  return nd;
}


/* destruction de l ABR donnee en argument */
void detruire_abr_mot(Nd_mot *abr)
{
  if (abr == NULL) return;

  detruire_abr_mot(abr->g);
  detruire_abr_mot(abr->d);
  free(abr->mot);
  free(abr);
}


/* Recherche d'un mot dans ABR */
Nd_mot *chercher_Nd_mot(Nd_mot *abr, const char *mot)
{
  if (abr == NULL) return NULL;

  if (strcmp(mot, abr->mot) == 0) return abr;
  if (strcmp(mot, abr->mot) < 0) return chercher_Nd_mot(abr->g, mot);
  return chercher_Nd_mot(abr->d, mot);
}
