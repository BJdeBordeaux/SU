#include<stdio.h>

int tableau(){
	// int ns[42];

	return 0;
}

int main(){
	// int tb1[3] = {1,3};
	float tb2[3] = {2.5, 1.5, 0.5};
	tb2[1] += 1;
	float tb3[][3]={{1, 2, 3,}, {4, 5, 6, }, {7, 8, 9} ,};
	printf("%f, %f, %f\n",tb3[0][0], tb3[1][1], tb3[1+1][2]);
	printf("%f, %f, %f\n",tb2[0], tb2[1], tb2[2]);
	printf("%ld, %p, %p, %p\n",sizeof(float), &tb2, &tb2[1], &tb2+sizeof(float));
	float * plomb = tb2+1;
	printf("%p\n", plomb);


	return 0;
}

void copy_array(){
	/*
	for(i = 0; i < length_of_array; i++){
		a[i] = b[i];
	} 
	*/
}

