#include<stdio.h>
#include<assert.h>

float multi(int a, float b){
	printf("%d * %.2f = %.2f",a, b, a*b);
	return a * b;
}

int main(){
	assert(multi(5, 2.5) == 12.5);
	assert(multi(3, 0) == 0);
	assert(multi(0, 3) == 0);

	multi(5, 2.5) == 12.5;
	
	return 0;
}