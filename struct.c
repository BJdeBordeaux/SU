#include<stdio.h>
#include<stdlib.h>

struct nb
	{
		int nb1;
		int nb2;
	};
typedef struct nb anb;

struct nb2
	{
		int nb1;
		int nb2;
		struct nb2 *son;
	};
typedef struct nb2 *anb2;

struct nb nb_construct(int a, int b){
	struct nb mynb;
	mynb.nb1 = a;
	mynb.nb2 = b;
	return mynb;
}

anb2 nb_construct2(int a, int b,anb2 son){
	anb2 mynb = malloc(sizeof(struct nb2));
	mynb->nb1 = a;
	mynb->nb2 = b;
	mynb->son = son;
	return mynb;
}

void nb_move(struct nb* mynb, int n1, int n2){
	(*mynb).nb1 += n1;
	(*mynb).nb2 += n2;
}

void nb_move2(struct nb* mynb, int n1, int n2){
	mynb->nb1 += n1;
	mynb->nb2 += n2;
}

void print_anb2(anb2 this){
	while(this!= NULL){
		printf("nb1: %d, nb2: %d\n",this->nb1, this->nb2);
		this = this->son;
	}
	printf("\n");
}

int somme_anb2(anb2 this){
	int r = 0;
	while(this != NULL){
		r += this->nb1 + this->nb2;
		this = this->son;
	}
	return r;
}

int somme2_anb2(anb2 this){
	if(this->son != NULL){
		return this->nb1 + this->nb2 + somme2_anb2(this->son);
	}else{
		return 0;
	}
}

int main(){
	

	struct nb mynb;
	mynb.nb1 = 1;
	mynb.nb2 = 2;
	printf("nb1: %d\nnb2: %d\n", mynb.nb1, mynb.nb2);

	struct nb mynb2= nb_construct(22,33);
	printf("nb1: %d\nnb2: %d\n", mynb2.nb1, mynb2.nb2);
	nb_move(&mynb2,1,2);
	printf("nb1: %d\nnb2: %d\n", mynb2.nb1, mynb2.nb2);
	nb_move2(&mynb2,-1,-2);
	printf("nb1: %d\nnb2: %d\n", mynb2.nb1, mynb2.nb2);

	anb2 nb2t1 = nb_construct2(55,44,nb_construct2(33,22,nb_construct2(11,0,(NULL))));
	printf("This is initially anb2t1\n");
	print_anb2(nb2t1);
	printf("The somme of nb2t1: %d\n",somme_anb2(nb2t1));
	printf("The somme of nb2t1 (recursive): %d\n",somme_anb2(nb2t1));
	return 0;
}