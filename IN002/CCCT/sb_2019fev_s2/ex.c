// pt total = 30

// q1

int t[] = {1, 3, 3, 6};
int n = 4;


#include <stdlib.h>
int *somCumulee(int t[], int n){
	int *res = malloc(sizeof(int)*n);
	int s = 0;
	int i;
	for(i = 0; i < n; i++){
		s += t[i];
		res[i] = s;
	}
	return res;
}

// pt = 6

// q2
int tirerSelonScore(int t[], int n){
	int *tCumul = somCumulee(t, n);
	int a = rand()%(tCumul[n-1]);
	int i;
	for(i = 0; i < n; i++){
		if(tCumul[i] > a){
			return i;
		}
	}
}

/*
correction:
int tirerSelonScore(int tDir[], int n){//watch the variable name
	int i = 1; r = -1;
	int *tCumul = somCumulee(tDir, n);
	if(tCumul[n-1] > 0){
		r = rand()%tCumul[n-1];
		i = 0;
		while(tCumul[i] < r){i++;}
	}
	return i;
}
*/

// pt = 3

// q3
void initMonde(int monde[NB_LG][NB_COL]){
	int i, j;
	for(i = 0; i < NB_LG; i++){
		for(j = 0; j < NB_COL; j++){
			if((i == 0) || (j == 0)){
				monde[i][j] = 0;
			}else{
				monde[i][j] = 1;
			}
		}
	}
}

// pt = 3

typedef struct _tyFourmi{
	int i; // coordonnee i (ligne) de la fourmi
	int j; // coordonnee j (colonne) de la fourmi
	char sens; //sens du trajet (’A’ pour aller ou ’R’ pour retour)
	int energie; //energie de la fourmi
	struct _tyFourmi *suiv; //pointeur vers la fourmi suivante
} tyFourmi;

#define MAX_E 10

// q4
tyFourmi *insererEnTete(tyFourmi *listeFourmis){
	tyFourmi *res = malloc(sizeof(tyFourmi));
	res->i = 1;
	res->j = 1;
	res->sens = 'A';
	res->energie = rand()%(MAX_E + 1);
	res->suiv = listeFourmis;
	return res;
}

// pt = 6

// q5
#define NB_LG 5
#define NB_COL 6
void copiePheromone(int monde[NB_LG][NB_COL], tyFourmi fourmi, int tDir[]){
	int i = fourmi.i;
	int j = fourmi.j;
	tDir[0] = monde[i-1];
	// tDir[0] = monde[i-1][j];
	tDir[1] = monde[j-1];
	// tDir[1] = monde[i][j-1];
	
	if(fourmi.sens == 'R'){
		tDir[2] = 0;
		tDir[3] = 0;
	}else{
		tDir[2] = monde[i+1];
		// tDir[2] = monde[i+1][j];
		tDir[3] = monde[j+1];
		// tDir[3] = monde[i][j+1];
	}
}

// do not forget the second component of 2-d array.


// q6
void bougerUneFourmi(tyFourmi *unefourmi, int monde[NB_LG][NB_COL]){
	int tDir[4] = copiePheromone(monde);
	// int tDir[4];
	//copiePheromone(monde, unefourmi, tDir);
	int s = tirerSelonScore(tDir);
	if(s == 0){
		unefourmi->i -= 1;
	}else if(s == 1){
		unefourmi->j -= 1;
	}else if(s == 2){
		unefourmi->i += 1;
	}else{
		unefourmi->j +=1;
	}
}

// pt = 3

// q7
// #include <string.h>
int majFourmi(tyFourmi *uneFourmi, int monde[NB_LG][NB_COL]){
	unefourmi->energie -= 1;
	int i = unefourmi->i;
	int j = unefourmi->j;
	if((i == NB_LG-2) && (j == NB_COL-2)){
		unefourmi->sens = 'R';
	}
	if(unefourmi->sens == 'R'){
		monde[i][j] += 1;
	}
	if((i == 1) && (j == 1) && (unefourmi->sens == 'R')){
	//if((i == 1) && (j == 1)){
		//if(unefourmi->sens == 'R')	
		//大条件下有不同，分别设小条件判断
		//if there are several conditions, use multi-step structure

		unefourmi->sens = 'A';
		unefourmi->energie = MAX_E;
		return 1;
	}
	return 0;
}

// pt = 2;

// q8
int longueurListe(tyFourmi *pListe){
	int r = 0;
	while(pListe){
		r++;
		pListe = pListe->suiv;
	}
	return r;
}

// pt = 3

// q9
int bougerLesFourmis(tyFourmi *pListe, int monde[NB_LG][NB_COL]){
	int res = 0;
	int l = longueurListe(pListe);
	int k = 0;
	// tyFourmi *t = pListe;
	for(k = 0; k < l; k++){
	 	bougerUneFourmi(pListe, monde);
	 	//bougerUneFourmi(t, monde);
		res += majFourmi(pListe, monde);
		// res += majFourmi(t, monde);
		pListe = pListe->suiv;
		// t = t->suiv;
	}
	return res;
}

// use temporary variable, if not, pListe will be affected
// pt = 2

// q10
tyFourmi *supprimerUneFourmi(tyFourmi *pListe, tyFourmi *aSupprimer){
	tyFourmi *p = pListe;
	// if(!p){return NULL;}
	if(!p->suiv){
		return NULL;
	}
	t = pListe->suiv;
	int ok = 0;
	while(t && (!ok)){
		if((t->i == aSupprimer->i) && (t->j == aSupprimer->j) &&
			(t->sens == aSupprimer->sens) && (t->energie == aSupprimer->energie)){
		//if(t == aSupprimer)
		// 2 obj of the same structure can be compare with each other	
			tyFourmi  *d = t;
			t = t->suiv;
			p->suiv = t;
			free(d);
			ok = 1;
		}else{
			p = p->suiv;
			t = t->suiv;
		}
	}
	return pListe;
}

// parameter can be free()
// use pred if p == aSupprimer:
// pred->suiv = aSupprimer->suiv; free(aSupprimer); return pListe;

// q11
tyFourmi *supprimerFourmisMortes(tyFourmi *pListe){
	while(pListe && pListe->energie <= 0){
		tyFourmi *p = pListe;
		pListe = pListe->suiv;
		free(p);
	}
	if(!pListe){
		return NULL;
	}
	tyFourmi *t = pListe->suiv;
	//to continue
	while(t){
		if(t->energie <= 0){
			tyFourmi *d = t;
			t = t->suiv;
			p->suiv = t;
			free(d);
		}else{
			p = p->suiv;
			t = t->suiv;
		}
	}
	return pListe;
}

int main(){
	int monde[NB_LG][NB_COL];
	initMonde(monde);
	int i;
	int nur = 0;
	tyFourmi *listeFourmis = NULL;
	for(i = 0; i < 10; i++){
		listeFourmis = insererEnTete(listeFourmis);
	}
	while(listeFourmis){
		nur += bougerLesFourmis(listeFourmis, monde);
		listeFourmis = supprimerFourmisMortes(listeFourmis);
	}
	printf("La quantite de nourriture ramenee: %d\n", nur);
}

// pt = 6
