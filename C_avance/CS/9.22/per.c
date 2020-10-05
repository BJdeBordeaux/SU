#include <stdio.h>

typedef struct _Personne{
    char nom[30];
    int age;
} Personne;

int main(){
	Personne p={"Josie", 52}; 
    p.nom="Josiane"; 

    p.age = 54;
    printf("%d\n",p.age ); 
    return 1;
}