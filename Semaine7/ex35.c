#include<stdio.h>
#define NB_PLANETES 8


typedef struct planete {
    char nom[10];
    float densite;
    float distance;
    int nb_satellite;
} planete;

void affiche_planete(planete p){
    printf("nom : %s\n",p.nom);
    printf("densite : %.2f\n",p.densite);
    printf("distance au soleil en million km : %.2f\n",p.distance);
    printf("nombre de satellites : %d\n",p.nb_satellite);
}

void afficheToutesPlanetes(planete *ps, int taille){
    for (int i = 0; i < taille; i++)
    {
        affiche_planete(*(ps+i));
    }
    

}

int main(){
    planete systeme_Solaire[NB_PLANETES]={{"Mercure", 5.42, 58, 0}, {"Venus", 5.25, 108.2, 0}, {"Terre", 5.52, 149.6, 1}, {"Mars", 3.94, 227.9, 2}, {"Jupiter", 1.314, 778.3, 16}, {"Saturne", 0.69, 1427, 17}, {"Uranus", 1.19, 2869, 15}, {"Neptune", 1.6, 4496, 2}};

    affiche_planete(systeme_Solaire[0]);
    afficheToutesPlanetes(systeme_Solaire, NB_PLANETES);
    return 0;
}