#/--------------------------------------------------------------------------------------------------
#/   _     ___    __
#/  | |__ /'v'\  / /    \date        2021-12-05
#/  | / /(     )/ _ \   \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
#/  |_\_\ x___x \___/
#/
#/--------------------------------------------------------------------------------------------------

# Tools and parameters definitions
# --------------------------------------------------------------------------------------------------

NTTY   ?= 1#                          default number of ttys

CC      = mipsel-unknown-elf-gcc#     compiler
OD      = mipsel-unknown-elf-objdump# desassembler

CFLAGS  = -c#                         stop after compilation, then produce .o
CFLAGS += -Wall -Werror#              gives almost all C warnings and considers them to be errors
CFLAGS += -mips32r2#                  define of MIPS version
CFLAGS += -std=c99#                   define of syntax version of C
CFLAGS += -fno-common#                do not use common sections for non-static vars (only bss)
CFLAGS += -fno-builtin#               do not use builtin functions of gcc (such as strlen)
CFLAGS += -fomit-frame-pointer#       only use of stack pointer ($29)
CFLAGS += -G0#                        do not use global data pointer ($28)
CFLAGS += -O3#                        full optimisation mode of compiler
CFLAGS += -I. -I../common#            directories where include files like <file.h> are located
CFLAGS += -DNTTYS=$(NTTY)#			  #define NTTYS with the number of ttys in the prototype	

# Rules (here they are used such as simple shell scripts)
# --------------------------------------------------------------------------------------------------

help:
	@echo -e "\nUsage : make <compil|clean>\n"
	@echo -e "        compil  : compile all sources"
	@echo -e "        clean   : clean all compiled files\n"

compil: mkdir_obj all

mkdir_obj:
	test -d obj || mkdir obj

clean:
	-rm -r obj *~ 2> /dev/null || true

# Explicite rules with automatic variables to produce the executable 
# --------------------------------------------------------------------------------------------------

all : obj/crt0.o obj/libc.o

obj/crt0.o : crt0.c ../common/syscalls.h
	$(CC) -o $@ $(CFLAGS) $<
	$(OD) -D $@ > $@.s

obj/libc.o : libc.c ../common/syscalls.h libc.h
	$(CC) -o $@ $(CFLAGS) $<
	$(OD) -D $@ > $@.s
