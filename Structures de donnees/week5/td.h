#ifndef __TDH__
#define __TDH__

typedef struct _formation Formation;
typedef struct _element
{
    Formation* f;
    struct _element* suivant;
} Element;
typedef Element* PElement;

struct _formation
{
    char* nom;
    int nb_heures; // initialiser a 0
    Element* suivant;
};
typedef Formation* PFormation;

typedef struct _catalog
{
    unsigned int nb_formations;
    unsigned int nb_max_formations;
    Formation** formations;
} Catalog;
typedef Catalog* PCatalog;


typedef struct _membre
{
    char* nom;
    struct _membre* suivant;    
}Membre;
typedef Membre* PMembre;

typedef struct _association
{
    char* nom_asso;
    PMembre liste_membres;
} Association;
typedef Association* PAssociation;

typedef struct _maison
{
    Association* assoc;
    struct _maison* suivant;
} Maision;
typedef Maision* PMaison;



#endif