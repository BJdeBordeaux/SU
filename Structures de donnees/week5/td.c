#include "td.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ex1

void affichage_formation(PFormation pformation){
    if(pformation->nb_heures == 0){
        printf("Formation : %s\n", pformation->nom);
        PElement tmp = pformation->suivant;
        while(tmp){
            printf(" %s ", tmp->f->nom);
            tmp = tmp->suivant;
        }
    }else{
        printf("Cours : %s", pformation->nom);
    }
    putchar('\n');
}

void affichage_catalog(PCatalog pcatalog){
    int i;
    for ( i = 0; i < pcatalog->nb_formations; i++)
    {
        affichage_formation(pcatalog->formations[i]);
    }
}

int nb_heures_formation(PFormation pformation){
    if(!pformation) {
        printf("La formation a pour valeur NULL");
        return 0;
    }
    int res = pformation->nb_heures;
    PElement tmp = pformation->suivant;
    while(tmp){
        res += nb_heures_formation(tmp->f);
        tmp = tmp->suivant;
    }
    return res;
}

void ajout_f1_dans_f2(PFormation f1, PFormation f2){
    // recherche sur f2 est deja incluse dans f1 (ou inversement)
    // on cherche a empecher la creation d'un cycle
    // si la recheche indique que les formations sont deja liee
    // alors on annule l'ajout
}

// ex2

PAssociation creer_association(const char* nomA){
    PAssociation a = (PAssociation) calloc(1, sizeof(Association));
    a->nom_asso = strdup(nomA);
    return a;
}

void liberer_association(PAssociation a){
    // ...
    free(a->nom_asso);
    // ...
}

void ajouter_personne(PAssociation a, const char* nom){
    PMembre m = (PMembre) calloc(1, sizeof(Membre));
    m->nom = strdup(nom);
    m->suivant = a->liste_membres;
    a->liste_membres = m;
}

void liberer_membre(PMembre m){
    if(!m) return;
    free(m->nom);
    free(m);
}

void supprimer_personne(PAssociation a, char* nom){
    if(!a) return;
    PMembre cur = a->liste_membres;
    if(!cur) return;
    PMembre prev = NULL;
    while(cur && strcmp(nom, cur->nom) != 0){
        prev = cur;
        cur = cur->suivant;
    }
    if(cur){
        prev->suivant = cur->suivant;
        liberer_membre(cur);
    }
}

PMaison creer_maison(){
    PMaison res = (PMaison) calloc(1, sizeof(Maision));
    return res;
}

void ajouter_association(PMaison* maison, PAssociation assoc){
    PMaison new = creer_maison();
    new->assoc = assoc;
    new->suivant = *maison;
}

void enleverAssociation(PMaison* m, PAssociation a)
{
    PMaison cur = *m;
    if(strcmp(a->nom_asso, cur->assoc->nom_asso)==0) // si cest le meme nom
    {
        *m = cur->suivant;
        free(cur);
    } else {
        PMaison prev = cur;
        cur = cur->suivant;
        
        while(cur!=NULL && strcmp(a->nom_asso, cur->assoc->nom_asso) != 0) {
            prev=cur;
            cur=cur->suivant;
        }
        if(cur != NULL) {
            prev->suivant=cur->suivant;
            free(cur);
        }
    }
    
}

// 2.4
// Personne morale -> liste != NULL, physique liste == NULL
// 2.5
// une personne recoit 2 fois si elle fait partie d'une personne morale
// si au moins 2 associations sont liee, alors on a un boucle infinie
// 2.6
// on va utiliser une table de hachage dont le cle = nom de personne
//  le contenu peut etre un booleen. si contenu == 0 : lettre non envoyee, sinon contenu == 1
// apres l'envoi, on fait tab_hachage[nom] = 1
// tab_hachage est juste utilise pour un seul envoi