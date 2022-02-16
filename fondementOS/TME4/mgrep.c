#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/resource.h>

#define MAXFILS 1

int main(int argc, char const *argv[])
{
    pid_t pid;
    int i;
    for (i = 0; i < (argc-2>MAXFILS?MAXFILS:argc-2); i++)
    {
        pid = fork();
        if(pid == 0 || pid == -1){
            break;
        }
    }
    if(pid == -1){
        // error
        fprintf(stderr, "error !\n");
        exit(EXIT_FAILURE);
    }else if (pid == 0)        // child process
    {
        printf("child process %d\n", getpid());
        execlp("grep", "grep", argv[1], argv[i+2], NULL);
        printf("End child process: %d\n", getpid());
        exit(EXIT_SUCCESS);
    }else
    {
        // parent process
        int k;
        struct rusage r;
        while((k=wait3(&pid, 0, &r))>0){
            struct timeval utime, stime;
            utime = r.ru_utime;
            stime = r.ru_stime;
            printf("PID %d :\n\tutime: %ld.%06lds\n\tstime: %ld.%06lds\n", k, utime.tv_sec, utime.tv_usec, stime.tv_sec, stime.tv_usec);
            if(i<argc-2){
                pid = fork();
                if (pid==0)
                {
                    // child process
                    printf("child process %d\n", getpid());
                    execlp("grep", "grep", argv[1], argv[i+2], NULL);
                    printf("End child process: %d\n", getpid());
                    exit(EXIT_SUCCESS);
                }
                i++;
            }
        };
        printf("End parent process: %d\n", getpid());
    }
    
    return 0;
}