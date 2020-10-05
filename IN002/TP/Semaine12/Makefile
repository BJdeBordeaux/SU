CFLAGS = -Wall
CINI_INCLUDE = ../../C-L1/Environnement/include/
CINI_LIB = ../../C-L1/Environnement/lib/
all : Othello 

Othello.o : Othello.c
	gcc ${CFLAGS} -c Othello.c

ListePos.o : ListePos.c
	gcc ${CFLAGS} -c ListePos.c

Affichage.o : Affichage.c
	gcc ${CFLAGS} `sdl2-config --cflags` -c Affichage.c

Main.o : Main.c
	gcc ${CFLAGS} -c Main.c

Othello : ListePos.o Othello.o Main.o Affichage.o
	gcc ${CFLAGS} -o Othello ListePos.o Othello.o Main.o Affichage.o `sdl2-config --libs`


clean :
	rm -f *.o Othello
