#include <stdio.h>
int main(){
	printf("Enter your number :");
	int n;
	if(scanf("%d",&n)){
		switch(n){
		case 1:
			printf("Hello World\n");
			break;
		case 2:
			printf("I don't know.\n");
			break;
		default:
			printf("Default\n");
			break;
		}
	}
}