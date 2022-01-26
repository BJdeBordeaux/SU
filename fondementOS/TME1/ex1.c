#include <stdio.h>
#include <stdlib.h>

int* strTab_2_intTab(char* charTab[], int len);
int max_list(int int_list[], int len);

int main(int argc, char *argv[])
{
    if(argc < 2){
        printf("Erreur : il faut passer des arguments\n");
        exit(1);
    }
    
    int len = argc - 1;
    int* intTab = strTab_2_intTab((argv+1), len);
    printf("max : %d\n", max_list(intTab, len));
    free(intTab);

    return 0;
}

int max_list(int int_list[], int len){
    int res = int_list[0];
    int i;
    for(i = 1; i < len; i++){
        if(int_list[i] > res){
            res = int_list[i];
        }
    }
    return res;
}

int* strTab_2_intTab(char* charTab[], int len){
    int* res = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        res[i] = atoi(charTab[i]);
    }

    return res;
}