#include<assert.h>
#include<stdio.h>

int somme_carre(int m, int n){
	int s = 0;
	int j = m;
	while(j <= n){
		s += j*j;
		j++;
	}

	return s;
}

int main(){
	assert(somme_carre(1, 3) == 14);
	// printf("%d\n",somme_carre(1, 3));
	return 0;
}