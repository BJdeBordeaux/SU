#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/resource.h>

int main(int argc, char const *argv[])
{
    printf("Bienvenu à minishell\n");

    // chaîne de caractères
    int taille = 255;
    char buffer[taille];
    char *tab[taille];

    // variables processus
    int pid, i;
    int wait_for_fils = 1;

    while(strcmp(fgets(buffer, taille, stdin), "quit\n")!= 0){

        buffer[strlen(buffer)-1] = '\0';
        if(buffer[strlen(buffer)-1] == '&'){
            wait_for_fils = 0;
            buffer[strlen(buffer)-1] = '\0';
        }
        if((pid=fork()) == 0)
        {
            // processus fils
            char *token = strtok(buffer, " ");
            int i = 0;
            while (token != NULL)
            {
                tab[i++] = token;
                token = strtok(NULL, " ");
            }
            tab[i] = NULL;
            execvp(tab[0], tab);
            exit(EXIT_SUCCESS);
        }else
        {
            // processus père
            if(wait_for_fils == 1){
                struct rusage r;
                wait3(NULL, 0, &r);
                struct timeval utime = r.ru_utime, stime = r.ru_stime;
                printf("utime: %ld.%06lds\nstime: %ld.%06lds\n", utime.tv_sec+utime.tv_usec/1000000, utime.tv_usec%1000000, stime.tv_sec+stime.tv_usec/1000000, stime.tv_usec%1000000);
            }
        }
    }
    

    printf("Goodbye!\n");
    return 0;
}
