#include<stdio.h>

void permut_circulaire(int *a, int *b, int *c);

int main(){
	int a=10, b=20, c=30;
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	permut_circulaire(&a, &b, &c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	return 0;
}

void permut_circulaire(int *a, int *b, int *c){
	int t=*a;
	*a = *b;
	*b = *c;
	*c = t;
}