CC = gcc

LIBS = lib

CFLAGSMAIN = -Wall -Werror -pedantic -O3  -lm
CFLAGSDEBUG = -Wall -Werror -pedantic -O0  -ggdb -lm
CFLAGSTEST = -Wall -Werror -pedantic #-fsyntax-only

HEADERS ?= $(wildcard $(LIBS)/*.h)

SOURCES ?= $(wildcard src/*.c)

OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

TESTS ?= $(wildcard test/*.c)

TESTSOBJECTS = $(patsubst %.c,%.o, $(TESTS))

TESTNAMES = $(patsubst %.c,%, $(TESTS))


CPPFLAGS ?= -I$(LIBS) -ggdb # Variable interna de Makefile para definir los flgas de los objetos

MAIN = main

DEBUG = degub

.PHONY: test clean print all

all: $(MAIN) $(DEBUG) clean run

$(MAIN): $(OBJECTS) 
	$(CC) -o bin/main/$(MAIN) $(OBJECTS) $(CFLAGSMAIN) 

$(DEBUG): $(OBJECTS)
	$(CC) -o bin/debug/$(DEBUG) $(OBJECTS) $(CFLAGSDEBUG)

print:
	echo $(CC) -o test/A $(TESTSOBJECTS)  $(CFLAGSTEST)

clean:
	$(RM) $(OBJECTS) *.gch

run:
	./bin/main/$(MAIN)

test: $(TESTNAMES)
	$(RM) $(TESTSOBJECTS) $(TESTNAMES) *.gch

$(TESTNAMES): $(TESTSOBJECTS)
	$(CC) -o $@ $@.o $(CFLAGSTEST)
	./$@
