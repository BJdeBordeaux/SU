#include<stdio.h>

void min_max_moy(int tab[], int l, int *mi, int *ma, float *moy);
void min_max_moy_rec(int tab[], int l, int *min, int *max, float *moy);
void print_int_table(int *t, int len);
void min_max_moy2(int tab[], int l, int *min, int *max, float *moy);
void min_max_som_rec(int tab[], int l, int *min, int *max, int *som);

int main(){
	int tab[3] = {3,1,2};
	int mini, maxi;
	float moy;
	min_max_moy2(tab, 3, &mini, &maxi, &moy);
	printf("min, max, moy : %d, %d, %.2f\n",mini, maxi, moy);
	print_int_table(tab,3);


}

void min_max_moy(int tab[], int l, int *min, int *max, float *moy){
	*min = tab[0];
	*max = tab[0];
	double s = tab[0];
	int i;
	for(i = 1; i < l; i++){
		if(tab[i]<*min){
			*min = tab[i];
		}
		if(tab[i]>*max){
			*max = tab[i];
		}
		s += tab[i];
	}
	*moy = s/l;
}

void min_max_som_rec(int tab[], int l, int *min, int *max, int *som){
	if(l>1){
		min_max_som_rec(tab+1, l-1, min, max, som);
		if(*min > tab[0]){*min = tab[0];}
		if(*max > tab[0]){*max = tab[0];}
		*som += tab[0];
	}
	*min = tab[0];
	*max = tab[0];
	*som = tab[0];
};

void min_max_moy2(int tab[], int l, int *min, int *max,float *moy){
	int som = 0;
	min_max_som_rec(tab, l, min, max, &som);
	*moy = som/1.0/l;
}

void print_int_table(int *t, int len){
    int i;
    for(i = 0; i < len; i++){
        if(i%10 == 0){printf("\n");}
        printf("(%d)  ",t[i]);
    }
    printf("\n");
}