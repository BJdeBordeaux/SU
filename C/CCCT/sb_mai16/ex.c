// pt 34/60

//advise:
// 1. use s[i] instead of char *s
// 2. for rotation: begin: i = 1; s[i-1] = s[i]
//		last char: s[l-1] (s[l] is '\0'), l = strlen(s)
// 3. unify the type: int h(int *a, int *b, int c), no! 
//		should int *c to avoid error
// 4. there is no bool in C, but int
// 5. watch float type which may be mistaken by int
// 6. about find imin/imax, no need to difine max, min
//		but t[imin], t[imax]
// 7. to upper: s[i] = 'A' + s[i] - 'a';
// 8. if there are steps, we can use the structure below:
/*
	
	st1 = 1; st2 = 0; st3 = 0;
	while((s[i] != '\0') && (!end)){
		if(st1){
			...
			if(cond1){
				st1 = 0;
				st2 = 1;
			}
		} else if(st2){
			if(cond2){
				st2 = 0;
				st3 = 1;
			}
		} else{
	
		}

		//if we want to find an indice
		if(!end){
			i++;
		}
	}
*/

/*
Q1 non elle  n'obtient pas d'executable.
1. utiliser "printf" sans inclure bibliotheque <stdio.h>
2. variabel a est declaree mais n'est pas affectee.
3. variable c est de type flotant mais utilise comme entier
comme -Werror traite tous les avertissement comme erreurs, le fichier ne se compile pas.
*/

// pt = 4



// Q2
//should include first, then define A and B
#define A 1664
#define B 17
#include <stdio.h>

// pt = 3


//Q3 F F F T

//   F T F T

// pt = 1

/*
Q4
1. correct
2. incorrect : pb est de type pointeur, non char
	 ... *pb = 'L' ...;
3. incorrect : c est un int, non float
	... int *pc = &c;
4. correct
*/

// pt = 4

// Q5
struct vetement{
	char description[33];
	int taille;
	//cor : float taille;
	bool femme;
	//cor : int femme;
	//bool do not exist in C
}

// Q6
int suite_u(int n){
	if(n == 0){
		return 42;
	}
	if(n == 1){
		return 17;
	}else{
		return 2*suite_u(n-1) - 3*suite_u(n-2);
	}
}

// pt = 4

// Q7
float exponentielle(float x){
	if((-0.01 <= x) && (x <= 0.01)){
		return 1 + x + 0.5*x*x;
	}else{
		return exponentielle(x/2)*exponentielle(x/2);
	}
}

// pt = 5

// Q8
int longueur(char s[]){
	int r = 0;
	while(*s != '\0'){
		r++;
		s++;
	}
	return r;
}

/*
advise:
int longueur(char s[]){
	int i;
	i = 0;
	while(s[i] != '\0'){
		i++
	}
	return i;
}
*/

// pt = 2

// Q9
void majuscule(char s[]){
	char a = 'a';
	char z = 'z';
	char A = 'A';
	char *t = s;
	while(*t != '\0'){
		if((*t>=a) && (*t<=z)){
			*t = A + (*t - a);
		}
		t++;
	}
}

/*
advise:
void majuscule(char s[]){
	int i;
	i = 0;
	while(s[i] != '\0'){
		if('a' <= s[i] && s[i] <= 'z'){
			s[i] = 'A' + s[i] - 'a';
		}
		i++;
	}
}
*/

// pt = 3

// Q10
// #include <stdio.h>

// Q11
void rotation(char s[]){
	int l = longueur(s);
	char *t = s[0];
	//cor: char *t is reference while char t is char;
	//char t = s[0];
	for(int i = 0; i < l; i++){
		s[i] = s[i+1];
	}
	s[l] = *t;
	//cor: s[l-1] = t;
}

/*
advise:
void rotation(char s[]){
	int l = longueur(s);
	char t;
	if(l != 0){
		t = s[0];
		for(int i = 1; i < l; i++){
			s[i-1] = s[i];
		}
		s[l-1] = t;
	}
}
*/


// Q12
include <stdio.h>
//cor: #include...

void f(float x, float *a, int b){
	*a = *a + x;
	printf("%d\n", b);	
}

