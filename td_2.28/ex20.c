#include<stdio.h>
#include<string.h>

int compte(char str[], char c){
	int res = 0;
	int i = 0;
	while(str[i]){
		if(str[i]==c){
			res++;
			// printf("s:%s,c:%c\n",str+i,c);
		}
		i++;
	}
	return res;
}

void affiche_occur(char str[]){
	for(int i=0; str[i]!='\0'; i++){
		int j=0;
		while((j<i) && (str[j]!=str[i])){
			j++;
		}
		if(j==i){
		printf("le caractere %c appait %d fois.\n",str[i], compte(str,str[i]));	
		}
	}
}

int frequent(char str[]){
	int max = compte(str,str[0]);
	int res = 0;
	int i = 0;
	while(str[i]){
		if(compte(str,str[i])>=max){
			max = compte(str,str[i]);
			res = i;
		}
		i++;
	}
	return res;
}

int main(){
	char str[] = "hellow world.";
	affiche_occur(str);
	printf("le plus frequent: %c\n",str[frequent(str)]);
	return 0;
}