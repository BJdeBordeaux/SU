#include <cini.h>
#include <SDL2/SDL.h>

#define TAILLE_CASE 20
#define HAUTEUR 22
#define LARGEUR 10
#define VIDE 8 /* n'importe quelle valeur qui n'est pas un indice du tableau des couleurs */

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
void afficher_piece(struct piece tetromino, char* couleur) {
  int i;
  int ligne_deb,colonne_deb;

  for (i=0; i < 4; i++) {
    ligne_deb=(tetromino.pos_ligne+tetromino.la_piece[i].ligne)*TAILLE_CASE;
    colonne_deb=(tetromino.pos_colonne+tetromino.la_piece[i].colonne)*TAILLE_CASE;
    CINI_fill_rect(colonne_deb,ligne_deb,TAILLE_CASE,TAILLE_CASE,couleur);
  }
}

/* Initialisation d'une piece, elle se trouve initialement en haut et au milieu du plateau */
void initialiser(struct piece* p_tetromino, struct une_case tab[4], int indice) {
  int i;
  p_tetromino->pos_colonne=LARGEUR/2;
  p_tetromino->pos_ligne=0;
  for (i=0; i < 4; i++) {
    p_tetromino->la_piece[i]=tab[i];
  }
	
  p_tetromino->type=indice;
}

/* Afficher toutes les pieces, permet de tester si les pieces sont bien declarees */
void afficher_toutes_pieces (char* color[], struct une_case tab_pieces[7][4]){
  int i;
  int lig=0;
  struct piece tetromino;

  for (i=0; i < 7; i++) {
    initialiser( &tetromino,tab_piece[i],i);
    tetromino.pos_ligne=lig;
    lig = lig + 3;
    afficher_piece(tetromino,color[tetromino.type]);
  }
}

/*---------------------------------------------------------------------*/

int main() {
   
   /*---------------------   les declarations   ---------------------*/
   
   int indice;    /* l'indice (type) de la piece jouee */
   int touche;   /* identifie la frappe du joueur */  

   char* color[] = {"light salmon","fuchsia","lime green","white","yellow","cyan","grey"};
   
   
   /* (a completer) */
   
   /*--------------------  les initialisations  ---------------------*/
   
   srand(time(NULL));
   
   /* (a completer) */

   /*----------------------  ouverture de la fen�tre graphique -------*/

   CINI_open_window(LARGEUR*TAILLE_CASE,HAUTEUR*TAILLE_CASE,"black");
   
   /* Affichage de test des pieces */
   /* Instruction a mettre en commentaire pour la suite */
   afficher_toutes_pieces(color,tab_pieces);
   
   /*----------------------  la boucle de jeu  ----------------------*/

   do {
      /* afficher_plateau( );*/
      indice = rand()%7;
      /* initialiser( ); */
      /* afficher_piece( ); */
            
      do {
         touche = CINI_loop_until_keyup();
         /* afficher_piece( ); */              /* "efface" la piece en l'affichant en noir ... */
         /* descendre( ); */  
         switch (touche) {
            case SDLK_LEFT:
               /* decaler_gauche( ); */
               break;
            case SDLK_RIGHT:
               /* decaler_droite( ); */
               break;
            case SDLK_d:
               /* rotation_gauche( ); */
               break;
            case SDLK_g:
               /* rotation_droite( ); */
               break;
            /*case SDLK_g:
               hard_drop( ); 
               break; */
            default:
               break;
         }
         /* afficher_piece( ); */   /* ... avant de la reafficher
                                                                  apres modification */
      } while ( (touche != SDLK_DOWN) && (touche != SDLK_ESCAPE) ) ;
            
      /* on supprime les lignes completes si elles existent */
      /* supprimer_lignes( ); */

   } while (touche != SDLK_ESCAPE) ;
      
   return 0;
}
