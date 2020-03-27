#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int est_deb(char *deb, char *mot){
    if(strlen(deb)>strlen(mot)){
        return 0;
    }
    while( (*deb == *mot) && (*mot != '\0')){
        deb++;
        mot++;
        if(*deb == '\0'){
            return 1;
        }
    }
    return 0;
}

int est_incluse(char *s1, char *s2){
    if(*s1 != *s2  && (*s1 != '\0')){
        // printf("m1 : s1 %c, s2 %c\n",*s1, *s2);
        return 0;
    }else if(*s1 == '\0'){
        // printf("m2 : s1 %c, s2 %c\n",*s1, *s2);
        return 1;
    }else if(*s2 == '\0'){
        // printf("m3 : s1 %c, s2 %c\n",*s1, *s2);
        return 0;
    }else{
        // printf("m4 : s1 %c, s2 %c\n",*s1, *s2);
        return est_incluse(s1+1, s2+1);
    }
    
}

int main(){
    char *a1 = "alphabet";
    char *a2 = "algab";
    char *a3 = "blphab";
    char *a4 = "alpha";
    char *a5 = "alphabet";
    char *a6 = "alphabeta";

    assert(!est_deb(a2, a1));
    assert(!est_deb(a3, a1));
    assert(!est_deb(a6, a1));
    assert(est_deb(a4, a1));
    assert(est_deb(a5, a1));

    // assert(!est_incluse('1re', '1reg'));
    // est_incluse(a4, a1);
    assert(!est_incluse(a2, a1));
    assert(!est_incluse(a3, a1));
    assert(!est_incluse(a6, a1));
    assert(est_incluse(a4, a1));
    assert(est_incluse(a5, a1));
    return 0;
}