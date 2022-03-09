/* Diffusion tampon 1 case */

  #include <stdio.h> 
  #include <unistd.h> 
  #include <stdlib.h> 
  #include <signal.h> 
  #include <libipc.h>

/************************************************************/

/* definition des parametres */ 

  #define NE          2     /*  Nombre d'emetteurs         */ 
  #define NR          5     /*  Nombre de recepteurs       */ 

/************************************************************/

/* definition des semaphores */ 

	// A completer
  #define SEM_EMET 0
  #define SEM_NB_RECEPT 1
  int RECEP[NR];
  
/************************************************************/

/* definition de la memoire partagee */ 
#define MSG_TAILLE 255
	// A completer
typedef struct {
  int nbRecpt;
	char* msg;
} t_segpart;

t_segpart *sp; 

/************************************************************/

/* variables globales */ 
    int emet_pid[NE], recep_pid[NR]; 

/************************************************************/

/* traitement de Ctrl-C */ 

  void handle_sigint(int sig) { 
      int i;
      for (i = 0; i < NE; i++) kill(emet_pid[i], SIGKILL); 
      for (i = 0; i < NR; i++) kill(recep_pid[i], SIGKILL); 
      det_sem(); 
      det_shm((char *)sp); 
  } 

/************************************************************/

/* fonction EMETTEUR */ 
#define MSG_STR "This is a message.\n"
	// A completer - contient les instructions executees
        // par un emetteur
void Emettre(char* msg){
  P(SEM_EMET);
  sp->msg = msg;
  printf("(Message sent!)\n");
  for (int i = 0; i < NR; i++)
  {
    V(RECEP[i]);
  }
}

/************************************************************/

/* fonction RECEPTEUR */ 

	// A completer - contient les instructions executees
        // par un recepteur
void Recevoir(int i){
  P(RECEP[i]);
  printf("Recepteur %d: %s\n", i, MSG_STR);
  
  P(SEM_NB_RECEPT);
  sp->nbRecpt++;
  if(sp->nbRecpt ==NR){
    sp->nbRecpt = 0;
    printf("Case Libéré\n");
    V(SEM_EMET);
  }
  V(SEM_NB_RECEPT);
}

/************************************************************/

int main() { 
    struct sigaction action;
    /* autres variables (a completer) */
    
    setbuf(stdout, NULL);

/* Creation du segment de memoire partagee */

	// A completer
	if ( (sp = (t_segpart *)init_shm(sizeof(t_segpart) ))== NULL) {
		perror("init_shm");
		exit(1);
	}
  sp->nbRecpt = 0;

/* creation des semaphores */ 

	// A completer
  creer_sem(1+1+NR);


/* initialisation des semaphores */ 

	// A completer
  
  int i = 0;
  // Sem_Emetteur
  init_un_sem(i++, 1);

  // Sem_nbRecp
  init_un_sem(i++, 1);

  // Sem_Recepteur
  for (i = 0; i < NR; i++)
  {
    RECEP[i] = i+2;
    init_un_sem(RECEP[i], 0);
  }

/* creation des processus emetteurs */ 

	// A completer - les pid des processus crees doivent
        // etre stockes dans le tableau emet_pid
  for (int j = 0; j < NE; j++)
  {
    
    if((emet_pid[j] = fork()) == 0)// fils
    {
      while(1){
        Emettre(MSG_STR);
      }
    }
  }
  

/* creation des processus recepteurs */ 

	// A completer - les pid des processus crees doivent
        // etre stockes dans le tableau recep_pid
  for (int k = 0; k < NR; k++)
  {
    
    if((recep_pid[k] = fork()) == 0)// fils
    {
      while(1){
        Recevoir(k);
      }
    }
  }
/* redefinition du traitement de Ctrl-C pour arreter le programme */ 

    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    action.sa_handler = handle_sigint;
    sigaction(SIGINT, &action, 0); 
    
    pause();                    /* attente du Ctrl-C  */
    return EXIT_SUCCESS;
} 
