CFLAGS = -g -Wall -Wextra -pedantic
CC = gcc

PROGRAMS = ex

.PHONY:	all clean

.SUFFIX: 


ex: ex.c
	$(CC) -o $@ $(CFLAGS)  $^

#Ou plus simplement
#%.o:%.c %.h
#	$(CC)  $(GCC_FLAGS) -c  $<


clean:
	rm -f *.o *~ $(PROGRAMS)
