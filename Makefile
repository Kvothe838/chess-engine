CFLAGSMAIN = -Wall -Werror -pedantic -O3 -lm
CFLAGSTEST = -Wall -Werror -pedantic -O0 -ggdb -lm


SOURCES ?= $(wildcard src/*.c)

OBJECTSMAIN = $(patsubst %.c, %.o, $(SOURCES))
OBJECTSTEST = $(patsubst %.c, %.o, $(SOURCES))

MAIN = main
TEST = test

all: $(MAIN) clean run

$(MAIN): $(OBJECTSMAIN)
	$(CC) -o bin/$(MAIN) $(OBJECTSMAIN) $(CFLAGSMAIN) 

clean:
	$(RM) $(OBJECTSMAIN) *.gch

run:
	./bin/$(MAIN)
