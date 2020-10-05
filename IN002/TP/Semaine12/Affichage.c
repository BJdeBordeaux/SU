#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Othello.h"
#include "Affichage.h"

#include <SDL.h>

#define CASE_SIZE 64

//-----------------------------  LES VARIABLES GLOBALES
static SDL_Window *screen;
static SDL_Renderer *renderer;

void clear_screen() {
  printf("\x1b[2J\x1b[1;1H");  /* code ANSI X3.4 pour effacer l'ecran */
}



void Afficher_plateau_text(int plateau[H][H]){


	clear_screen();	

	int i,j;
	printf(" 0|1|2|3|4|5|6|7|\n");
	for(i=0;i<H;i++){
		printf("%d", i);
		for(j=0;j<H; j++){
			switch(plateau[i][j]){
				case VIDE: printf(" |"); break;
				case NOIR: printf("*|"); break;
				case BLANC: printf("O|"); break;
				default: printf("Unknown character in game board\nEXITING\n"); exit(1);
			}
		}
		printf("*\n");
	}
	printf("-----------------\n");
}

void Creer_fenetre(char *ModeStr)
	{
	char WindowName[48];
	// Initialize SDL 2D display component.
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
		{
		fprintf(stderr, "Erreur: ne peut pas initialiser le systeme graphique (\"%s\").\n",
		SDL_GetError());
		return;
		}

	// Initialized windowed mode with given size and flags.
	sprintf(WindowName, "1I002 - Othello - %s", ModeStr);
	screen = SDL_CreateWindow(	WindowName,
								SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
								H*(CASE_SIZE + 1) + 1, (H+1)* (CASE_SIZE + 1),
								SDL_WINDOW_RESIZABLE);

	renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
	if (screen == NULL || renderer == NULL)
		{
		fprintf(stderr, "Oups, probleme a la creation de la fenetre...\n");
		exit(1);
		}

	}

void Detruire_fenetre()
	{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(screen);
	SDL_Quit();
	}

void Draw_disc(int xc, int yc, int r)
	{
	int x, y;
	for ( x = xc - r; x <= xc + r; x++) 
		for ( y = yc - r; y <= yc + r; y++) 
			if ((((x-xc) * (x -xc)) + ((y - yc) * (y - yc))) < (r*r))
      			SDL_RenderDrawPoint(renderer, x, y);
	}

void Dessine_plateau_graph(int plateau[H][H], int joueurCourant)
	{
	int i,j ;
	int x,y ;

	// Dessin Fond gris
	SDL_SetRenderDrawColor(renderer, 0xC0, 0xC0, 0xC0, 255);
	SDL_RenderClear(renderer);

	// Dessin du damier
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
	for(y = CASE_SIZE; y <=  (H+1)*CASE_SIZE +9 ; y+= CASE_SIZE + 1)
		SDL_RenderDrawLine(renderer, 0, y, H*CASE_SIZE +H, y);
	for(x = 0; x <=  H*(CASE_SIZE +1) ; x+= CASE_SIZE + 1)
		SDL_RenderDrawLine(renderer, x, CASE_SIZE, x, (H+1)*(CASE_SIZE +1) -1);

	// Placement du pion a jouer
	if (joueurCourant == 1)
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
	else
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 255);
	Draw_disc(CASE_SIZE/2, CASE_SIZE/2, CASE_SIZE/2);
	

	// Placement des pions
	for (i=0; i<H; i++)
		for (j=0; j<H; j++)
			if (plateau[i][j])
				{
				int x = 1 + CASE_SIZE/2 +(j * (CASE_SIZE + 1));
				int y = CASE_SIZE/2 +CASE_SIZE + 1 + (i * (CASE_SIZE +1));

				if (plateau[i][j] == 1)
					SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
				else
					SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 255);
				Draw_disc(x, y, CASE_SIZE/2);
				
				}
	
	SDL_RenderPresent(renderer);
	}

int Loop_until_play(int plateau[H][H], int *pi, int *pj, int joueurCourant)
{
	SDL_Event event;
	int x,y;

	Dessine_plateau_graph(plateau, joueurCourant);
	while(1) {
		// Poll system for an event.
		//if (SDL_PollEvent(&event)) {
		if (SDL_WaitEvent(&event)) {
			switch(event.type) {
				/* If the window has been closed, then stop the loop. */
				case SDL_QUIT: return -1;

				/* A mouse button have been pressed */
				case SDL_MOUSEBUTTONDOWN:
					x = event.button.x;
					y = event.button.y;

					*pj = x / (CASE_SIZE + 1);
					*pi = (y - CASE_SIZE) / (CASE_SIZE + 1);
					return 0;
			}
		}
	}
}
