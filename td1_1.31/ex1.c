#include<assert.h>

int addtion (int a, int b){
	return a + b;
}

int main(){
	assert(addtion(3, 5) == 8);
	return 0;
}