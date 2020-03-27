#include<stdio.h>
#include<stdlib.h>

void affiche_lettre(char *s){
    while(*s!='\0'){
        if((*s>='A' && *s<='Z')||(*s>='a'&&*s<='z') ){
            printf("%c",*s);
        }
        s++;
    }
    printf("\n");
}

char *filtrage_lettre(char *s){
    int i = 0;
    char *res=malloc(255*sizeof(char));
    while(*s!='\0'){
        if((*s>='A' && *s<='Z')||(*s>='a'&&*s<='z') ){
            res[i]=*s;
            i++;
        }
        s++;
    }
    return res;
}

int main(){
    char *s = "\tI'm a person!\n";
    affiche_lettre(s);
    char *s2 = filtrage_lettre(s);
    affiche_lettre(s2);
    return 0;
}