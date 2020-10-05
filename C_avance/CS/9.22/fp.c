#include <stdio.h>
// if the reference is transfered into a function
// its value can be affected by the function
// ex. f(int t[]), f(int *a)
void m(int a){
	a = 4;
}

void m2(int *a){
	*a = 4;
}

void f1(int b[]){
	b[2] = 333;
}

int main(){
	int a = 5;
	m(a);
	printf("a = %d\n", a);
	m2(&a);
	printf("a = %d\n", a);

	int b[] = {0,1,2,3};
	for (int i = 0; i < 4; i++)
	{
		printf("b[%d] = %d\n",i,b[i]);
	}
	f1(b);
	for (int i = 0; i < 4; i++)
	{
		printf("b[%d] = %d\n",i,b[i]);
	}
	return 1;
}