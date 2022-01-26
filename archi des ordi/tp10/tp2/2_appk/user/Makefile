#/--------------------------------------------------------------------------------------------------
#/   _     ___    __
#/  | |__ /'v'\  / /    \date        2021-09-20
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
CFLAGS += -DNTTYS=$(NTTYS)#			  #define NTTYS with the number of ttys in the prototype	

# Rules (here they are used such as simple shell scripts)
# --------------------------------------------------------------------------------------------------

help:
	@echo -e "\nUsage : make <compil|clean>\n"
	@echo -e "        compil  : compile all sources"
	@echo -e "        clean   : clean all compiled files\n"

compil: mkdir_obj ../user.x

mkdir_obj:
	test -d obj || mkdir obj

clean:
	-rm -r obj ../*.x* *~ 2> /dev/null || true

# Explicite rules to produce the executable 
# --------------------------------------------------------------------------------------------------

../user.x : user.ld obj/crt0.o obj/main.o 
	$(LD) -o $@ -T $^
	$(OD) -D $@ > $@.s

obj/crt0.o : crt0.c 
	$(CC) -o $@ $(CFLAGS) $<
	$(OD) -D $@ > $@.s

obj/main.o : main.c
	$(CC) -o $@ $(CFLAGS) $<
	$(OD) -D $@ > $@.s
