#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "liste.h"

Lm_mot *creer_Lm_mot(char *mot)
{
  Lm_mot *pm = malloc(sizeof(Lm_mot));
  if (pm==NULL)
    {
      printf("Probleme lors de l'allocation d'un element de liste de mot.\n");
      return NULL;
    }
  pm->mot=strdup(mot);
  pm->suiv=NULL;
  return pm;
}

Lm_mot *ajouter_Lmot(Lm_mot *lm, char *mot)
{
  Lm_mot *plm = lm;
  Lm_mot *npm = creer_Lm_mot(mot);
  if (npm==NULL) 
    return lm;
	
  if (lm == NULL)
    return npm;

  if (strcmp(mot, lm->mot) <= 0)
    {
      npm->suiv = lm;
      return npm;
    }
	
  while (plm->suiv)
    {
      if (strcmp(mot, plm->suiv->mot) <= 0)
	{
	  npm->suiv = plm->suiv;
	  plm->suiv = npm;
	  return lm;
	}
      plm = plm->suiv;
    }
  plm->suiv = npm;
  return lm;
}

void afficher_Lmot(Lm_mot *lm)
{
  int cpt=0;
  while (lm!=NULL)
    {
      printf("%s\n",lm->mot);
      lm=lm->suiv;
      cpt++;
    }
  printf("Nombre de mots dans la liste: %d\n",cpt);
}

int taille_Lmot(Lm_mot *lm)
{
  int cpt=0;
  for(cpt = 0; lm; lm = lm->suiv)
    cpt++;
  return cpt;
}


void detruire_Lmot(Lm_mot *lm)
{
  while (lm)
    {
      Lm_mot *lm_suiv = lm->suiv;
      free(lm->mot);
      free(lm);
      lm = lm_suiv;
    }
}

Lm_mot *lire_dico_Lmot(const char *nom_fichier)
{
  char ligne[100];
  Lm_mot *lm=NULL;
  FILE *f=fopen(nom_fichier,"r");
  if (f==NULL)
    {
      printf("Erreur lors de l'ouverture du fichier %s\n",nom_fichier);
      return NULL;
    }

  while(fgets(ligne,100,f))
    {
      ligne[strlen(ligne)-1]='\0';
      lm=ajouter_Lmot(lm,ligne);
    }
  fclose(f);
  return lm;
}

Lm_mot *chercher_Lm_mot(Lm_mot *lm, const char *mot)
{
  while(lm)
    {
      if(strcmp(lm->mot,mot) == 0)
	return lm;
      if(strcmp(lm->mot,mot) > 0)
	return NULL;
      lm=lm->suiv;
    }
  return NULL;
}


