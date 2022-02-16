CFLAGS = -g -Wextra
CC = gcc

PROGRAMS = mgrep zombie

.PHONY:	all clean

all: $(PROGRAMS)

mgrep: mgrep.c
	$(CC) -o $@ $(CFLAGS) $^
	
zombie: zombie.c
	$(CC) -o $@ $(CFLAGS) $^

clean:
	rm -f *.o $(PROGRAMS)
