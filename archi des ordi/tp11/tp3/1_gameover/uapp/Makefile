#/--------------------------------------------------------------------------------------------------
#/   _     ___    __
#/  | |__ /'v'\  / /    \date        2021-09-20
#/  | / /(     )/ _ \   \copyright   2021 Sorbonne University https://opensource.org/licenses/MIT
#/  |_\_\ x___x \___/
#/
#/--------------------------------------------------------------------------------------------------

# Sources and target
# --------------------------------------------------------------------------------------------------

BIN     = ../user.x
SRC     = main.c
LIB		= crt0.o libc.o
LIBDIR  = ../ulib
LDSCRIPT= ../ulib/user.ld

# Tools and parameters definitions
# --------------------------------------------------------------------------------------------------

NTTYS  ?= 1#                          default number of ttys
NCPUS  ?= 1#                          default number of CPUS

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
CFLAGS += -I. -I../common -I../ulib#  directories where include files like <file.h> are located
CFLAGS += -DNTTYS=$(NTTYS)#			  #define NTTYS with the number of ttys in the prototype	
CFLAGS += -DNCPUS=$(NCPUS)#			  #define NCPUS with the number of cpus in the prototype	

OBJ     = $(addprefix obj/,$(subst .c,.o,$(filter %.c,$(SRC))))
OBJLIB	= $(addprefix $(LIBDIR)/obj/, $(LIB))

LDFLAGS = -T $(LDSCRIPT) $(OBJLIB)

PDF 	= ../$(notdir $(shell pwd)).pdf# the pdf file has the name of directory

# Rules (here they are used such as simple shell scripts)
# --------------------------------------------------------------------------------------------------

help:
	@echo ""
	@echo "Usage : make <compil|clean|pdf>"
	@echo ""
	@echo "        compil  : compile all sources"
	@echo "        clean   : clean all compiled files"
	@echo "        pdf     : generate $(PDF) with all source files"
	@echo ""

compil: mkdir_obj depend ../user.x

mkdir_obj:
	test -d obj || mkdir obj

clean:
	-rm -r obj ../*.x* *~ Makefile.bak $(PDF) pdf.log 2> /dev/null || true

pdf:
	@a2ps -2 -M A4 -A fill -o - -l100 Makefile $(SRC) 2> pdf.log |\
	ps2pdf -sPAPERSIZE=a4 - $(PDF); echo $(PDF); sed 's/^/    /' pdf.log

# Rules with automatic variables to produce the executable 
# --------------------------------------------------------------------------------------------------

$(BIN) : $(OBJ)
	$(LD) -o $@ $(LDFLAGS) $^
	$(OD) -D $@ > $@.s

obj/%.o : %.c
	$(CC) -o $@ $(CFLAGS) $<
	$(OD) -D $@ > $@.s

# makedepend analyzes the source files to determine automatically what are the dependencies
# of the object files on the source files (see https://linux.die.net/man/1/makedepend for details)
depend :
	makedepend -- $(CFLAGS) -D__DEPEND__ -- -pobj/ $(SRC)

# Automatic dependies
# --------------------------------------------------------------------------------------------------
# DO NOT DELETE

obj/main.o: ../ulib/libc.h
