GCC_FLAGS=-Wall -g 
CC=gcc
EXE=ex_ab_entiers ex_ab_mots main_expr
LIB=libarbre_binaire.a

all: $(EXE) $(LIB)

%.o: %.c
	$(CC) $(GCC_FLAGS) -c $^

ex_ab_entiers: ex_ab_entiers.o arbre_binaire.o fonctions_entiers.o
	$(CC) $(GCC_FLAGS) -o $@ $^  

ex_ab_mots: ex_ab_mots.o arbre_binaire.o fonctions_string.o	
	$(CC) $(GCC_FLAGS)  $(LINK_FLAGS) -o $@ $^  

main_expr: arbre_expr.o arbre_binaire.o main_expr.o
	$(CC) $(GCC_FLAGS)  $(LINK_FLAGS) -o $@ $^ 

lib%.a: %.c
	$(CC) $(GCC_FLAGS) $(GCC_LIB_FLAGS) -c -o $@ $^

clean:
	rm -f arbre_binaire.o arbre_expr.o ex_ab_entiers.o ex_ab_mots.o fonctions_entiers.o main_expr.o $(EXE) $(LIB) *~

