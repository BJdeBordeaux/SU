#include<stdio.h>
#include<string.h>
#include<assert.h>

int same_string(char *s1, char *s2){
    if(strlen(s1)==strlen(s2)){
        while(*s1!='\0'){
            if(*s1==*s2){
                s1++;
                s2++;
            }else{
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int same_string2(char *s1, char *s2){
    int i = 0;
    while(s1[i]!='\0' && s2[i]!='\0' && s1[i]==s2[i]){
        i++;
    }
    if(s1[i] == s2[i]){
        return 1;
    }
    return 0;
}

int same_string_recursive(char *s1, char *s2){
    if(*s1 != *s2){
        return 0;
    }else if (*s2=='\0' && *s1=='\0')
    {
        return 1;
    }else{
        return(same_string_recursive(s1+1,s2+1));
    }
}

int main(){
    assert(same_string("hello world", "hello world"));
    assert(!same_string("hello world", "helloworld"));
    assert(!same_string("hello world!", "hello world"));
    assert(!same_string("hello wwrld", "hello world"));
    assert(same_string2("hello world", "hello world"));
    assert(!same_string2("hello world", "helloworld"));
    assert(!same_string2("hello world!", "hello world"));
    assert(!same_string2("hello wwrld", "hello world"));
    assert(same_string_recursive("hello world", "hello world"));
    // assert(!same_string_recursive("hello world", "helloworld"));
    // assert(!same_string_recursive("hello world!", "hello world"));
    // assert(!same_string_recursive("hello wwrld", "hello world"));
    printf("succeed.\n");
}