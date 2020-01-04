CFLAGSMAIN = -Wall -Werror -pedantic -O3 -lm
CFLAGSTEST = -Wall -Werror -pedantic -O0 -ggdb -lm


SOURCES ?= $(wildcard src/*.c)

OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

MAIN = main
TEST = test

all: $(MAIN) $(TEST) clean run

$(MAIN): $(OBJECTS)
	$(CC) -o bin/$(MAIN) $(OBJECTS) $(CFLAGSMAIN) 

$(TEST):
	$(CC) -o test/$(TEST) $(OBJECTS) $(CFLAGSMAIN)

clean:
	$(RM) $(OBJECTS) *.gch

run:
	./bin/$(MAIN)
