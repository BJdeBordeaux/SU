mf.o: mf.c mf.h
	gcc -Wall -o mf.o -c mf.c
mp.o: mp.c 
	gcc -Wall -o mp.o -c mp.c
mp: mp.o mf.o
	gcc -Wall -o mp mp.o mf.o
clean:
	rm -f *.o