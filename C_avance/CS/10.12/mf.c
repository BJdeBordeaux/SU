// #include "mf.h"
#include <stdio.h>

float var = 12;

int f1(int a, float b){
	printf("This is a and b: %d %.2f from f1\n", a, b);
	return a+b;
}

void f2(float a, char s[]){
	printf("This is a and s: %.2f and %s \n", a, s);
}