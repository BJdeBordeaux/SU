CFLAGS = -g -Wextra
CC = gcc

PROGRAMS = loopcpu loopsys mytimes mytimes2

.PHONY:	all clean

all: $(PROGRAMS)

loopcpu: loopcpu.c
	$(CC) -o $@ $(CFLAGS) $@.c

loopsys: loopsys.c
	$(CC) -o $@ $(CFLAGS) $@.c

fonctions.o: fonctions.c
	$(CC) -c $(CFLAGS) $^

mytimes: mytimes.c fonctions.o
	$(CC) -o $@ $(CFLAGS) $^

mytimes2: mytimes2.c fonctions.o
	$(CC) -o $@ $(CFLAGS) $^

clean:
	rm -f *.o $(PROGRAMS)
