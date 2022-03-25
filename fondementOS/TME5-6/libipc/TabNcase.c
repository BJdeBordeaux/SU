/* Diffusion tampon N case */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <libipc.h>

/************************************************************/

/* definition des parametres */

#define NE 2   /*  Nombre d'emetteurs         */
#define NR 5   /*  Nombre de recepteurs       */
#define NMAX 3 /*  Taille du tampon           */

/************************************************************/

/* definition des semaphores */

#define S_EMETTEUR 0
#define S_IndexEcrireCase 1
#define S_NbRecption 2
int S_CASES[NMAX];
int S_RECEPTEUR[NR];

/************************************************************/

/* definition de la memoire partagee */

typedef struct
{
        int indexEcrireCase;
        int nb_recepteurs[NMAX];
        int caseContenu[NMAX];

} t_segpart;

t_segpart *sp;

/************************************************************/

/* variables globales */
int emet_pid[NE], recep_pid[NR];

/************************************************************/

/* traitement de Ctrl-C */

void handle_sigint(int sig)
{
        int i;
        for (i = 0; i < NE; i++)
                kill(emet_pid[i], SIGKILL);
        for (i = 0; i < NR; i++)
                kill(recep_pid[i], SIGKILL);
        det_sem();
        det_shm((char *)sp);
}

/************************************************************/

/* fonction EMETTEUR */

// A completer - contient les instructions executees
// par un emetteur

int emetteur(int id_emet)
{
        while (1)
        {
                printf("Emetteur %d\n", id_emet);

                P(S_IndexEcrireCase);
                        int tmp = sp->indexEcrireCase;
                        sp->indexEcrireCase = (sp->indexEcrireCase+1) % NMAX;
                V(S_IndexEcrireCase);

                P(S_EMETTEUR);
                
                P(S_CASES[tmp]);
                        sp->caseContenu[tmp] = id_emet;
                V(S_CASES[tmp]);
                for (int i = 0; i < NR; i++)
                {
                        V(S_RECEPTEUR[i]);
                }
        }
        return 0;
}

/************************************************************/

/* fonction RECEPTEUR */

int recepteur(int id_recp)
{
        int caseALire = 0;
        while (1)
        {
                P(S_RECEPTEUR[id_recp]);
                P(S_CASES[caseALire]);
                        printf("rec%d, case%d: %d \n", id_recp, caseALire, sp->caseContenu[caseALire]);
                V(S_CASES[caseALire]);
                
                P(S_NbRecption);
                        if (++sp->nb_recepteurs[caseALire] == NR)
                        {
                                sp->nb_recepteurs[caseALire] = 0;
                                V(S_EMETTEUR);
                        }
                V(S_NbRecption);
                caseALire = (caseALire + 1) % NMAX;
        }
}
/************************************************************/

int main()
{
        struct sigaction action;
        /* autres variables (a completer) */

        setbuf(stdout, NULL);

        /* Creation du segment de memoire partagee */
        if ((sp = (t_segpart *)init_shm(sizeof(t_segpart))) == NULL)
        {
                perror("init_shm");
                exit(1);
        }
        
        sp->indexEcrireCase = 0;
        for (int i = 0; i < NMAX; i++)
        {
                sp->caseContenu[i] = -1;
                sp->nb_recepteurs[i] = 0;
        }

        /* creation des semaphores */

        if (creer_sem(NMAX + NR + 3) == -1)
        {
                perror("creer_sem");
                exit(1);
        }

        /* initialisation des semaphores */

        init_un_sem(S_EMETTEUR, NMAX);
        init_un_sem(S_IndexEcrireCase, 1);
        init_un_sem(S_NbRecption, 1);
        for (int i = 0; i < NMAX; i++)
        {
                S_CASES[i] = i + 3;
                init_un_sem(S_CASES[i], 1);
        }
        for (int i = 0; i < NR; i++)
        {
                S_RECEPTEUR[i] = i + 3 + NMAX;
                init_un_sem(S_RECEPTEUR[i], 0);
        }

        /* creation des processus emetteurs */

        // A completer - les pid des processus crees doivent
        // etre stockes dans le tableau emet_pid
        for (int i = 0; i < NE; i++)
        {
                if ((emet_pid[i] = fork()) == 0)
                {
                        emetteur(i);
                }
        }

        /* creation des processus recepteurs */
        for (int i = 0; i < NR; i++)
        {
                
                if ((recep_pid[i]=fork()) == 0)
                {
                        recepteur(i);
                }
        }

        /* redefinition du traitement de Ctrl-C pour arreter le programme */
        sigemptyset(&action.sa_mask);
        action.sa_flags = 0;
        action.sa_handler = handle_sigint;
        sigaction(SIGINT, &action, 0);

        pause(); /* attente du Ctrl-C */
        return EXIT_SUCCESS;
}
