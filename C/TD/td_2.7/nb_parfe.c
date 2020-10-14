#include<stdio.h>
#include<assert.h>

int sommeDiviseurs(int n){
	int s = 0;
	for(int i = 2; i < n; i++){
		if(n % i == 0)
			s += i;
	}
	return s;
}

int k_parfait(int n, int k){
	int s = sommeDiviseurs(n) + 1 + n;
	if(s == k*n){
		return 1;
	}
	return 0;
}