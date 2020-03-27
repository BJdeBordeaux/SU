#include "fifo.c"


int main(){
    fifo f1 = new_fifo();
    f1 = add(1,f1);
    f1 = add(2,f1);
    // printf("%d\n",peekd(f1));
    print_fifo(f1);
    f1 = pop(f1);
    print_fifo(f1);
    addq(3,&f1);
    // print_fifo(f1);
    // check_fifo(f1);
    // popd(&f1);
    // check_fifo(f1);
    // printf("take f1 :%d\n",take(&f1));
    check_fifo(f1);

    fifo2 f2 = f1.last;
    f2->kid = f1.first;
    add2(4, f2);
    check_fifo(f1);
    pop2(f2);
    check_fifo(f1);
    return 0;
}