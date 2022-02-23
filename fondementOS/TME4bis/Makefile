CFLAGS = -g -Wextra
CC = gcc

PROGRAMS = arbre minishell

.PHONY:	all clean

all: $(PROGRAMS)

arbre: arbre.c
	$(CC) -o $@ $(CFLAGS) $^

minishell: minishell.c
	$(CC) -o $@ $(CFLAGS) $^

clean:
	rm -f *.o $(PROGRAMS)
