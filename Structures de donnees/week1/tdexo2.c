#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    float nb = rand()*1./RAND_MAX*1.;
    float nb2 = rand()/RAND_MAX*1.;
    float nb3 = rand()*1./RAND_MAX;// non
    float nb4 = (float) rand()/RAND_MAX;

    if (argc < 1) {
        printf("At least a argument!");
        exit(1);
    }
    
    int n = atoi(argv[1]);
    int vMin = 0;
    int nb5 = vMin + rand()%(n+1);

    printf("nb aleatoire : %f\n", nb4);
    printf("random int in [0, %d] : %d\n", n, nb5);

    // int *p = &n;
    int *p = (int*) malloc(sizeof(int));
    printf("un initial pointer *p = %d\n", *p);

    return 0;
}
abcdefg
