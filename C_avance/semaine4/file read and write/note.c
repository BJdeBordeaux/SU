#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define PP printf
#define LONGUEURLIGNE 128


int main(){
/*	THIS PART is for strcmp() and strcpy()
	//******
	char sa[] = "HeLlo World!";
	char *sc =  "HeIlo World!";
	char sb[] = "Bonjour monde!";

	int aa = strcmp(sa, sc);
	// int ab = strncmp(sa, sc, 2);
	int ab = strncmp(sa, sc, 3);
	// int ab = strncmp(sa, sc, 4);
	PP("aa, ab = %d %d\n", aa, ab);

	char sd[] = "";
	PP("sd, sb = %s;;%s;;\n", sd, sb);
	//strcpy(sd, sb);
	// char *sf = strcpy(sd, sb);
	// char *sf = strncpy(sd, sb, 17);
	// PP("sf, sd, sb = %s;;%s;;%s;;\n", sf, sd, sb);
	char* sf = strdup(sb);
	PP("sf, sd, sb = %s;;%s;;%s;;\n", sf, sd, sb);
	//******
	*/

	/*
	THIS PART is about getchar() and putchar()
	//******
	char ca = getchar();
	putchar(ca);
	PP("\n");

	do{
		ca = getchar();
	}while(isspace(ca));
	putchar(ca);
	PP("\n");
	//******
	*/

	/*
	//READ AND WRITE NOMALLY fsvanf() and fprintf()
	//******
	FILE * fa;
	int x, y, z;
	if((fa = fopen("ta.txt", "r")) == NULL){
		PP("Error when open file\n");
		exit(1);
	}
	fscanf(fa, "%d %d %d", &x, &y, &z);
	PP("x, y, z = %d %d %d\n", x, y, z);
	fclose(fa);

	FILE *fb = NULL;
	float xa = 10, ya = 12, za = 13.5;
	char nom[] = "LI", prenom[] = "Junji";

	if(!(fb = fopen("tb.txt","a"))){
		PP("Error when open file\n");
		exit(1);
	}
	fprintf(fb, "%s, %s, %f, %f, %f\n", nom, prenom, xa, ya, za);
	fclose(fb);
	//******
	*/

	/*
	// THIS PART is for read lines in file
	// fgets() and sscanf() with while
	// ******
	FILE *fc;
	if(!(fc = fopen("ta.txt","r"))){
		PP("Error when open file\n");
		exit(1);
	}
	char buffer[LONGUEURLIGNE];
	char *res = fgets(buffer, LONGUEURLIGNE, fc);
	// int x, y, z;
	while(res){
		sscanf(buffer,"%d %d %d", &x, &y, &z);
		res =  fgets(buffer, LONGUEURLIGNE, fc);
		PP("les entiers x, y, z: %d %d %d\n", x, y, z);
	}
	fclose(fc);
	// ******
	*/

	// //THIS PART is for read file with binary lecture
	// // fopen("a.txt", "rb");
	// // ******
	// FILE *fd;
	// if(!(fd = fopen("ta.txt", "rb"))){
	// 	PP("Error when open file\n");
	// 	exit(1);	
	// }
	// int size = 10;
	// int i[size];
	// int nb_lu =fread(&i, sizeof(int), size, fd);
	// if(nb_lu != size){PP("no ok, size == %d != nb_lu == %d\n", size, nb_lu);}
	// // *******

	// // THIS PART is for binary write and read
	// // fopen("a.txt", "wb"); fopen("a.txt", "rb");
	// // fwrite(&p1, sizeof(point), 1, fe);
	// // fread(&p2, sizeof(point), 1, fe2);
	// // ******
	// typedef struct _point {
	// 	float a;
	// 	float b;
	// 	float c;
	// } point;
	// point p1 = {1, 2, 3}, p2;

	// PP("%f %f %f\n", p1.a, p1.b, p1.c);

	// FILE * fe;
	// if(!(fe = fopen("tb.txt", "wb"))){
	// 	PP("Error when open file\n");
	// 	exit(1);	
	// }
	// fwrite(&p1, sizeof(point), 1, fe);
	// fclose(fe);

	// FILE *fe2 = fopen("tb.txt", "rb");
	// fread(&p2, sizeof(point), 1, fe2);
	// fclose(fe2);
	// PP("%f %f %f\n", p2.a, p2.b, p2.c);
	// // ******


	// typedef struct _contact{
	// 	char* nom;
	// } contact;

	typedef struct _contact{
		char nom[30];
	} contact;

	// contact c = {"QIAN"}, dd;
	contact c, dd;
	c.nom = strdup("ZHAO");

	// // THIS PART is for fprint();
	// // ******
	// FILE * ff;
	// if(!(ff = fopen("tb.txt", "wb"))){
	// 	PP("Error when open file\n");
	// 	exit(1);	
	// }
	// fwrite(&c, sizeof(contact), 1, ff);
	// fclose(ff);
	// FILE * ff2;
	// if(!(ff2 = fopen("tb.txt", "rb"))){
	// 	printf("Unable to open it\n");
	// 	exit(1);
	// }
	// fread(&dd, sizeof(contact), 1, ff2);
	// PP("%s\n", dd.nom);
	// // ******
	
}