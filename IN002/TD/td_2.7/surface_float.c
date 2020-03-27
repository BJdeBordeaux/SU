#include<stdio.h>
#include<assert.h>

float surface_float(float a, float b){
	return a*b;
}

float float_absolu(float a){
	if(a >= 0){
		return a;
	}else{
		return -a;
	}
}

int egal_eps(float a, float b, float c){
	if((a > b - c) | (a < b + c)){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	// assert(egal_eps(surface_float(2.5, 2.5), 6.25, 0.01) == 1);
	// assert(egal_eps(surface_float(1.3, 1.4), 1.82), 0.01 == 1);
	return 0;
}