#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "tab.h"

#define NTAB 1000000

void PrintMem(){
    int who = RUSAGE_SELF;
    struct rusage usage;
    int ret = getrusage(who, &usage);
    // long sec = usage.ru_utime.tv_sec + usage.ru_stime.tv_sec;
    // long usec = usage.ru_utime.tv_usec + usage.ru_stime.tv_usec;
    printf("ru_maxrss : %ld, return status : %d\n", usage.ru_maxrss, ret);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    PrintMem();
    int tab2[NTAB];
    InitTab(tab2, NTAB);
    PrintMem();
    // PrintTab(tab2, NTAB);
    int min2;
    int sum2 = MinSumTab(&min2, tab2, NTAB);
    printf("Sum : %d, Min : %d\n", sum2, min2);

    int *tab = malloc(sizeof(int)*NTAB);
    PrintMem();
    InitTab(tab, NTAB);
    PrintMem();
    // PrintTab(tab, NTAB);
    int min1;
    int sum = MinSumTab(&min1, tab, NTAB);
    free(tab);
    printf("Sum : %d, Min : %d\n", sum, min1);


    return 0;
}
