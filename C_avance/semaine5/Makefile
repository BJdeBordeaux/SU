GCC_FLAGS=-Wall -g
GCC_LIB_FLAGS=-fpic -static
CC=gcc
EXE=ex_liste_entiers ex_liste_string compte_mots
LIB=libfonctions_entiers.a libfonctions_string.a libliste.a

all: $(EXE) $(LIB)

%.o: %.c
	$(CC) $(GCC_FLAGS) -c $^

ex_liste_entiers: ex_liste_entiers.o liste.o fonctions_entiers.o
	$(CC) $(GCC_FLAGS) -o $@ $^	

ex_liste_string: ex_liste_string.o liste.o fonctions_string.o
	$(CC) $(GCC_FLAGS) -o $@ $^	

compte_mots: compte_mots.o liste.o fonctions_string.o fonctions_2entiers.o
	$(CC) $(GCC_FLAGS) -o $@ $^

lib%.a: %.c
	$(CC) $(GCC_FLAGS) $(GCC_LIB_FLAGS) -c -o $@ $^

clean:
	rm -f *.o $(EXE) $(LIB) *~ 
