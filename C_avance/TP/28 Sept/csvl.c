#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void detruit_tab_mots(char **ptab_mots);
void affiche_tab_mots(char **ptab_mots);//查看单词数组里的单词
int compte_mots(char **ptab_mots);//求一个单词数组的单词数量
int compte_mots_chaine(char *s);//求一个句子（字符串）中单词数量
char **decompose_chaine(char *chaine);//将一个句子打散成字符串数组

char *compose_chaine(char **ptab_mots)
{
  /* a completer exercice 3, question 4 */
  int len_mot = 0;
  int nb_mots = compte_mots(ptab_mots);
  int espace = nb_mots - 1;
  int i;
  for(i = 0; i < nb_mots; i++){
    len_mot += compte_char(ptab_mots[i]);
    // printf("mot, cc : %s, %d\n",ptab_mots[i],compte_char(ptab_mots[i]));
  }
  
  char *res = (char*) malloc((len_mot+espace+1)*sizeof(char));
  printf("len + esp :%d\n",len_mot+espace+1);
  int len_p = 0;
  int cc;
  for(i = 0; i < nb_mots; i++){
      cc = compte_char(ptab_mots[i]);
      memcpy(res+len_p, ptab_mots[i], cc*sizeof(char));
      len_p += cc;
      strcpy(res+len_p, " ");
      len_p++;
      // printf("%s\n",res);
    }
  return res;
}
		

char **reduit_tab_mots(char **ptab_mots)
{
  /* a completer exercice 4, question 1 */
}

int main() {

  char **tab_s = {"mot1","et","mot2","et"," ","mot3"};
  char *s1 = " mot1 et mot2 et  mot3 ";
  // printf("mot s1 = %d\n", compte_mots_chaine(s1));
  char **tab_s2 = decompose_chaine(s1);
  affiche_tab_mots(tab_s2);
  int cpt_s2 = compte_mots(tab_s2);
  printf("compte_mot : %d\n", cpt_s2);
  char *s3 = compose_chaine(tab_s2);
  printf("%s\n", s3);
  /* a completer:
   * exercice 3, question 3, 5 
   * exercice 4, question 1
   */
  return 1;
}

int compte_mots_chaine(char *s) {
  int n = 0;
  while(*s != '\0'){
    while(*s ==' '){s++;}
    if(*s == '\0'){return n;}
    n++;
    while((*s != ' ') && (*s)){
      *s++;
    }
  }
  return n;
}

char **decompose_chaine(char *chaine)
{

  /* Fonction vue en TD, exercice 2, question 7 */

  char *pc= chaine;
  int nb_mots=0;
  char **ptab;
  char *psrc_mot;
  int ind_mot=0;

  //comptages des mots
  nb_mots=compte_mots_chaine(chaine);
  
  if (nb_mots == 0)
    return NULL;
  // allocation du tableau

  ptab = malloc((nb_mots + 1) * sizeof(char *));
  ptab[nb_mots] = NULL;
  
  // copie des mots
  
  pc=chaine;
  while (*pc)
    {
      if(*pc == ' ')
        {
          pc++;
          continue;
        }

      psrc_mot = pc;

      while((*pc != ' ') && (*pc)) pc++;

      //allocation du mot
      ptab[ind_mot] = malloc((pc - psrc_mot + 1)* sizeof(char));
      //copie du mot
      memcpy(ptab[ind_mot], psrc_mot, pc - psrc_mot);
      //insertion du marqueur de fin de chaine
      *(ptab[ind_mot] + (pc - psrc_mot)) = '\0';

      ind_mot++;
    }
  

  return ptab;
}

int compte_mots(char **ptab_mots)
{
  /* a completer exercice 3, question 2 */
  int n = 0;
  while(*ptab_mots != NULL){
    n++;
    ptab_mots++;
  }
  return n;
}

void detruit_tab_mots(char **ptab_mots)
{

  /* Fonction vue en TD, exercice 2, question 5 */

  int i=0;

  if (ptab_mots)
    while(ptab_mots[i])
      free(ptab_mots[i++]);

  free(ptab_mots);
}

void affiche_tab_mots(char **ptab_mots)
{
  while(*ptab_mots){
    char *pc = ptab_mots[0];
    printf("%s\n", pc);  
    ptab_mots++;
  }
  
}

int compte_char(char *s){
  int n = 0;
  while(*s){
    n++;
    s++;
  }
  return n;
}