#ifndef CSVL
#define CSVL

/*****************************************************************************/
/* Fonction de comptage du nombre de mots presents dans une chaine de        */
/* caracteres.                                                               */
/* Renvoie le nombre de mots presents dans l'argument chaine.                */
/*****************************************************************************/
int compte_mots_chaine(char *chaine);

/*****************************************************************************/
/* Fonction de decomposition d une chaine un tableau de pointeur sur des mots*/
/* Retourne un pointeur sur le tableau alloue. la dernier element du tableau */
/* doit toujour etre egal a NULL.                                            */
/*****************************************************************************/
char **decompose_chaine(char *chaine);

/*****************************************************************************/
/* Fonction de decomposition d une chaine un tableau de pointeur sur des mots*/
/* Retourne un pointeur sur le tableau alloue.                               */
/*****************************************************************************/
char *compose_chaine(char **ptab_mots);


/*****************************************************************************/
/* Libere la memoire allouee pour un tableau de mots ainsi que les mots qui  */
/* qui le composent.                                                         */
/*****************************************************************************/
void detruit_tab_mots(char **ptab_mots);

/*****************************************************************************/
/* Compte ne nombre de mots presents dans un tableau de mots.                */
/*****************************************************************************/
int compte_mots(char **ptab_mots);


/*****************************************************************************/
/* Affiche le tableau de mots.                                               */
/*****************************************************************************/
void affiche_tab_mots(char **ptab_mots);

/*****************************************************************************/
/* fonction de reduction de la memoire utilisee pour stocker les mots par    */
/* supression des ocurences multiples d un meme mot.                         */
/* Retourne un pointeur sur le nouveau tableau de mots.                      */
/*****************************************************************************/
char **reduit_tab_mots(char **ptab_mots);

#endif
