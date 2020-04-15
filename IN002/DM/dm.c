#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define N 5
// première occurrence
int indice_min(int t[], int len){
	int mini = t[0];
	int indice,i;
	for(i = 1; i< len ; i++){
		if(t[i]<mini){
			mini = t[i];
			indice = i;
		}
	}
	return indice;
}

void remplace_min_if_sup(int n, int *t, int len){
	int im = indice_min(t,len);
	if(t[im]<n){*(t+im)=n;}
}

int *t_best(int n, int t[], int len){
	int *res = malloc(n*sizeof(int));
	for(int i = 0; i < n ; i++){
		res[i] = t[i];
	}
	for(int i = n; i < len; i++){
		remplace_min_if_sup(t[i],res,n);
	}
	return res;
}

void echange(int t1[], int t2[], int len){
	int t;
	for(int i = 0; i<len; i++){
		// printf("t1, t2: %d, %d\n", t1[i],t2[i]);
		if(t1[i]<t2[i]){
			t = t1[i];
			t1[i] = t2[i];
			t2[i] = t;
		}
		// printf("t1, t2: %d, %d\n", t1[i],t2[i]);
	}
}

int main(){
	int t[N] = {4,3,5,1,7};
	assert(indice_min(t,N)== 3);
	int *b = t_best(3,t,N);
	printf("%d %d %d\n",b[0], b[1],b[2]);
	echange(t,t+2,2);
	printf("(%d)\n",*t);
	printf("(%d)\n",t[1]);
	printf("(%d)\n",t[2]);
	printf("(%d)\n",t[3]);
	return 0;
}