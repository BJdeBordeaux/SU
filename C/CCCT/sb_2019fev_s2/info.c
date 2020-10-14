//

void print_int_table(int *t, int len){
    int i;
    for(i = 0; i < len; i++){
        if(i%10 == 0){printf("\n");}
        printf("(%d)  ",t[i]);
    }
    printf("\n");
}

void print_int_table_2d(int t[][], int l1, int l2){
    int i, j;
    for(i = 0; i < l1; i++){
        for(j = 0; j < l2; j++){
        	printf("(%d)  ",t[i][j]);	
        }
        printf("\n");
    }
    printf("\n");
}

typedef struct _cellule_t cellule_t;
struct _cellule_t {
 int donnee;
 cellule_t *suivant;
};

cellule_t * creerCellule(int n, cellule_t *l) {
/* cree une cellule d'une liste*/
 cellule_t *res = malloc(sizeof(cellule_t));
 res->donnee = n;
 res->suivant = l;
 return res;
//}
//
//
//
cellule_t * creerListe(int n) {
/* cree une liste de n entiers saisi par l'utilisateur
 renvoie l'adresse du premier element de la liste */
 int i;
 int val;
 cellule_t *tete=NULL;
 cellule_t *ptr;
 
 printf("Saisie %d elements de la liste\n",n);
 for (i=0; i < n; i++) {
   printf("Element %d :",n-i);
   scanf("%d",&val);
   ptr=malloc(sizeof(cellule_t));
   ptr->donnee = val;
   ptr->suivant = tete;
   tete = ptr;
 }
 return tete;
}

void AfficherListeInt(cellule_t *l){
   // int cpt = 1;
   cellule_t *cur_l = l;
   while(cur_l != NULL){
       printf("Le element courant: %d\n", cur_l->donnee);
       cur_l = cur_l->suivant;
       // cpt++;
   }
}

  int tab[][9]={0,1,0,6,0,7,0,0,4,
               0,4,2,0,0,0,0,0,0,
               8,7,0,3,0,0,6,0,0,
               0,8,0,0,7,0,0,2,0,
               0,0,0,8,9,3,0,0,0,
               0,3,0,0,6,0,0,1,0,
              0,0,8,0,0,6,0,4,5,
              0,0,0,0,0,0,1,7,0,
              4,0,0,9,0,8,0,6,0};