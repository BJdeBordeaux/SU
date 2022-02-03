# include "fonctions.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/times.h>
# include <time.h>
# include <unistd.h>

void lance_commande(char *command){
    struct timeval debut, fin;
    gettimeofday(&debut, NULL);
    system(command);
    gettimeofday(&fin, NULL);
    // printf("début: tv_usec = %ld tv_sec = %ld\n", debut.tv_usec, debut.tv_sec);
    // printf("fin: tv_usec = %ld tv_sec = %ld\n", fin.tv_usec, fin.tv_sec);
    long int delt_u = fin.tv_usec - debut.tv_usec;
    long int delt_s = fin.tv_sec - debut.tv_sec;
    double sec = delt_s + delt_u;
    printf("passé: tv_sec = %ld tv_usec = %ld\n", delt_s, delt_u);
}

void lance_commande2(char *command){
    clock_t start, end;
    typedef struct tms TMS;
    TMS start2, end2;
    struct timeval debut, fin;
    
    
    gettimeofday(&debut, NULL);
    times(&start2);
    system(command);
    gettimeofday(&fin, NULL);
    times(&end2);

    long int tick_per_sec = sysconf(_SC_CLK_TCK);
    long int delt_u = fin.tv_usec - debut.tv_usec;
    long int delt_s = fin.tv_sec - debut.tv_sec;
    double temps_total = delt_s + delt_u*1./CLOCKS_PER_SEC;
    printf("Commande : %s\n", command);
    printf("Temps total: %.6lf\n", temps_total);
    printf("Temps utilisateur: %.6lf\n", (double)(end2.tms_utime - start2.tms_utime)/tick_per_sec);
    printf("Temps système: %.6lf\n", (double)(end2.tms_stime - start2.tms_stime)/tick_per_sec);
    printf("Temps utilisateur fils: %.6lf\n", (double)(end2.tms_cutime - start2.tms_cutime)/tick_per_sec);
    printf("Temps système fils: %.6lf\n", (double)(end2.tms_cstime - start2.tms_cstime)/tick_per_sec);
    
    // printf("%ld, %ld\n", sysconf(_SC_CLK_TCK), CLOCKS_PER_SEC);
    
    
}