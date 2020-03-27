#include <cini.h>

#define N       4
#define COEFX  50    /* coefficients d'echelle */
#define COEFY  38
#define DX    250    /* position dans la fenetre */
#define DY    420

/* fonction calcule_bornes_sup */
      /* A COMPLETER */

/* fonction tire_non_equi */
      /* A COMPLETER */

int main() {

   float tab_A[N] = {0.5,  0.2, -0.15,  0.85};    /* les coefficients a_i */
   float tab_B[N] = {0,   -0.26, 0.28,  0.04};    /* les coefficients b_i */
   float tab_C[N] = {0,    0.23, 0.26, -0.04};    /* les coefficients c_i */
   float tab_D[N] = {0.16, 0.22, 0.24,  0.85};    /* les coefficients d_i */
   float tab_E[N] = {0,    0,    0,     0};       /* les coefficients e_i */
   float tab_F[N] = {0,    1.6,  0.44,  1.6};     /* les coefficients f_i */
   
   int tab_P[N] = {1, 7, 7, 85};  /* pourcentages de chaque transformation */
   
   char *couleurs[N] = {"lime green", "fuchsia", "yellow", "turquoise"};

   /* Definition de variables supplementaires si necessaire */

   /* Calcul des bornes des intervalles */
   
         /* A COMPLETER */
   
   CINI_open_window(500, 500, "feuille");
   
   do {

      /* Choix du numero de la transformation a appliquer */
   
            /* A COMPLETER */
      
      /* Calcul du point a tracer (coordonnees x et y) */
   
            /* A COMPLETER */
                  
      CINI_draw_pixel(DX + x*COEFX, DY - y*COEFY, couleurs[noT]);      
      
   } while (! CINI_key_down());

   return 0;
}


