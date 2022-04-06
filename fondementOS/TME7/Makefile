CFLAGS = -Wall -g

mymalloc : affiche_tas.o mymalloc.c
	gcc $(CFLAGS) -o mymalloc affiche_tas.o mymalloc.c
    
affiche_tas.o : affiche_tas.h affiche_tas.c
	gcc $(CFLAGS) -c affiche_tas.c