float g(char d, int *b){
	int al = 9;
	al + = (d - 'A');
	*b += 1;
	printf("%d\n", al + b);
	//cor : ... al + *b ...
	return al*13.5;
}

void h(float *a){
	*a = 17.0;
}

//pt = 2

// Q13
void imin_imax(float t[], int l, int *imin, int *imax){
	if(!l){
	*imin = -1;
	*imax = -1;
	}
	int min = t[0];
	int max = t[0];
	for(int i = 0; i < l; i++){
		if(t[i] < min){
			min = t[i];
			*imin = i;
		}
		if(t[i] > max){
			max = t[i];
			*imax = i;
		}
	}
}

/*
advise:
void imin_imax(float t[], int l, int *imin, int *imax){
	if(!l){
		*imin = -1;
		*imax = -1;
	}
	*imin = 0;
	*imax = 0;
	int i;
	for(i = 0; i < l; i++){
		if(t[i] < t[*imin]){
			*imin = i;
		}
		if(t[i] > t[*imax]){
			*imax = i;
		}
	}
}
*/

// Q14
void affiche_min_max(float t[], int l){
	int imin, imax;
	imin_imax(t, l, &imin, &imin_imax);
	printf("min: %d, indice:%d\nmax:%d, indice:%d\n", t[imin], imin, t[imax], imax);
	//cor: min et max are float.
	//... min: %f, ... max:%f ...
}

// Q15
int indiceDeuxiemeMot(char s[]){
	int r = 1;
	bool deux = false;
	// there is no bool in C;
	char *c1 = s[0]; char a = 'a'; char z = 'z'; char A = 'A'; char Z = 'Z';
	//cor: not necessary to declare those char
	// char *c1 = s
	// better use s[i] to mark the char
	if(*c1 == '\0'){
		return 0;
	}
	char *c2 = s[1];
	// should be s+1 to run; if not, error of type
	if(*c2 == '\0'){
		return 1;
	}
	while(*c2 != '\0'){
		if(((A<= *c1) && (*c1 <= Z) || (a<= *c1) && (*c1 <= z) )&& (*c2 == ' ')){
			deux = true;
		}
		if((*c1 == ' ') && ((A<= *c2) && (*c2 <= Z) || (a<= *c2) && (*c2 <= z)) && deux){
			return r;
		}
		c1++;
		c2++;
		r++;
	}
	return r;
}

/*
advise:
int indiceDeuxiemeMot(char s[]){
	int i = 0;
	int st1 = 1;
	int st2 = 0;
	int st3 = 0;
	int end = 0;
	while((s[i] != '\0') && (!end)){
		if(st1){
			if(s[i] != ' '){
				st1 = 0;
				st2 = 1;
			}
		}else if(st2){
			if(s[i] == ' '){
				st2 = 0;
				st3 = 1;
			}
		} else{
			if(s[i] != '\0'){
				end = 1;
			}
		}
		if(!end){
			i++;
		}
	}
	return i;
}
*/

// pt = 4

// Q16
void rotationNCaracteres(char s[], int n){
	int i;
	for(i = 0; i < n; i++){
		rotation(s);
	}
}

// Q17
// #include <stdio.h>

// pt = 2;

int main() {
	
	//Q2
	int a = A;
	int b = B;
	float c = 42.25;
	printf("%d %d %.6f\n", a, b, c);
	//Q2 end

	//Q10
	char s[] = "Hola, world!";
	majuscule(s);
	printf("%s\n", s);
	//Q10 end

	//Q12
	float ag;
	int bg;
	float a = 42.0;
	bg = 1664;
	h(&ag);
	f(1.0, &ag, bg);
	a = g('B', &bg);
	printf("%f %d\n", a, bg);
	//Q12 end

	// Q17
	char s2[] = "NAITRE ET MOURIR POUR LA PAIX ";
	int len = longueur(s2);
	int l_u = 0;
	int idm;
	while(l_u <= len){
	//cor: while(l_u < len)
		printf("%s\n", s2);
		idm = indiceDeuxiemeMot(s2);
		l_u += idm;
		rotationNCaracteres(s2, idm);
	}

	return 0;
}


