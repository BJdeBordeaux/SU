/*
 * sched.h
 *
 * Copyright (C) 2001  Pierre Sens (Pierre.Sens@lip6.fr)
 *
 * Mini-ordonnanceur de fonctions utilisateurs 
 *
 */
#ifndef _SCHED_H_
#define _SCHED_H_

#include <sys/time.h>
#include <setjmp.h>
#include <signal.h>

#define true 1
#define false 0
#define main MAIN

// Parametres de l'ordonnanceur
#define QUANTUM   1

// Types d'ordonnancement 

#define NEW       1    // Nouvelle strategie definie par l'utilisateur
#define PREMPT    2    // Ordonnancement preemptif
#define BATCH     3    // Ordonnancement de type Batch

#define MAXPROC   20   // Nombre maximum de processus

#define MINPRIO   0
#define MAXPRIO   100



// Etat d'un processus
#define RUN 1
#define IDLE 2
#define ZOMB 3

typedef void (*function_t)();

typedef struct proc {
  int flag;                   // Etat de la tache 
  int prio;                   // Priorité
  int pid;                    // Pid 
  sigjmp_buf env;             // Contexte matériel (registres)
  function_t func;            // Le code 
  void *arg;                  // Les arguments
  int stack_size;             // La taille de la pile d'exécution
  char *stack_svg;            // La pile
  struct timeval end_time;    // date de fin
  struct timeval start_time;  // date de création  
  struct timeval realstart_time;  // date de lancement
  double ncpu;                // "cpu" consommés
  double duration;            // temps estimé de la tâche
} proc_t;

extern struct proc Tproc[MAXPROC];



void sched(int printmode);    // Ordonnanceur
int CreateProc(function_t, void *, int);   // Creation d'une processus leger
void SchedParam(int type, double quantum, int (*f)(void)); // Reglage des paramêtres 
void PrintStat(void);         // Affichage des statistiques
int GetElecProc(void);        // Retourne l'indice du processus elu

#endif
