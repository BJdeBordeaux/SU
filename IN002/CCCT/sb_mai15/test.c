#include <stdio.h>

int *f(){
	int a[] = {1,2,3,4,5};
	return a;
}

int main(){
	int *a = f();
	printf("%d",a[0]);
	return 0;
}