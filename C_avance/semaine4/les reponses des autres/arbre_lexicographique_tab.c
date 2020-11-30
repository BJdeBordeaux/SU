#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "arbre_lexicographique_tab.h"
#define LONGUEUR_MAX 255

PNoeudTab creer_noeud(char lettre) {
   PNoeudTab n= (PNoeudTab)malloc(sizeof (struct noeudTab));
   if (n == NULL){
   printf("Problèmes d'allocation mémoire !\n");
   return NULL;
   }
   n->lettre = lettre;
   n->fin_de_mot=non_fin;
   for(int i=0;i<26;i++){
   n->fils[i]=NULL;
   }
  
  return ;
}

PNoeudTab ajouter_mot(PNoeudTab racine, char *mot) {
if (mot == NULL)
    return racine;
  else if (racine == NULL){
    if(strlen(mot) >= 1)
      return ajouter_mot(creer_noeud(*mot), mot+1);
    else
      return racine;
  }
  else{
      PNoeudTab tmp = racine;
            while(*mot != '\0'){
              tmp -> fils[*mot - 'a'] = creer_noeud(*mot);
              tmp = tmp -> fils[*mot - 'a'];
              mot++;
            }
            tmp -> fin_de_mot = fin;
      return racine;
  }

}

void afficher_mots(PNoeudTab n, char mot_en_cours[LONGUEUR_MAX_MOT], int index) {
  if (n==NULL)
    return;
  mot_en_cours[index] = n->lettre;

  if(n->fin_de_mot==fin) {
    mot_en_cours[index+1]='\0';
    printf("%s\n",mot_en_cours);
  }

  int i;
  for(i=0;i<26;i++) {
    // On affiche les fils
    if (n->fils[i]!=NULL) {

      afficher_mots(n->fils[i],mot_en_cours,index+1);
    }
  }  mot_en_cours[0] = "";
}

void afficher_dico(PNoeudTab racine) {
	char mot_en_cours[LONGUEUR_MAX];
	afficher_mots(racine,mot_en_cours,0);
  
}

void detruire_dico(PNoeudTab dico) {
  if( dico != NULL){
  	for(int i=0;i<26;i++){
  		detruire_dico(dico->fils[i]);
 	}
  free (dico);
  }
  
}

int rechercher_mot(PNoeudTab dico, char *mot) {
  if (dico == NULL || mot == NULL ||dico -> fils[*mot - 'a']==NULL)
    return 0;

  if(strlen(mot)==1)
    return dico -> fin_de_mot == fin;
    
  else{
      int i;
      for(i=0; i<26; i++)
      return  rechercher_mot(dico, mot+1);
    }

}

PNoeudTab lire_dico(const char *nom_fichier) {
 FILE *f=fopen(nom_fichier,"r");
 	if (f== NULL){
 	printf("Problème d'ouverture de fichier\n");
 	return NULL;
 	}
 	char ligne[LONGUEUR_MAX];
 	PNoeudTab dico=creer_noeud("!");
 	
 	while (!EOF ){
 		if (fgets (ligne,LONGUEUR_MAX,f)==NULL)
 			break;
 	ligne [strlen(ligne-1)]='\0';
 		if (strlen(ligne)>=1)
 		dico=ajouter_mot(dico,ligne);
 	}
 	fclose(f);
 	return dico;
 	
 
}
/*
Lm_mot *tous_les_mots_longueur_donnee_rec(PNoeudTab n, char mot_en_cours[LONGUEUR_MAX_MOT], int index, int l, Lm_mot *res) {
  char mot_en_cours[LONGUEUR_MAX_MOT];
 	strcpy(mot_a_completer,prefixe);
 	int i=0;
 	while((i<LONGUER_MAX_MOT)&&(mot_en_cours[i])!=' ');
 return tous_les_mots_longueur_donnee_rec(racine,mot_en_cours,i,strlen(prefixe),NULL);
 
}

Lm_mot *mots_commencant_par(const char *mot_a_completer, PNoeudTab dico) {
  Lm_mot *res=NULL;
  
 int l=strlen(mot_a_completer);
 PNoeudTab tmp(dico->fils[mot_a_completer[0]-'a'];
 int i=1;
 	while((tmp!=NULL) && (i<l) && (mot_a_completer[i]!=' ');
		tmp=tmp->fils[mot_a_completer[i]-'a'];
		i++;
		}
		if(tmp==NULL){
		return NULL;
		res=strcpy(mot_a_completr,i);
		
  return res;
}*/
