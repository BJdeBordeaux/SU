CFLAGS = -g -Wextra
CC = gcc

PROGRAMS = mgrep mgrep2 testf

.PHONY:	all clean

all: $(PROGRAMS)

mgrep: mgrep.c
	$(CC) -o $@ $(CFLAGS) $^
	
mgrep2: mgrep2.c
	$(CC) -o $@ $(CFLAGS) $^

testf: testf.c
	$(CC) -o $@ $(CFLAGS) $^

clean:
	rm -f *.o $(PROGRAMS)
