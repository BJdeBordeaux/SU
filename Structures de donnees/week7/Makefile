CFLAGS = -g -Wall -Wextra -pedantic
CC = gcc

PROGRAMS = td

.PHONY:	all clean

all: $(PROGRAMS)

td: td.c
	$(CC) -o td $(CFLAGS) td.c 

clean:
	rm -f *.o *~ $(PROGRAMS)
