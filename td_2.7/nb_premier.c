#include<stdio.h>
#include<assert.h>
#include<math.h>
#define MAX 5
int premier(int a){
	if((a == 0) | (a == 1)){
		return 0;
	}
	for(int i = 2; i <= sqrt(a) ; i++){
		if(a%i == 0){
			return 0;
		}
	}
	return 1;
}

void listeNombresPremier(int n_max){
	printf("Voici les nombres premiers:\n");
	for(int i = 2; i <= n_max; i++){
		if(premier(i)){
			printf("%d ,", i);
		}
	}
	printf("...\n");

}

int main(){
	printf("liste des nombres premiers <= %d \n",MAX);
	listeNombresPremier(MAX);

	return 0;
}