# include<stdio.h>

int longueur(char s[]){
	int r = 0;
	while(*s != '\0'){
		r++;
		s++;
	}
	return r;
}

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

void rotation(char s[]){
	int l = longueur(s);
	char t = s[0];
	for(int i = 0; i < l; i++){
		s[i] = s[i+1];
	}
	s[l-1] = t;
}

void f(float x, float *a, int b){
	*a = *a + x;
	printf("%d\n", b);	
}

float g(char d, int *b){
	int al = 9;
	al += (d - 'A');
	*b += 1;
	printf("%d\n", al + *b);
	return al*13.5;
}

void h(float *a){
	*a = 17.0;
}

// int indiceDeuxiemeMot(char s[]){
// 	int r = 1;
// 	int deux = 0;
// 	char *c1 = s; char a = 'a'; char z = 'z'; char A = 'A'; char Z = 'Z';
// 	if(*c1 == '\0'){
// 		return 0;
// 	}
// 	char *c2 = s+1;
// 	if(*c2 == '\0'){
// 		return 1;
// 	}
// 	while(*c2 != '\0'){
// 		if(((A<= *c1) && (*c1 <= Z) || (a<= *c1) && (*c1 <= z) )&& (*c2 == ' ')){
// 			deux = 1;
// 		}
// 		if((*c1 == ' ') && ((A<= *c2) && (*c2 <= Z) || (a<= *c2) && (*c2 <= z)) && deux){
// 			return r;
// 		}
// 		c1++;
// 		c2++;
// 		r++;
// 	}
// 	return r;
// }

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

void rotationNCaracteres(char s[], int n){
	int i;
	for(i = 0; i < n; i++){
		rotation(s);
	}
}

int main(){
	char s1[] = "NAITRE ET MOURIR POUR LA PAIX";
	/*
	char s2[] = "naitre et mourir pour la paix";
	majuscule(s2);
	rotation(s2);
	printf("%s : %d mots\n", s2, longueur(s2));
	*/

	/*
	float ag;
	int bg;
	float a = 42.0;
	bg = 1664;
	h(&ag);
	f(1.0, &ag, bg);
	a = g('B', &bg);
	printf("%f %d\n", a, bg);
	*/

	// int i = indiceDeuxiemeMot(s1);
	// printf("%d\n", i);
	char s2[] = "NAITRE ET MOURIR POUR LA PAIX ";
	int len = longueur(s2);
	int l_u = 0;
	int idm;
	printf("len = %d\n", len);
	while(l_u < len){
	//cor: while(l_u < len)
		printf("%s (l_u = %d)\n", s2, l_u);
		idm = indiceDeuxiemeMot(s2);
		l_u += idm;
		rotationNCaracteres(s2, idm);
	}
	return 0;
}