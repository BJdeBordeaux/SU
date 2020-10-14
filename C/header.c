#include <stdio.h>
#include <stdlib.h>

void print_int_table(int *t, int len){
    int i;
    for(i = 0; i < len; i++){
        if(i%10 == 0){printf("\n");}
        printf("(%d)  ",t[i]);
    }
    printf("\n");
}
