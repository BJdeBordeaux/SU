#include<stdio.h>
#include<assert.h>

void decomposition_somme(int s){
	int p5 = s/5;
	int p2 = (s%5)/2;
	int p1 = (s%5)%2;

	printf("%d est composee de %d piece de 5 euros, %d piece de 2 euros, %d piece de 1 euros.\n", s,p5, p2, p1);
}

void decomposition_multiple_somme(int s){
	for (int i = s/5; i >=0; i--)
	{
		for (int j = (s - 5*i)/2; j >= 0; j--)
		{
			printf(" 5 euros:%d, 2 euros: %d, 1 euro: %d.\n", i, j, s-5*i-2*j);
		}
	}
	
}

int main(){
	printf("Please enter a sum of euros:\n");
	int s;
	scanf("%d",&s);
	decomposition_multiple_somme(s);
	return 0;
}