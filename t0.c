#include<stdlib.h>
#include<stdio.h>
#include "fifo.h"

fifo new_fifo(){
    fifo r;
    r.first = NULL;
    r.last = NULL;
    return r;
}

int is_empty(fifo xs){
    return (xs.first == NULL && xs.last == NULL);
}

fifo add(int val, fifo xs){
    cell *new_cell = malloc(sizeof(cell));
    new_cell->val = val;
    new_cell->kid = NULL;

    if(is_empty(xs)){
        xs.first = new_cell;
        xs.last = new_cell;
    }else{
        xs.last->kid = new_cell;
        xs.last = new_cell;
    }
    return xs;
}

int peekd(fifo xs){
    if(!is_empty(xs)){
        return xs.first->val;
    }
    else{
        printf("Error : the fifo is empty\n");
        return -1;
    }
}

fifo pop(fifo xs){
    if(!is_empty(xs)){
        if(xs.first->kid == NULL){xs.last = NULL;}
        xs.first = xs.first->kid;
    }
    return xs;
}

void print_fifo(fifo xs){
    if(!is_empty(xs)){
        cell *c = xs.first;
        printf("[");
        while(c != NULL){
            printf("(%d)\t",c->val);
            c = c->kid;
        }
        printf("]\n");
    }else{
        printf("empty fifo\n");
    }
}

void check_fifo(fifo xs){
    if(xs.first == NULL){printf("empty first\n");}
    else{printf("first val:%d\n",xs.first->val);}
    if(xs.last == NULL){printf("empty last\n");}
    else{printf("last val:%d\n",xs.last->val);}
    int cpt = 0;
    {
        cell *c = xs.first;
        printf("[");
        while(c != NULL && (cpt < 10)){
            printf("(%d)\t",c->val);
            c = c->kid;
            cpt++;
        }
        printf("]\n");
    }
}

void addq(int val, fifo *xs){
    cell *cl = malloc(sizeof(cell));
    cl->val = val;
    cl->kid = NULL;
    if(!is_empty(*xs)){
        xs->last->kid = cl;
        xs->last = cl;
    }else{
        xs->first = cl;
        xs->last = cl;
    }
}

void popd(fifo *xs){
    if(!is_empty(*xs)){
        cell *tem = xs->first;
        xs->first = xs->first->kid;
        free(tem);
        if(xs->first == NULL){
            xs->last = NULL;
        }
    }
}

int take(fifo *xs){
    cell *d = xs->first;
    int r = d->val;
    xs->first  = xs->first->kid;
    if(xs->first == NULL){xs->last = NULL;}
    free(d);
    return r;
}

fifo2 add2(int val, fifo2 xs2){
    fifo2 res = (cell *)malloc(sizeof(cell));
    res->val = val;
    if(xs2 == NULL){
        res->kid = res;
    }else{
        res->kid = xs2->kid;
        xs2->kid = res;
    }

    return res;
}

fifo2 pop2(fifo2 xs2){
    if(xs2 == NULL){
        return NULL;
    }else if(xs2->kid == xs2){
        return NULL;
    }else{
        fifo2 d = xs2->kid;
        xs2->kid = xs2->kid->kid;
        free(d);
        return xs2;
    }
}