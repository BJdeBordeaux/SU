#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
    indice和array对应tt[ii],t[i]
    循环中两边轮换的结构
    while(ii<len){
        if(i1<len){}
        if(i2<c){}
    }
    区间公式：　i1+rand()%(i2-i1+1);
    不用malloc如果不返回的东西或只返回１个
    用的话不返回记得free
    传入的cs如果可以直接cs->suivant(iterate)，不用创建tem
    如果取了第一个，循环外走下去，循环底再走一遍
    r = c->d;
    c = c->s;
    while(c){...; c = c->s;}
    反向ｆｏｒ　for(i=len-1;i>-1;i--)
    类似于ajouter_tete的函数，如果返回第一个，记得res = ajouter_tete(...,res);然后用反向for（因为从最后一个开始构建）
*/

void print_int_table(int *t, int len){
    int i;
    for(i = 0; i < len; i++){
        if(i%10 == 0){printf("\n");}
        printf("(%d)  ",t[i]);
    }
}
//for printing the content of an array

int *creer_len(int len){
    int *res = malloc(sizeof(int)*len);
    for (int i = 0; i < len; i++){res[i] = i;}
    return res;
}

void deplacer(int i, int t[]){
    int x = t[0];
    int j;
    for(j = 0; j<i ; j++){t[j]=t[j+1];}
    t[i] = x;
}
//exchange of mutiple values

void coupe(int c, int t[], int tt[], int len){
    int i;//indice for original array
    int ii = 0;//indice for new array
    for(i = c; i<len ; i++){
        tt[ii] = t[i];
        ii++;//if there's 2 increment, write it in the accolades
    }
    for(i = 0; i<c ; i++){
        tt[ii] = t[i];
        ii++;
    }
}

void intercale(int c, int t[], int tt[], int len){
    int i1 = 0;
    int i2 = c;//indice of original array
    int ii = 0;//indice of new array
    while(ii<len){//if ii doesn't reach the end
        if(i2<len){
            tt[ii] = t[i2];
            i2++;
            ii++;
        }
        if(i1<len){
            tt[ii] = t[i1];
            i1++;
            ii++;
        }//alternative way and condition control
    }
}

int randb(int i1, int i2){
    return i1+rand()%(i2-i1+1);
}

int *battre(int len){
    int *t = creer_len(len);
    int tt[len];//decalre an array in stead of using malloc
    int d = randb(1,len-1);
    deplacer(d,t);
    for (int i = 0; i < 42; i++)
    {
        coupe(len/2-1, t, tt, len);
        intercale(len/2-1, tt, t, len);
    }
    return t;
}

struct s_carte {
    char *figure;
    char *couleur;
    struct s_carte *suivant;
};
typedef struct s_carte carte;

int hauteur_carte(carte c){return 0;}

int carte_sup(carte c1, carte c2){
    return (strcmp(c1.couleur,c2.couleur) == 0//watch out if it's coulour or figure
     && hauteur_carte(c1)>hauteur_carte(c2));
}

carte carte_min(carte *cs){//parameter can be used in the function
    //in condition of it's use to iterate
    carte res = *cs;//declare r just like the type of return value
    cs = cs->suivant;
    //no need to declare tem, either mv to store min value
    while(cs){//cs->suivant can loss the last element
        //if we put cs = cs->suivant, then cs can be NULL;
        if(hauteur_carte(*cs)<hauteur_carte(res)){//mind the type of cs and res
            res = *cs;//mind if we need min ou max
        }
        cs = cs->suivant;
    }
    return res;
}
//we take the first element of list and in the while circle,
// the instruction to iterate should be in the end

carte *ajouter_carte(char *fig, char *coul, carte *cs){
    carte *tete = malloc(sizeof(carte));
    tete->figure = fig;
    tete->couleur = coul;
    tete->suivant = cs;
    return tete;
}

carte *liste_cartes_sup(carte c, carte *cs){
    carte *res = NULL;
    // int h = hauteur_carte(c);
    // carte *tem = cs;
    while(cs){
        if(carte_sup(cs,c)){
            res = ajouter_carte(cs->figure,cs->couleur,res);
        }//if "ajouter" function for a list has return value, reaffect res
        cs = cs->suivant;
    }
    return res;
}

char *figure_of_num(int n){
    return "figure";
}

char *couleur_of_num(int n){
    return "couleur";
}

carte *battre_cartes(int len){
    int *b = battre(len);
    carte *res = NULL;
    for(int i = len-1 ; i>-1 ; i--){//the order is dicreasing
        res = ajouter_carte(figure_of_num(b[i]),couleur_of_num(b[i]),res);
    }
    free(b);//with malloc, the memory allocated (malloc) should be free
    return res;
}

struct s_joueurs{//remenber to add "s_" for struct to avoid confusion
    carte *premier;
    carte *seconde;
};
typedef struct s_joueurs joueurs;

joueurs *distrubuer(int len){
    joueurs *res;//no need to malloc
    carte *cs = battre_cartes(len);
    carte *res.premier = NULL;
    carte *res.seconde = NULL;//associate the variable with its structure to make it more explicite
    carte *tem;//to free the memory allocated for carte
    while(cs){//use cs instead of tem to iterate
        res.premier = ajouter_carte(cs->figure,cs->couleur,res.premier);
        tem = cs;
        cs = cs->suivant;
        free(tem);
        res.seconde = ajouter_carte(cs->figure,cs->couleur,res.seconde);
        tem = cs;
        cs = cs->suivant;
        free(tem);
    }
    return res;
}

int main(){
    // int *t = creer_len(6);
    // print_int_table(t, 6);
    // deplacer(3,t);
    // print_int_table(t, 6);
    // int * tt = malloc(6*sizeof(int));
    // coupe(3,t,tt,6);
    // intercale(3,t,tt,6);
    // intercale(4,t,tt,6);
    // intercale(2,t,tt,6);
    // print_int_table(t,6);
    // print_int_table(tt,6);
    // int *ba = battre(54);
    // print_int_table(ba,54);
    return 0;
}