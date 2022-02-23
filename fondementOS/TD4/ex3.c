#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>
#define N 3

int main()
{
    int i = 0, pid;
    while(i<N && (pid=fork())== 0){
        i++;
    }
    if(pid == -1){
        fprintf(stderr, "fork error!\n");
        exit(EXIT_FAILURE);
    }else
    {
        printf("Je suis pid:%d\n", getpid());
        wait(NULL);
        printf("Pid:%d quit!\n", getpid());
        exit(EXIT_SUCCESS);
    }
    
    return 0;
}
