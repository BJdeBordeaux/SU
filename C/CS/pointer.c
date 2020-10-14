//pile (variables locales, paramétres) :pointer: - mémoire non allouée (pour pile et tas) - tas (mémoire dynamique, pour image) 
// - donnée (variables globales) :global pointer: - code (instructions):program count:

// pointer: a variable that contain an adress: int *n
// we can obtain a variable's adress by the operator "&": &a
#include<stdio.h>
int main(){
	int a, b;
	int r = scanf("%d %d", &a, &b);
	if(r)
		printf("%d + %d = %d\n", a, b, a+b);
	else
		printf("Input error.\n");
	// scanf("Press any key to continue...");
	return 0;
}

void pt(){
	int a = 1;
	int * b = &a;
	printf("a, &a = %d, %p,\n *b, b, &b = %d, %p, %p\n", a, &a, *b, b, &b);
}