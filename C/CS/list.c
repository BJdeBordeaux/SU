#include<stdlib.h>
#include<stdio.h>

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

void print_int_list(int_list ns){
    if(ns != NULL){
        print_int_list(ns->kid);
        printf("%d,  ", ns->first);
    }else{
        printf("\n");
    }
}

int somme_list(int_list ns){
    int somme = 0;
    while(ns != NULL){
        somme += ns->first;
        ns = ns->kid;
    }
    return somme;
}



int somme_list2(int_list ns){
    if(ns != NULL){
        return ns->first + somme_list2(ns->kid);
    }else{
        return 0;
    }
}

int carre(int a){
    return a*a;
}

// int list_carre(int_list ns){
//     int_list r = NULL;
//     while(ns != NULL){
//         r = cons(carre(ns->first), r);
//         ns = ns->kid;
//     }
//     return r;
// }

int_list list_carre2(int_list ns){
    if(ns != NULL){
        return cons(carre(ns->first),list_carre2(ns->kid));
    }else{
        return NULL;
    }
}

int_list rev(int_list ns){
    int_list r = NULL;
    while(ns != NULL){
        r = cons(ns->first,r);
        ns->kid;
    }
    return r;
}

// int_list rev2(int_list ns){
//     if(ns != NULL){
//         return cons(ns->first,rev2(ns->kid));
//     }else{
//         return NULL;
//     }
// }

void free_int_list(int_list ns){
    while(ns != NULL){
        int_list ptr = ns->kid;
        free(ns);
        ns = ptr;
    }
}

void free_int_list2(int_list ns){
    if(ns != NULL){
        free_int_list2(ns->kid);
        free(ns);
    }else{
        free(ns);
    }
}

int_list list_carre(int_list ns){
    int_list r = NULL;
    while(ns != NULL){
        r = cons(carre(ns->first), r);
        ns = ns->kid;
    }
    int_list rr = rev(r);
    free_int_list(r);
    return rr;
}

void rev2(int_list *ns){
    int_list prev, cur, next;
    prev = NULL;
    cur = *ns;
    while (cur != NULL)
    {
        next = cur->kid;
        cur->kid = prev;
        prev = cur;
        cur = next;
    }
    *ns = prev;
}

int main(){
    return 0;
}