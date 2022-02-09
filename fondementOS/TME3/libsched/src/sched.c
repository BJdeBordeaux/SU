/*
 * sched.c
 *
 * Copyright (C) 2001  Pierre Sens (Pierre.Sens@lip6.fr)
 *
 * Mini-ordonnanceur de fonctions utilisateurs 
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>
#include <signal.h>
#include <malloc.h>
#include <string.h>
#include <libelf/nlist.h>

#include "sched.h"

#define REEVAL 5
#define DEBUG printf

#undef main

struct proc Tproc[MAXPROC];

static sigjmp_buf envsched;
static long base;

static double Quantum = QUANTUM;
static int commut(int s);
static int election(void);
static void InitSched(void);
static void AjustPrio(void);
static int (*felect)(void) = election;
static int verbose;

static int courant;         // Indice du processus elu
static int nbrun;           // Nombre de processus prets
static char prog[40];       // Nom du programme
static int pidcount = 0;    // Compteur poour generer les pid
static sigset_t mask;

int MAIN(int, char **);

// Fonction qui retourne le processus elu ou -1 si il n'y en a aucun
int GetElecProc() {
  return (Tproc[courant].flag == RUN)?courant:-1;
}


// Fonction appelée toutes les "Quantum" secondes pour faire la commutation

int commut(int s) {
  int top;
  int ssize,k;

  if (verbose) 
   DEBUG("Commutation !\n");

  if (courant < 0 || courant >= MAXPROC || nbrun == 0) {
    return 0;
  }

  if (verbose) { 
    for (k=0;k<MAXPROC;k++) 
      if (Tproc[k].flag == RUN) 
	DEBUG(" <%d,%d>", k, Tproc[k].prio );
    DEBUG("\n");
  }

  

  // Sauvegarde de la pile
 
  ssize = base - (unsigned long) &top;
 
  if (Tproc[courant].stack_svg == NULL) {
    if ((Tproc[courant].stack_svg = (char *) malloc(ssize)) == NULL) {
      perror("sched - malloc");
      exit(1);
    }
  }
  else 
    if (ssize > Tproc[courant].stack_size) {
      if ((Tproc[courant].stack_svg = (char *) realloc(Tproc[courant].stack_svg,ssize)) == NULL) {
	perror("sched - realloc");
	exit(1);
      }
    }      
    
  Tproc[courant].stack_size =  ssize;

  bcopy((char *) &top, Tproc[courant].stack_svg, base - (unsigned long) &top);
  
  if (sigsetjmp(Tproc[courant].env,1) == 0) {

    Tproc[courant].ncpu+=Quantum;
    // Commutation 
    siglongjmp(envsched,0);
  
  }
  else {
    // Restauration de la pile
    bcopy(Tproc[courant].stack_svg, (char *) base - Tproc[courant].stack_size, Tproc[courant].stack_size); 
  }
  return 0;
}
			
// Algorithme d'election par defaut : priorité dynamique + reevaluation

// Reevaluation des priorité toutes les REEVAL secondes
void AjustPrio(void){
  int i;

  for (i=0; i < MAXPROC; i++) {
    if (Tproc[i].func != NULL) {
      Tproc[i].prio+=REEVAL/2;
      if (Tproc[i].prio > MAXPRIO)
	Tproc[i].prio = MAXPRIO;
    }
  }
}


// Election
int election(void) {
  static unsigned int i = 0;
  static int cpt = 0; 
  unsigned int j;
  int p;
  int maxprio = MINPRIO;
  int elu = GetElecProc();

  cpt++;
  if (cpt == REEVAL) {
    if (verbose) DEBUG("REEVALUATION\n");
    AjustPrio();
    cpt = 0;
  }

  if (Tproc[elu].prio > MINPRIO) Tproc[elu].prio--;

  p = 0;	

  j = (i-1)%MAXPROC;

  for(; i != j; i=(i+1)%MAXPROC) {
    if (Tproc[i].flag == RUN && Tproc[i].prio > maxprio) { 
      maxprio = Tproc[i].prio;
      p = i;
    }
  }
  return p;
}	

// Fixer les paramètres de l'ordonnanceur

void SchedParam(int type, double timeslice, int (*elec)(void)) {

  switch(type) {
  case BATCH:
    Quantum = 0;
    break;
  case PREMPT:
    Quantum = timeslice;
    break;
  case NEW:
    felect = elec;
    Quantum = timeslice;
  }
}



//  Boucle de l'ordonnanceur
void sched(int print) {

  struct sigaction sa;
  sigset_t m;
  struct itimerval timer;
 
  verbose = print;
    
  sigemptyset(&m);
  sa.sa_handler = (function_t) commut;
  sa.sa_flags = SA_NODEFER;
  sa.sa_mask = m;

  // Armer l'horloge
  sigaction(SIGALRM, &sa, NULL);

  sigsetjmp(envsched,1);
  
  //ualarm(Quantum*1E6,0);
  alarm(Quantum);

  timer.it_value.tv_sec = (long) Quantum;
  timer.it_value.tv_usec = 1E6 * ((double) Quantum - timer.it_value.tv_sec);
  timer.it_interval.tv_sec = (long) Quantum;
  timer.it_interval.tv_usec =  1E6 * ((double) Quantum - timer.it_value.tv_sec);
  setitimer(ITIMER_REAL, &timer,NULL);
 

  if (nbrun != 0) {
    courant = felect();
    if (courant >= 0 && courant < MAXPROC && Tproc[courant].flag == RUN) {
      // Restaurer les registres
      siglongjmp(Tproc[courant].env,0);
    }
    else {
      printf("Error: election of a wrong task - task id = %d, \n", courant);
      exit(1);
    }
  }
}


// Créer une nouvelle fonction			
int CreateProc(function_t f, void *arg, int d) {
  int ret;
  int i = 0;


  // Trouver la première entrée libre 

  while (i < MAXPROC && Tproc[i].flag != IDLE) 
    i++;
  if (i == MAXPROC) 
    return -1;


  // Inserer la fonction

  Tproc[i].flag = RUN;
  Tproc[i].pid = pidcount++;
  Tproc[i].func = f;
  Tproc[i].arg = arg;
  Tproc[i].ncpu = 0;
  Tproc[i].duration = d;
  Tproc[i].prio = MAXPRIO;
  gettimeofday(&Tproc[i].start_time, NULL);

  nbrun++;

  if ((ret = setjmp(Tproc[i].env)) == 0) 
    // longjmp(envmain, 0);
      return 0;
  else {
    
    if (Quantum == 0)
      gettimeofday(&Tproc[courant].realstart_time, NULL);
    
    // Lancement de la fonction
    Tproc[courant].func((int *)Tproc[courant].arg);

    // statistique d'utilisation CPU
    gettimeofday(&Tproc[courant].end_time, NULL);
    
    if (Quantum == 0) {
      struct timeval t;

      // Mode batch
      gettimeofday(&t, NULL);
      Tproc[courant].ncpu = (double)(Tproc[courant].end_time.tv_sec - Tproc[courant].realstart_time.tv_sec) + 
	(double)((double) (Tproc[courant].end_time.tv_usec - Tproc[courant].realstart_time.tv_usec)* 1e-6);
    }
    else {
      struct itimerval timer;
      getitimer(ITIMER_REAL, &timer);

      Tproc[courant].ncpu += (double) Quantum - 
      (double)((double) timer.it_value.tv_sec + (double) timer.it_value.tv_usec*1e-6);
      //      printf("courant %d - quantum %2.3f - duration %2.3f- ncpu %2.3f", courant, Quantum,  (double)((double) timer.it_value.tv_sec + (double) timer.it_value.tv_usec*1e-6), Tproc[courant].ncpu);
    }

    free(Tproc[courant].stack_svg);
    Tproc[courant].flag = ZOMB;
   
    nbrun--;
    longjmp(envsched,0);
  }
}

// Initialisation de la table des processus
void InitSched(void) {
  int i;
  
  for (i=0; i < MAXPROC; i++) {
    Tproc[i].start_time.tv_sec = Tproc[i].start_time.tv_usec = 0;    
    Tproc[i].realstart_time.tv_sec = Tproc[i].realstart_time.tv_usec = 0;    
    Tproc[i].end_time.tv_sec = Tproc[i].end_time.tv_usec = 0;
    Tproc[i].flag = IDLE;
    Tproc[i].func = NULL;

  }
  // Creer le masque de signal
  sigemptyset(&mask);
  sigaddset(&mask, SIGALRM);
}
	
// Affiche les statistiques de toutes les taches

void PrintStat(void) {
  int i,j;
  double t,avg_rt,avg_ct;
  struct nlist nlst[MAXPROC];

  // Masquer SIGALRM
  sigprocmask(SIG_BLOCK, &mask, NULL);

  // Recuperer les noms de fonctions
  j = 0;
  for (i = 0; i < MAXPROC; i++) {
    if (Tproc[i].func != NULL) {
      nlst[j].n_name = "Function";
      nlst[j].n_value = (long) Tproc[i].func;
      j++;
    }
  }
  nlst[j].n_name = NULL;

//  nlist(prog,nlst);
  
  j = 0;
  avg_rt = avg_ct = 0.0;

  // Afficher les statistiques
  printf("PID\tFUNCTION\tREAL-TIME\tCPU-TIME\tWAITING-TIME\n");
  printf("--------------------------------------------------------------------\n");
  for (i = 0; i<MAXPROC; i++) {
    if (Tproc[i].flag != IDLE) {
      t = (double) (Tproc[i].end_time.tv_sec - Tproc[i].start_time.tv_sec) + 
	(double) (Tproc[i].end_time.tv_usec - Tproc[i].start_time.tv_usec)* 1e-6;
      if (t<0) t=0;
      printf("%d\t%s%d\t%02.3fs\t\t%2.3fs\t\t%2.3fs\n", i, nlst[j].n_name,j,
	     t,Tproc[i].ncpu, t - Tproc[i].ncpu);
      j++;
      avg_rt += t;
      avg_ct += Tproc[i].ncpu;
      if (Tproc[i].flag == ZOMB) {
	Tproc[i].flag = IDLE;
	Tproc[i].func = NULL;
      }
    }
  }
  printf("--------------------------------------------------------------------\n");
  printf("Average:\t\t%2.3fs\t\t%2.3fs\t\t%2.3fs\n", avg_rt/(double)j,
	 avg_ct/(double)j, (avg_rt - avg_ct)/(double)j);
  printf("--------------------------------------------------------------------\n");
  // Demasquer SIGALRM
  sigprocmask(SIG_UNBLOCK, &mask, NULL);
}

// Le "vrai" main
int main (int argc, char *argv[]) {
  int ret;
  int i;
  base = (long) &i;

  setbuf(stdout,NULL);	

  strcpy(prog,argv[0]);
  // Initialiser

  InitSched();

  // Appeler le "main" du programme utilisateur
  ret = MAIN(argc,argv);
  exit(ret);
}
