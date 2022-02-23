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
    char buffer2[taille];

    // variables processus
    int pid, i;
    int andOperand = 0;

    while(strcmp(buffer, "quit")!= 0){
        fgets(buffer, taille, stdin);
        buffer[strlen(buffer)-1] = '\0';
        if(buffer[strlen(buffer)-1] == '&'){
            andOperand = 1;
            buffer[strlen(buffer)-1] = '\0';
        }
        if((pid=fork()) == 0)
        {
            // processus fils
            if(strcmp(buffer, "quit") != 0){
                strcat(buffer2, "time ");
                strcat(buffer2, buffer);
                
                system(buffer2);
            }
            exit(EXIT_SUCCESS);
        }else
        {
            // processus père
            if(andOperand == 1){
                wait(NULL);
            }else{
                while(wait(NULL)!=-1);
            }
        }
    }
    

    printf("Goodbye!\n");
    return 0;
}
