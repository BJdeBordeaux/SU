#ifndef TD_H
#define TD_H
typedef struct _cellule* PCellule;
struct _cellule
{
    int data;
    PCellule suivant;
    PCellule precedent;
} Cellule;

typedef struct _liste * PListe;
struct _liste
{
    PCellule debut;
    PCellule fin;
} Liste;
#endif

PCellule creer_Cellule(int data);
PListe creer_liste();
void insererEnTete(PListe l, PCellule c);
void insererEnFin(PListe l, PCellule c);