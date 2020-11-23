#ifndef ABR_H
#define ABR_H

#include "liste.h"

typedef struct Nd_mot_ {
  char *mot;
  struct Nd_mot_ *g;
  struct Nd_mot_ *d;
} Nd_mot;

/* Creation de l ABR */
Nd_mot *Lm2abr(Lm_mot *l);

/* destruction de l ABR donnee en argument */
void detruire_abr_mot(Nd_mot *abr);

/* Recherche d'un mot dans ABR */
Nd_mot *chercher_Nd_mot(Nd_mot *abr, const char *mot);

#endif
