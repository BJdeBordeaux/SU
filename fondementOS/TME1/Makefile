CFLAGS = -g -Wall -Wextra
CC = gcc

PROGRAMS =  maintab

.PHONY:	all clean

all: $(PROGRAMS)

ex1: ex1.c
	$(CC) -o $@ $(CFLAGS) $^

maintab: maintab.o tab.o
	$(CC) -o $@ $(CFLAGS) $^

maintab.o: maintab.c
	$(CC) -c $(CFLAGS) $^

tab.o: tab.c
	$(CC) -c $(CFLAGS) $^

clean:
	rm -f *.o $(PROGRAMS)
