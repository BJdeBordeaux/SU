# Mettre dans SCHEDPATH le repertoire ou se trouve libsched.a
# et sched.h
SCHEDPATH = ../src

CFLAGS = -Wall -I$(SCHEDPATH) -g

all: main scen 

main: main.o 
	gcc $(CFLAGS) -o main main.o -L$(SCHEDPATH) -lsched -L$(SCHEDPATH)  


scen: scen.o 
	gcc $(CFLAGS) -o scen scen.o -L$(SCHEDPATH) -lsched -L$(SCHEDPATH)  

main.o: main.c
	gcc $(CFLAGS) -c main.c

scen.o: scen.c
	gcc $(CFLAGS) -c scen.c

clean: 
	rm -f main main.o scen scen.o
