#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include <stdlib.h>
#include <string.h>

char *strappend(char *s1, char *s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int len = len1+len2;
	char *r = malloc(len+1);
	int i;
	for (i=0; i < len1; i++) { r[i] = s1[i]; }
	for (i=0; i < len2; i++) { r[len1+i] = s2[i]; }
	r[len] = '\0';
	return r;
}

char *strappend2(char *s1, char *s2){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	char *r = malloc(len1 + len2 + 1);
	char *a = r;
	while(*s1){*a = *s1; a++; s1++;}
	while(*s2){*a = *s2; a++; s2++;}
	*a = '\0';
	return r; 
}

char *strappend3(char *s1, char *s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int len = len1+len2;
	char *r = malloc(len+1);
	strcpy(r,s1);
	strcat(r,s2);
	return r;
}

int main(){
	// char s1[] = "hello ";
	// char s2[] = "world.";
	// char *s3 = strappend(s1,s2);
	// printf("s1: %s\ns2: %s\n s3: %s\n", s1, s2, s3);

	// char s1[] = "hello ";
	// char s2[] = "world.";
	// char *s3 = strappend2(s1,s2);
	// printf("s1: %s\ns2: %s\n s3: %s\n", s1, s2, s3);

	char s1[] = "hello ";
	char s2[] = "world.";
	char *s3 = strappend3(s1,s2);
	printf("s1: %s\ns2: %s\n s3: %s\n", s1, s2, s3);
	return 0;
}