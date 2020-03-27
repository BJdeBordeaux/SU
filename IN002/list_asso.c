#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct acell
{
    char *name;
    int score;
    struct acell *kid;
};
typedef struct acell acell_t;

acell_t *add(char *name, int score, acell_t *kid_acell){
    acell_t *r=malloc(sizeof(acell_t));
    r->name = name;
    r->score = score;
    r->kid = kid_acell;
    return r;
}

int get_score_rec(char *name, acell_t *ls){
    if(ls == NULL){
        return -1;
    }else if(strcmp(name, ls->name) == 0){
        return ls->score;
    }else{
        return get_score_rec(name, ls->kid);
    }
}

int get_score_im(char *name, acell_t *ls){
    while(ls != NULL){
        if(strcmp(ls->name, name) == 0){
            return ls->score;
        }else{
            ls = ls->kid;
        }
    }
    return -1;
}

acell_t *supprime_name_rec(char *name, acell_t *ls){
    // printf("marque %d\n",1);
    if(ls != NULL){
        // printf("marque %d\n",2);
        if(strcmp(ls->name, name) == 0){
            // printf("marque %d\n",3);
            // acell_t *d = ls;
            // printf("marque %d\n",31);
            ls = ls->kid;
            // printf("marque %d\n",32);
            // free(d);
            // printf("marque %d\n",4);
        }else{
            printf("marque %d\n",5);
            ls->kid = supprime_name_rec(name, ls->kid);
        }
    }
    printf("marque %d\n",6);
    return ls;
}

acell_t *supprime_name_im(char *name, acell_t *ls){
    if(ls != NULL){
        if(strcmp(ls->name, name) == 0){
            // acell_t *d = ls;
            ls = ls->kid;
            // free(d);
        }else{
            acell_t *ptr1 = ls;
            acell_t *ptr2 = ls->kid;
            while(ptr2 != NULL && strcmp(name, ptr2->name)!=0){
                ptr1 = ptr1->kid;
                ptr2 = ptr2->kid;
            }
            if(ptr2 != NULL){
                // acell_t *d = ptr2;
                printf("ptr1 %s, ptr2 %s\n",ptr1->name,ptr2->name);
                ptr1->kid = ptr2->kid;
                // free(d);
            }
        }
    }
    return ls;
}

void print_acell(acell_t *ns){
    if(ns != NULL){
        printf("name : %s, score: %d\n", ns->name, ns->score);
        print_acell(ns->kid);
    }else{
        printf("done\n");
    }
}

int main(){
    acell_t c = {"c", 3, NULL};
    acell_t b = {"b", 2, &c};
    acell_t a = {"a", 1, &b};

    acell_t q = {"b",1, &a};

    acell_t d = {"d",4, NULL};
    acell_t e = {"e",5, &d};

    // printf("im name: %s, score: %d\n","b",get_score_im("b",&a));
    // printf("rec name: %s, score: %d\n","b",get_score_rec("b",&a));
    // print_acell(supprime_name_im("b",&q));
    // print_acell(&q);
    print_acell(supprime_name_rec("b",&q));
    
    printf("yes!\n");
    return 0;
}