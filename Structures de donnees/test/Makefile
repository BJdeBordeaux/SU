# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

# linker
LD=gcc
LDFLAGS=$(PTHREAD)

OBJS=    tme1_exo1p1 tme1_exo1p2 tme1_exo1p3

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)

tme1_exo1p1: tme1_exo1p1.c
	$(CC) $(CCFLAGS) tme1_exo1p1.c -o tme1_exo1p1
tme1_exo1p2: tme1_exo1p2.c
	$(CC) $(CCFLAGS) tme1_exo1p2.c $(GLIB) -o tme1_exo1p2
tme1_exo1p3: tme1_exo1p3.c
	$(CC) $(CCFLAGS) tme1_exo1p3.c $(GLIB) -o tme1_exo1p3

clean:
	rm -f *.o $(TARGET)