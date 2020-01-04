LIBS = lib

CFLAGSMAIN = -Wall -Werror -pedantic -O3  -lm
CFLAGSTEST = -Wall -Werror -pedantic -O0  -ggdb -lm

HEADERS ?= $(wildcard $(LIBS)/*.h)

SOURCES ?= $(wildcard src/*.c)

OBJECTS = $(patsubst %.c, %.o, $(SOURCES))


CPPFLAGS ?= -I$(LIBS) # Flags de objetos

MAIN = main
TEST = test

all: print $(MAIN) $(TEST) clean run

$(MAIN): $(OBJECTS) 
	$(CC) -o bin/$(MAIN) $(OBJECTS) $(CFLAGSMAIN) 

$(TEST): $(OBJECTS)
	$(CC) -o test/$(TEST) $(OBJECTS) $(CFLAGSTEST)

print:
	echo $(HEADERS)

clean:
	$(RM) $(OBJECTS) *.gch

run:
	./bin/$(MAIN)
