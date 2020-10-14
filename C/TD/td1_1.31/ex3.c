#include<stdio.h>
#include<assert.h>

int plusGrand(int a, int b, int c){
	if(a>=b && a>=c){
		return a;
	}else{
		if(b >= c){
			return b;
		}else{
				return c;
			}	
	}
}

int main(){
	assert(plusGrand(1,2,3) == 3);
	assert(plusGrand(1,3,2) == 3);
	assert(plusGrand(2,1,3) == 3);
	assert(plusGrand(2,3,1) == 3);
	assert(plusGrand(3,1,2) == 3);
	assert(plusGrand(3,2,1) == 3);
	assert(plusGrand(1,1,1) == 1);
	assert(plusGrand(0,0,0) == 0);
	assert(plusGrand(2,2,5) == 5);
	assert(plusGrand(7,7,3) == 7);
	assert(plusGrand(plusGrand(1,2,3),4,5) == 5);
	return 0;	
}