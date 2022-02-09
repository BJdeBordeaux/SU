CFLAGS = -Wall  -fPIC -I. -g
all: libsched.a 
	
libsched.a: sched.o 
	ar r libsched.a sched.o 
	ranlib libsched.a
	
sched.o: sched.c sched.h
	gcc $(CFLAGS) -c sched.c

	
clean: 
	rm -f libsched.a sched.o 
