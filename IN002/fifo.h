#ifndef FIFO
#define FIFO

typedef struct _cell cell;
struct _cell{
    int val;
    struct _cell *kid;
};

typedef struct _fifo fifo;
struct _fifo{
    cell *first;
    cell *last;
};

typedef cell *fifo2;

fifo new_fifo();
int is_empty(fifo xs);
fifo add(int val, fifo xs);
int peekd(fifo xs);
fifo pop(fifo xs);
void print_fifo(fifo xs);
void check_fifo(fifo xs);
void addq(int val, fifo *xs);
void popd(fifo *xs);
int take(fifo *xs);
fifo2 add2(int val, fifo2 xs2);
fifo2 pop2(fifo2 xs2);

#endif