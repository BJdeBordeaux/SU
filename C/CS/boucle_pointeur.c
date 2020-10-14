#include<stdio.h>

double somme(double tab[], int len){
	double r = 0;
	double *a = tab;
	for (int i = 0; i < len; i++)
	{
		r += *(a + i);
	}
	return r;
}

int main(){
	double tab[4] = {1.1, 2.2, 3.3, 4.4};
	printf("%f\n",somme(tab, 4));
	return 0;
}