CC = gcc
CFLAGS = -Wall -g
PROGRAMS = note

all: $(PROGRAMS)

note.o: note.c
	$(CC) -c $(CFLAGS) $^

note: note.o
	$(CC) $(CFLAGS) $^ -o note 

clean: 
	rm -f *.o $(PROGRAMS)