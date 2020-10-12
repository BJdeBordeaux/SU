Animal *ajouter_en_tete_animal(Animal *liste, Animal *animal){
	animal->suivant = liste;
	liste = animal;
	return liste;
}
unsigned int compte_animal_it(Animal *la){
	int c = 0;
	Animal *t = la;
	while(*t){
		c++;
		t = t->suivant;
	}
	return c;
}


unsigned int compte_animal_rec(Animal *la){
	if(!*la){return 0;}
	else if(!*la->suivant){return 1;}
	else{return compte_animal_rec(*la->suivant)+1;}
}
