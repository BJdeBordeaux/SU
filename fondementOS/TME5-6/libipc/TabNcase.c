/* Diffusion tampon N case */

  #include <stdio.h> 
  #include <unistd.h> 
  #include <signal.h> 
  #include <libipc.h>

/************************************************************/

/* definition des parametres */ 

  #define NE          2     /*  Nombre d'emetteurs         */ 
  #define NR          5     /*  Nombre de recepteurs       */ 
  #define NMAX        3     /*  Taille du tampon           */ 

/************************************************************/

/* definition des semaphores */ 

	// A completer

/************************************************************/

/* definition de la memoire partagee */ 

	// A completer

/************************************************************/

/* variables globales */ 
    int emet_pid[NE], recep_pid[NR]; 

/************************************************************/

/* traitement de Ctrl-C */ 

  void handle_sigint(int sig) 
  { int i;
  	for (i = 0; i < NE; i++) kill(emet_pid[i], SIGKILL); 
	for (i = 0; i < NR; i++) kill(recep_pid[i], SIGKILL); 
	det_sem(); 
	det_shm((char *)sp); 
 
  } 

/************************************************************/

/* fonction EMETTEUR */ 

	// A completer - contient les instructions executees
        // par un emetteur

/************************************************************/

/* fonction RECEPTEUR */ 

	// A completer - contient les instructions executees
        // par un recepteur

/************************************************************/

int main() { 
    struct sigaction action;
    /* autres variables (a completer) */
    
    setbuf(stdout, NULL);

/* Creation du segment de memoire partagee */

	// A completer

/* creation des semaphores */ 

	// A completer

/* initialisation des semaphores */ 
    
	// A completer
    
/* creation des processus emetteurs */ 

	// A completer - les pid des processus crees doivent
        // etre stockes dans le tableau emet_pid

/* creation des processus recepteurs */ 

	// A completer - les pid des processus crees doivent
        // etre stockes dans le tableau recep_pid
    
/* redefinition du traitement de Ctrl-C pour arreter le programme */ 

    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    action.sa_handler = handle_sigint;
    sigaction(SIGINT, &action, 0); 

    pause();                     /* attente du Ctrl-C */
    return EXIT_SUCCESS;
} 
