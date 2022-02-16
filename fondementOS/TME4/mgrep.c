#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("This is parent process %d\n", getpid());
    pid_t p1, p2;
    int status_child, exit_child;
    int taille = 255;
    char commandBuffer[taille];
    for (int i = 0; i < argc-2; i++)
    {
        if ((p1=fork())==0)
        {
            // child process
            printf("child process %d\n", getpid());
            strcat(commandBuffer, "grep");
            strcat(commandBuffer, " ");
            strcat(commandBuffer, argv[1]);
            strcat(commandBuffer, " ");
            strcat(commandBuffer, argv[i+2]);
            // printf(strdup(commandBuffer));
            system(commandBuffer);
            printf("\nEnd child process: %d\n", getpid());
            // printf("\nEnd child process: %d, status: %d\n", exit_child, WEXITSTATUS(status_child));
            // return 0;
            exit(1);
        }
        // parent process

    }

    exit_child = wait(&status_child);
    if(WIFEXITED(status_child)){
        
    }

    printf("End parent process: %d\n", getpid());
    return 0;
}