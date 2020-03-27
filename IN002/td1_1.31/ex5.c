#include<assert.h>

#define TNORMAL 11.4
#define TMOIS14 4.5
#define TMOIS26S 4.9
#define TMOIS26WE 7.90
#define TMATIN 7.10

float prixPlace(int a, int d, float h){
	float prix = TNORMAL;
	if(a <= 14){
		prix = TMOIS14;
	}else if(a <= 26){
		if(d >= 1 && d<=5){
			prix = TMOIS26S;
		}else{
			prix = TMOIS26WE
		}
	}
	if(h >= 8 && h<= 11 && prix >= TMATIN){
		prix = TMATIN;
	}
	return prix;
}

int main(){
	printf(prixPlace(21, 5, 17));
}
