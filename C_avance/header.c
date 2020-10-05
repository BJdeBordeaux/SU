#include <stdio.h>
#include <stdlib.h>

void print_int_table(int *t, int len){
    int i;
    for(i = 0; i < len; i++){
        if(i%10 == 0){printf("\n");}
        printf("(%d)  ",t[i]);
    }
    printf("\n");
}

void init_tab_int(int *t, int l){
	int i;
	//remember :int t = malloc(l*sizeof(int));
	for(i = 1; i < l+1; i++){
		t[i] = i;
	}
}

int compte_mots_chaine(char *s) {
  int n = 0;
  while(*s != '\0'){
    while(*s ==' '){s++;}
    if(*s == '\0'){return n;}
    n++;
    while((*s != ' ') && (*s)){
      *s++;
    }
  }
  return n;
}