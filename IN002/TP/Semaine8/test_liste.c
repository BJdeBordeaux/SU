#include "liste_entiers.h"
// #include "liste_entiers.c"
#include<stdio.h>

int main() {
  cellule_t *ma_liste=creerListe(5);
  AfficherListeInt(ma_liste);
  // cellule_t *ma_liste2=creerListe(5);
  // AfficherListeInt(ma_liste2);
  // printf("Sasissez la valeur :\n");
  // int val;
  // scanf("%d",&val);
  // // printf("nb_occurrence de %d : %d fois\n", val, nb_occurrence(val, ma_liste));
  // // if(tous_plus_grand(val, ma_liste)){
  // //   printf("%d c'est la valeur la plus petite.\n", val);
  // // }else{printf("%d n'est pas la valeur la plus petite.\n", val);}
  // // AfficherListeInt(Maximum(ma_liste));
  // printf("pos %d: %d\n", val, Renvoyer_val_pos(val, ma_liste));
  // cellule_t *ma_liste3 = Concatener_it(ma_liste, ma_liste2);
  // AfficherListeInt(ma_liste3);
  cellule_t *Max = Maximum(ma_liste);
  // printf("marque %d\n",2);
  // AfficherListeInt(Max);
  // printf("marque %d\n",1);
  printf("max: %d, nb:%d\n",Max->donnee, nb_maximum(Max));
  return 0;
}