GCC_FLAGS=-Wall -g 
EXEC= main_liste main_arbre main_abr main_arbre_tab main_mot_le_plus_long main_carre_magique 

all: $(EXEC)

clean:
	rm -f *.o $(EXEC)

.c.o:   
	gcc $(GCC_FLAGS) -c $*.c

main_liste: main_liste.o liste.o
	gcc ${GCC_FLAGS} -o $@ $^

main_abr: main_abr.o liste.o abr.o
	gcc ${GCC_FLAGS} -o $@ $^

main_arbre: main_arbre.o liste.o arbre_lexicographique.o
	gcc ${GCC_FLAGS} -o $@ $^

main_arbre_tab: main_arbre_tab.o liste.o arbre_lexicographique_tab.o
	gcc ${GCC_FLAGS} -o $@ $^

main_mot_le_plus_long: main_mot_le_plus_long.o liste.o arbre_lexicographique_tab.o mot_le_plus_long.o
	gcc ${GCC_FLAGS} -o $@ $^

main_carre_magique: main_carre_magique.o carre_magique.o liste.o arbre_lexicographique_tab.o
	gcc ${GCC_FLAGS} -o $@ $^
