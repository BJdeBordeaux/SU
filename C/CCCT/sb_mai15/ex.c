#include <stdio.h>
#include <stdlib.h>

// pt 31/65;

/*
Q1
il n'est pas executable 
variable b n'est pas utilisee

Q2
il se compile
affichage :
"Vive la France!
"

//pt : 2

Q3
1. float a; float *pa = &a;
2. int b = 17; int *pb = &b;
3. correct
4. int d = 51; float e; float *pe = &e; *pe = d*1.0;
//4.correct : conversion automatique

//pt : 3

Q4
T T F T

correction : 
T F F F

Q5
les deux se compilent
ils affichent :
"1
2
3
4
5"


// A can't be compiled.
//function returns address of local variable


*/

float puissance(float x, int n){
    if(n == 0){
        return 1;
        //should return 1.0
    }
    if(n%2 == 0){
        return puissance(x*x, n/2);
    }
    return x*puissance(x*x, (n-1)/2);
}

// pt = 3

void motdepass(char t[], int n){
    int i;
    for(i = 0; i < n; i++){
        t[i] = rand()%26+ 'A';
    }
    t[i] = '\0';
    //t[n] = '\0';
}

//pt = 4


#define N 5
#include <time.h>

int comparechaines(char *c1, char *c2){
	//advise: (cahr mot1[], char mot2[])
    while(*c1 == *c2 && *c1 != '\0' && *c2 != '\0'){
        c1++;
        c2++;
    }
    
    if(*c1 == *c2 && *c1 == '\0'){
        return 1;
    }
    return 0;
    //should return (mot1[i] == mot[2])
}

// pt = 4

int secondesaujourdhui(){
    return time()%24*60*60;
    //cor : ... time(NULL) ...
}

int *heuresminutessecondes(int t){
	int res = malloc(3*sizeof(int));
	int h = t/3600;
	int min = (t%3600)/60;
	int s = t%60;
	res[0] = h;
	res[1] = min;
	res[2] = s;
	return res;
}

/*
advise:
void heuresminutessecondes(int t, int *h, int *m, int *s){
	*h = t/3600;
	*m = (t%3600)/60;
	*s = t%60;
}
*/
// pt = 4

void affichetemps(int sec){
	int t[3] = heuresminutessecondes(sec);
	//int h, m, s;
	h = t[0];
	m = t[1];
	s = t[2];
	
	printf("%dh %dm %ds", h, m, s);
}

/*
advise:
void affichetemps(int sec){
	int h, m, s;
	heuresminutessecondes(sec, &h, &m, &s);
	printf("%dh %dm %ds", h, m, s);
}

*/

void affichehorloge(){
	affichetemps(secondesaujourdhui());
}

// pt = 1;

//Q14

void h(char c) {
    printf("%c\n", c);
}
void f(int x, int *a, float *b) {
    *a = *a + x;
    printf("%f\n", *b);
}
float g(char d, char *c, int *a, float *b) {
    int t;
    *c = d;
    printf("%d\n", *a);
    t = *c - 'A';
    f(t, a, b);
    return 1664.0 * (*b);
}

// pt = 5;

//P6 train

#define TRAIN_TGV 1
#define TRAIN_CORAIL 2
#define TRAIN_TER 3
#define TRAIN_NUIT 4
#define TRAIN_ICE 5
#define TRAIN_EUROSTAR 6
#define TRAIN_SPECIAL 7
#define NOMBRE_TRAINS 8
#define NOMBRE_GARES_INTERNATIONALES 5

struct train {
    int numero;
    int type;
    char gare_depart[64];
    char gare_arrivee[64];
    int heure_depart;
    int heure_arrivee;
    float prix;
};

struct traduction {
	char nom_francais[64];
	char nom_international[64];
};

int testgareinternationale(char gare[], struct traduction t[], int len){
	int i;
	int res = -1;
	for(i = 0; i < len; i++){
		if((comparechaines(gare, t.nom_francais[i]))){
		//cor: if((comparechaines(gare, t[i].nom_francais))){
			res = i;
		}
	}
	return res;
}
/*
cor:
int testgareinternationale(char gare[], struct traduction t[], int len){
	int i = 0;
	while(i < len && !comparechaines(gare, t[i].nom_francais)){
			i++;
	}
	if(i == len){
		return -1;
	}
	return i;
}
*/


