#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/resource.h>

#define NBFILS_DARBRE 2

int main(int argc, char const *argv[])
{
    int nb_fils_cur;
    int pid = 0;
    int niveau_cur = 0;
    int default_niveau = 3;

    if(argc < 2){
        fprintf(stderr, "usage: %s <hauteur de l'arbre>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int niveau_max = atoi(argv[1]) <0 ? default_niveau : atoi(argv[1]);
    printf("niveau max : %d\n", niveau_max);
    
    printf("pid: %d\n", getpid());
    while(niveau_cur < niveau_max && pid==0){
        for (nb_fils_cur = 0; nb_fils_cur < NBFILS_DARBRE && ((pid = fork())!=0); nb_fils_cur++);
        niveau_cur++;
    }
    sleep(30);
    return 0;
}

