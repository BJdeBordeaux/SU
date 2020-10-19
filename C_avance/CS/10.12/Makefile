CLFAGS = -g -Wall
CC = gcc
PROGRAMS = mp

all: $(PROGRAMS)

mf.o: mf.c mf.h
	$(CC) -c $(CFLAGS) mf.c
mp.o: mp.c 
	$(CC) -c $(CFLAGS) mp.c
mp: mp.o mf.o
	$(CC) $(CFLAGS) -o mp mp.o mf.o
clean:
	rm -f *.o $(PROGRAMS)