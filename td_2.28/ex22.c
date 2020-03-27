#include<stdio.h>
#include<stdlib.h>

char *int2str(int i){
	int tem = i, cpt = 0;
	while(tem/10!=0){
		cpt++;
		tem /= 10;
	}
	int tl = cpt+1;
	char *ch = malloc(sizeof(char)*tl);

	tem = i;
	for(int j = cpt; j >= 0 ; j--){
		ch[j] = (tem%10)+48;
		tem /= 10;
		// printf("%c\n",ch[j]);
	}
	
	return ch;
}

int main(){
	char *ch = int2str(361);
	printf("%s\n",ch);

	return 0;
}