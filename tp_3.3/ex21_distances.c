#include<stdio.h>
#include<stdlib.h>
#define NB_VILLE 5

int dist[NB_VILLE][NB_VILLE+1]={
	{29,0,599,900,504,995},
	{59,598,0,407,203,861},
	{67,900,407,0,397,621},
	{75,504,203,397,0,694},
	{83,995,861,621,694,0},
};

void affiche_distances(int dist[NB_VILLE][NB_VILLE+1]){
	printf("km        ");
	for (int i = 0; i < NB_VILLE; i++)
	{
		printf("%-10d",dist[i][0]);
	}
	printf("\n");
	for (int i = 0; i < NB_VILLE; i++)
	{
		for (int j = 0; j < NB_VILLE+1; j++)
		{
			if(dist[i][j] != 0){
				printf("%-10d",dist[i][j]);
			}else{
				printf("--        ");
			}
		}
		printf("\n");
	}
	
}

int main(){
	affiche_distances(dist);
	return 0;
}