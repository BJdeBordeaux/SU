#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("This is parent process %d\n", getpid());
    pid_t p1;
    int status_child;
    for (int i = 0; i < argc-2; i++)
    {
        if ((p1=fork())==0)
        {
            // child process
            printf("child process %d\n", getpid());
            execlp("grep", "grep", argv[1], argv[i+2], NULL);
            printf("\nEnd child process: %d\n", getpid());
            exit(EXIT_SUCCESS);
        }
    }
    // parent process
    sleep(10);
    int k;
    while((k=wait(&status_child))!=-1){
        printf("End child process: %d\n", k);
    };

    printf("End parent process: %d\n", getpid());
    return 0;
}