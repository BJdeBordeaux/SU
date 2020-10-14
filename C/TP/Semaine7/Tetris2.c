#include <cini.h>
#include <time.h>
#include <SDL2/SDL.h>

#define TAILLE_CASE 20
#define CHANGEMENT_NIVEAU 10 /* indique combien de lignes doivent avoir ete supprimees pour changer de niveau */

/* (a completer) */

/*-------------   INSERER ICI LES DEFINITIONS DE TYPES   --------------*/
struct une_case {
  int colonne;
  int ligne;
};

struct piece {
  int pos_ligne, pos_colonne;
  struct une_case la_piece[4];
  int type;
};

/*-------------------   INSERER ICI LES FONCTIONS   -------------------*/
/* Affiche une piece */
void afficher_piece(struct piece tetromino, char* color) {
  int i;
  int ligne_deb,colonne_deb;

  for (i=0; i < 4; i++) {
    ligne_deb=(tetromino.pos_ligne+tetromino.la_piece[i].ligne)*TAILLE_CASE;
    colonne_deb=(tetromino.pos_colonne+tetromino.la_piece[i].colonne)*TAILLE_CASE;
    CINI_fill_rect(colonne_deb,ligne_deb,TAILLE_CASE,TAILLE_CASE,color);
  }
}

/* Initialisation d'une piece, elle se trouve initialement en haut et au milieu du plateau */
void initialiser(struct piece *p_tetromino, struct une_case tab[4], int indice) {
  int i;
  p_tetromino->pos_colonne=LARGEUR/2;
  p_tetromino->pos_ligne=0;
  for (i=0; i < 4; i++) {
    p_tetromino->la_piece[i]=tab[i];
  }
	
  p_tetromino->type=indice;
}


/*-------------------------   Gestion du temps  ---------------------------*/

Uint32 at_top_horloge(Uint32 interval, void *param) {
   /* ajoute un evenement SDL_USEREVENT dans la file a l'echeance de l'horloge
      et reinitialise celle-ci a interval */
   SDL_Event event;
   SDL_UserEvent userevent;
   
   userevent.type = SDL_USEREVENT;
   userevent.code = 0;
   userevent.data1 = NULL;
   userevent.data2 = param;
   
   event.type = SDL_USEREVENT;
   event.user = userevent;
   SDL_PushEvent(&event);

   return interval;
}

/*------------------------------------------------------------------------*/

int main() {
   
   /* les variables */
   char * color[] = {"light salmon","fuchsia","lime green","white","yellow","cyan","grey"};
   

  /*---------------------   les declarations   ---------------------*/

  int descente_OK = 1;     /* determine si la piece peut encore descendre */
  int running = 1;         /* passe a 0 si l'utilsateur utilise la touche ESCAPE 
                               permet un arret premature de la partie              */
  int cpt=0, niveau=0;
  SDL_TimerID horloge;      /* l'identifiant de l'horloge qui cadence la chute des pieces */
   Uint32 intervalle = 500;  /* la periode de l'horloge (en ms) */
   SDL_Event event;          /* l'evenement a traiter */

   SDL_Surface *screen;

   int indice;    /* l'indice (type) de la piece jouee */

   /* (a completer) */

   /*--------------------  les initialisations  ---------------------*/
   
   srand(time(NULL));

   /* (a completer) */

   /*----------------------  ouverture de la fenêtre graphique -------*/
    
   /* CINI_open_window appelle SDL_Init qui initialise le timer :  
      a executer imperativement AVANT la creation de l'horloge  */
   
  /* (a completer) CREATION DE LA FENETRE */ 
   CINI_open_window(LARGEUR*TAILLE_CASE,HAUTEUR*TAILLE_CASE,"black");
                     
   screen = SDL_GetVideoSurface(); /* la surface video associee a la fenetre */
   
   /* at_top_horloge est appelee a chaque echeance de intervalle */
   horloge = SDL_AddTimer(intervalle, at_top_horloge, NULL);  

   /*----------------------  la boucle de jeu  ----------------------*/
   
   do {
     /* afficher_plateau( );*/
      nxt = rand()%7;
      /* initialiser( ); */
      /* afficher_piece( ); */
      descente_OK = 1;
      
      do {
         SDL_Flip(screen);        /* maj de l'affichage graphique */
         SDL_WaitEvent(&event);   /* on attend qu'il se passe quelque chose */
         /* afficher_piece(); */   /* on "efface" la piece */
         switch(event.type) {
            case SDL_USEREVENT: 
               /* descente_OK = descendre();*/
               break;
            case SDL_KEYUP:
               switch (event.key.keysym.sym) {
                  case SDLK_LEFT:
                     /*decaler_gauche(); */
                     break;
                  case SDLK_RIGHT:
                     /*decaler_droite(); */
                     break;
                  case SDLK_d:
                     /* rotation_gauche(); */
                     break;
                  case SDLK_g:
                     /* rotation_droite(); */
                     break;
                  case SDLK_SPACE:
                     /* hard_drop(); */
                     break;
                  case SDLK_ESCAPE:
                     running = 0;
                     break;
                  default:
                     break;
               }
               break;
            default:
               break;
         }
         /* afficher_piece( ); *//* on l'affiche apres mouvement */
      } while ( running && descente_OK );
      /* supprimer_ligne() */      
/*    
      if (cpt == CHANGEMENT_NIVEAU) {
         SDL_RemoveTimer(horloge);
         intervalle = intervalle -50;
         horloge = SDL_AddTimer(intervalle, at_top_horloge, NULL); 
         niveau++;
         cpt = cpt - CHANGEMENT_NIVEAU;
      }
*/
      
   } while (running) ;
   /* condition a completer en tenant compte du resultat de partie_perdue */
   /*----------------------------------------------------------------*/
   
   CINI_loop(); /* on attend (pour visualiser la fin de partie : score et plateau) */
   return 0;
}









