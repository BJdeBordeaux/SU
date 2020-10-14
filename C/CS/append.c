#include<stdio.h>
#include<stdlib.h>

struct cell
{
    int first;
    struct cell *kid;
};
typedef struct cell *int_list;

int_list cons(int first, int_list kid){
    int_list r = malloc(sizeof(struct cell));
    r->first = first;
    r->kid = kid;
    return r;
}

int_list append1(int_list n1, int_list n2){
    if(n1 != NULL){
        return cons(n1->first, append1(n1->kid, n2));
    }else{
        return n2;
    }
}

int_list append2(int_list n1, int_list n2){
    if(n1 != NULL){
        int_list ptr = n1;
        while(ptr->kid != NULL){
            ptr = ptr->kid;
        }
        ptr->kid = n2;
        return n1;
    }else{
        return n2;
    }
}

int main(){
    // int_list l
    
    return 0;
}