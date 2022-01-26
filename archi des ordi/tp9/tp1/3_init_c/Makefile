#/--------------------------------------------------------------------------------------------------
#/   _     ___    __
#/  | |__ /'v'\  / /    \date        2021-11-30
#/  | / /(     )/ _ \   \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
#/  |_\_\ x___x \___/
#/
#/--------------------------------------------------------------------------------------------------

# Tools and parameters definitions
# --------------------------------------------------------------------------------------------------

NTTYS  ?= 1#                          default number of ttys

CC      = mipsel-unknown-elf-gcc#     compiler
LD      = mipsel-unknown-elf-ld#      linker
OD      = mipsel-unknown-elf-objdump# desassembler
SX      = almo1.x#                    prototype simulator

CFLAGS  = -c#                         stop after compilation, then produce .o
CFLAGS += -Wall -Werror#              gives almost all C warnings and considers them to be errors
CFLAGS += -mips32r2#                  define of MIPS version
CFLAGS += -std=c99#                   define of syntax version of C
CFLAGS += -fno-common#                do not use common sections for non-static vars (only bss)
CFLAGS += -fno-builtin#               do not use builtin functions of gcc (such as strlen)
CFLAGS += -fomit-frame-pointer#       only use of stack pointer ($29)
CFLAGS += -G0#                        do not use global data pointer ($28)
CFLAGS += -O3#                        full optimisation mode of compiler
CFLAGS += -I.#                        directories where include files like <file.h> are located
CFLAGS += -DNTTYS=$(NTTYS)#           #define NTTYS with the number of ttys in the prototype

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
	$(CC) -o hcpua.o $(CFLAGS) hcpua.S
	@$(OD) -D hcpua.o > hcpua.o.s
	$(CC) -o kinit.o $(CFLAGS) kinit.c
	@$(OD) -D kinit.o >  kinit.o.s
	$(LD) -o kernel.x -T kernel.ld hcpua.o kinit.o
	@$(OD) -D kernel.x > kernel.x.s

exec: compil
	$(SX) -KERNEL kernel.x -NTTYS $(NTTYS)

debug: clean compil
	find . *.[chS] | xargs ctags
	$(SX) -KERNEL kernel.x -NTTYS $(NTTYS) -DEBUG $(FROM) -NCYCLES $(LAST) > $(DLOG)
	tracelog tags *.x.s $(DLOG)

clean:
	-killall xterm soclib-fb 2> /dev/null || true
	-rm tags xterm* /tmp/fbf.* *.o* *.x* *~ $(DLOG) trace*.s label*.s 2> /dev/null || true