//don't use switch, but if and embed them one another
void affichetypetrain(int t){
	switch(t){
		case 1 : printf("TGV");
		break;
		case 2 : printf("CORALL");
		break;
		case 3 : printf("TER");
		break;
		case 4 : printf("CNL");
		break;
		case 5 : printf("ICE");
		break;
		case 6 : printf("EUROSTAR");
		break;
		case 7 : printf("STECIAL");
		break;
		default : printf("AUTRE");
		break;
	}
}

// pt = 3;

void affichetrain(struct train t, int taille,
	struct traduction gares_internationales[]) {

	int type = t.type; 
	int n = t.numero;
	char *gdp = t.gare_depart;
	char *gar = t.gare_arrivee;
	int hdp = t.heure_depart;
	int har = t.heure_arrivee;
	float p = t.prix;
	int dpi = testgareinternationale(gdp);
	int ari = testgareinternationale(gar);
	affichetrain(type);
	printf(" %d %s ", n, gdp);
	if(dpi){
	//cor: (if dpi >= 0)
		char *gdp2 = gares_internationales[dpi];
		printf(" (%s) ",gdp2);
	}
	affichetemps(hdp);
	printf(" %s ", gar);
	if(ari){
	//cor: if(ari>=0)
		char *gar2 = gares_internationales[ari];
		printf(" (%s) ",ari2);
		//cor: printf(" (%s) ",gar2);
		
	}
	affichetemps(har);
	printf(" %f EUR", p);
	//cor: printf(" %f EUR\n", p);
}

int differencetemps(int t1, int t2) {
	if(t1 <= t2){
		return t2 - t1;
	}else{
		return (24*60*60 - t1) + t2;
	}
}

//pt = 2;

int cherchetraindirect(char gare_depart[],char gare_arrivee[],
					int heure_depart,struct train trains[],
					int trains_ignores[],int taille){

	int i;
	//cor: struct train t;
	for(i = 0; i < taille; i++){
		struct train t = trains[i];
		//cor: t = trains[i];
		if((differencetemps(heure_depart,24*60*60-1) < differencetemps(t.heure_depart, 24*60*60-1) ) && 
			comparechaines(t.gare_depart, gare_depart) &&
			comparechaines(t.gare_arrivee, gare_arrivee) &&
			trains_ignores[i] == 0){
			return i;
		}
	}
	return -1;
}
/*
advise: 
int cherchetraindirect(char gare_depart[],char gare_arrivee[], int heure_depart,struct train trains[],
					int trains_ignores[],int taille){

	int i;
	int imin = -1;
	int init = 0;
	struct train t = malloc(sizeof(struct train));
	for(i = 0; i < taille; i++){
		t = trains[i];
		if( !trains_ignores[i] && 
		comparechaines(t.gare_depart, gare_depart) && 
		comparechaines(t.gare_arrivee, gare_arrivee) && ){
		//step 1: train that satisfying the condition
			if(init){
				if(differencetemps(heure_depart, t.heure_depart) < differencetemps(heure_depart, t[imin].heure_depart)){
					imin = i;
				}
			}else{
				init = 1;
				imin = i;
			}
			//step 2: earlier train
		}
	}
	if(init){
		return imin;
	}
	return -1;
}
//if the initial condition is different from the common one, add init
*/

int main(){
    char t[N];
    //cor : char[N+1];
    //because array of char don't contain '\0' automatically
    srand(time(NULL));
    motdepass(t, N);
    printf("%s\n",t);

//Q14
    int a;
    float b;
    char c;
    char c2;
    float e;
    a = 17;
    b = 42.0;
    c = 'X';
    f(42, &a, &b);
    e = g('B', &c, &a, &b);
    h(c);
    printf("%c -> %f -> %d\n", c2, e, a);
    return 0;
}

