#/--------------------------------------------------------------------------------------------------
#/   _     ___    __
#/  | |__ /'v'\  / /    \date        2021-12-05
#/  | / /(     )/ _ \   \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
#/  |_\_\ x___x \___/
#/
#/--------------------------------------------------------------------------------------------------

# Tools and parameters definitions
# --------------------------------------------------------------------------------------------------

NTTYS  ?= 1#                          default number of ttys

SX      = almo1.x#                    prototype simulator
FROM   ?= 0#                          first cycle to trace
LAST   ?= 10000#                      last cycle to execute

DLOG    = ~/kO6-debug.log#            debug file 

# Rules (here they are used such as simple shell scripts)
# --------------------------------------------------------------------------------------------------

help:
	@echo ""
	@echo "Usage : make <compil|exec|debug|clean> [FROM=num] [LAST=num] [NTTYS=num]"
	@echo ""
	@echo "    Target "
	@echo "        compil  : compiles all sources"
	@echo "        exec    : executes the prototype"
	@echo "        debug   : Executes and generates execution traces (trace[cpu].s)"
	@echo "        clean   : clean all compiled files"
	@echo ""
	@echo "    Options (default values are defined in the Makefile)"
	@echo "        FROM is the first cycle from which the trace is made in debug (default $(FROM))"
	@echo "        LAST is the last cycle to execute (default $(LAST))"
	@echo "        NTTYS is the number of TTY to create (default $(NTTYS))"
	@echo ""

compil: 
	make -C kernel compil NTTYS=$(NTTYS)
	make -C user   compil NTTYS=$(NTTYS)

exec: compil
	$(SX) -KERNEL kernel.x -APP user.x -NTTYS $(NTTYS)

debug: clean compil
	find . -name *.[chS] | xargs ctags
	$(SX) -KERNEL kernel.x -APP user.x -NTTYS $(NTTYS) -DEBUG $(FROM) -NCYCLES $(LAST) >$(DLOG)
	tracelog tags *.x.s $(DLOG) 

clean:
	-make -C kernel clean 
	-make -C user   clean
	-killall xterm soclib-fb 2> /dev/null || true
	-rm tags xterm* /tmp/fbf.* *.o* *.x* *~ $(DLOG) trace*.s label*.s 2> /dev/null || true
