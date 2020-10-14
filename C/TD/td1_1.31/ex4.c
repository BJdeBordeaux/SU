#include<stdio.h>
#include<assert.h>


int signeSomme(int a, int b){
	int x = a + b;
	if(x > 0){
		return 1;
	}else if(x < 0){
		return -1;
	}else{
		return 0;
	}
}

int main(){
	assert(signeSomme(1,3) == 1);
	assert(signeSomme(3,1) == 1);
	assert(signeSomme(-1,3) == 1);
	assert(signeSomme(-3,1) == -1);
	assert(signeSomme(-1,-3) == -1);
	assert(signeSomme(3,-3) == 0);
}