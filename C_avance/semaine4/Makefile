GCC_FLAGS=-Wall -g 
EXEC= main_arbre main_abr main_arbre_tab 

all: $(EXEC)

clean:
	rm -f *.o $(EXEC) *~

.c.o:   
	gcc $(GCC_FLAGS) -c $*.c

main_abr: main_abr.o liste.o abr.o
	gcc ${GCC_FLAGS} -o $@ $^

main_arbre: main_arbre.o liste.o arbre_lexicographique.o
	gcc ${GCC_FLAGS} -o $@ $^

main_arbre_tab: main_arbre_tab.o liste.o arbre_lexicographique_tab.o
	gcc ${GCC_FLAGS} -o $@ $^


