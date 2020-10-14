#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

typedef struct point {
    int x;
    int y;
    char couleur[11];
} point;

typedef struct rectangle {
    point bg;
    point hd;
    char couleur_traits[11];
    char couleur_fond[11];
} rectangle;

int point_dans_rec(point pt, rectangle rec){
    return (pt.x >= rec.bg.x && pt.x <= rec.hd.x && pt.y <= rec.bg.y  && pt.y >= rec.hd.y);
}

rectangle intersection_rectangle(rectangle r1, rectangle r2){
    rectangle inter;
    strcpy(inter.couleur_fond, "gris");
    strcpy(inter.couleur_traits, "gris");
    inter.hd.y = max(r1.hd.y, r2.hd.y);
    inter.hd.x = min(r1.hd.x, r2.hd.x);
    inter.bg.y = max(r1.bg.x, r2.bg.x);
    inter.bg.x = min(r1.bg.y, r2.bg.y);
    return inter;
    
}

int main(){
    point mon_pointA;
    mon_pointA.x = 3;
    mon_pointA.y = 5;
    strcpy(mon_pointA.couleur, "rouge");// don't do that : s[11] = 'no';
    //use strcpy or s[]; s = 'blabla';
    point mon_pointB = {6, 2, "white"};// respect the order
    point points[2][2]= {{{1,2,"rouge"}, {3,4,"black"}},{{5,6,"rouge"}, {7,8,"black"}}};

    printf("pointA (%d, %d) %s\n",mon_pointA.x, mon_pointA.y, mon_pointA.couleur);
    printf("pointB (%d, %d) %s\n",mon_pointB.x, mon_pointB.y, mon_pointB.couleur);

    rectangle mon_rectangle;
    mon_rectangle.bg = mon_pointA;
    mon_rectangle.hd = mon_pointB;
    strcpy(mon_rectangle.couleur_fond, "rouge");
    strcpy(mon_rectangle.couleur_traits, "blanc");

    rectangle mon_rectangle2 = {mon_pointA, mon_pointB, "rouge", "blanc"};

    assert(point_dans_rec(mon_pointA, mon_rectangle));
    assert(point_dans_rec(mon_pointB, mon_rectangle2));
}