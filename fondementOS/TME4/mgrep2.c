#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/resource.h>

#define MAXFILS 2
int global_cpt = 0;
int main(int argc, char const *argv[])
{
    // struct rusage r;
    int status, i;
    int taille = 255;
    char commandBuffer[taille];
    for (i = 0; i < argc-2; i++)
    {
        status = fork();
        if(status == 0 || status == -1){
            break;
        }
    }
    if(status == -1){
        // error
        fprintf(stderr, "error !\n");
        exit(EXIT_FAILURE);
    }else if (status == 0)        // child process
    {
        printf("child process %d\n", getpid());
        printf(commandBuffer);
        strcat(commandBuffer, "grep");
        strcat(commandBuffer, " ");
        strcat(commandBuffer, argv[1]);
        strcat(commandBuffer, " ");
        strcat(commandBuffer, argv[i+2]);
        // printf(strdup(commandBuffer));
        system(commandBuffer);
        printf("End child process: %d\n", getpid());
        exit(EXIT_SUCCESS);
    }else
    {
        // parent process
        // sleep(1);
        // wait3(&status,0, &r);
        wait(&status);
        printf("End parent process: %d\n", getpid());
    }
    
    return 0;
}