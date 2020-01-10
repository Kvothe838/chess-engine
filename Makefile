# Programa de compilacion
CC = gcc

# Directorios
SRC_DIR  = src
TEST_DIR = test
LIB_DIR  = lib
OBJ_DIR  = obj
BIN_DIR = bin

# Nombre de los binarios creados
MAIN = main
DEBUG = degub

# Flags con los que se van a compilar los correspondientes ejecutables
CFLAGS = -Wall -Werror -pedantic -std=c99
CFLAGS_MAIN  = $(CFLAGS) -O3  -lm
CFLAGS_DEBUG = $(CFLAGS) -O0  -ggdb -lm
CFLAGS_TEST  = $(CFLAGS) 
# Variable interna de Makefile para definir los flgas de los objetos
CPPFLAGS ?= $(CFLAGS) -I$(LIB_DIR) -ggdb

# Los archivos .h que fueron usados en el programa (Actaulmente no usado)
HEADERS ?= $(wildcard $(LIB_DIR)/*.h)

# Los archivos .c utilizados para el programa principal
SOURCES ?= $(wildcard $(SRC_DIR)/*.c)

# Los archivos .c utilizados para la compilacion de los tests
TESTS ?= $(wildcard $(TEST_DIR)/*.c)

#Objetos del programa (las variables con guion son para auxiliares
# para poner la direccion correcta de los objetos, debido a que
# Makefile no acepta que una variable si use a si misma, lo toma
# como si fuera un llamado "recursivo")
__OBJECTS2 = $(patsubst %.c, %.o, $(SOURCES))
__OBJECTS1 = $(notdir $(__OBJECTS2))
OBJECTS  = $(patsubst %, $(OBJ_DIR)/%, $(__OBJECTS1))

# Objetos del programa programa principal exceptuando main.c
MAIN_OBJECTS = $(filter-out obj/main.o, $(OBJECTS))

# Objetos de los tests
TEST_OBJECTS = $(patsubst %.c,%.o, $(TESTS))

# Nombre de los tests usados para la compilacion de los .c
TEST_NAMES = $(patsubst %.c,%, $(TESTS))

# Lista que mantiene actualizados los programas ante
# los cambios realizados en el proyecto
.PHONY: test clean print all

# Etiqueta principal, este se ejecuta al ejecutar make
# sin ninguna etiquita de referencia, en ella se ejecutan
# las etiquetas en el orden escritos 
all: $(MAIN) $(DEBUG) clean run

# Etiqueta que compila el programa princial una vez compilados
# los objetos
$(MAIN): $(OBJECTS) 
	@echo "\033[0;32m [OK] \033[0m  \033[0;33m Compiling:\033[0m" $(MAIN)
	@$(CC) -o $(BIN_DIR)/main/$(MAIN) $(OBJECTS) $(CFLAGS_MAIN) 

# Etiqueta que compila el programa para debuggear una vez compilados
# los objetos
$(DEBUG): $(OBJECTS)
	@echo "\033[0;32m [OK] \033[0m  \033[0;33m Compiling:\033[0m" $(DEBUG)
	@$(CC) -o $(BIN_DIR)/debug/$(DEBUG) $(OBJECTS) $(CFLAGS_DEBUG)

# Etiqueta que llama a la etiquiqueta de creacion de los ejecutables
# los tests y luego los elimina
test: $(TEST_NAMES)
	@$(RM) $(TEST_OBJECTS) $(TEST_NAMES) *.gch

# Etiqueta que compila cada test y luego lo ejecuta 
$(TEST_NAMES): $(TEST_OBJECTS)
	@echo "\033[0;32m [OK] \033[0m  \033[0;33m Compiling:\033[0m" $<
	@$(CC) -o $@ $@.o $(MAIN_OBJECTS) $(CFLAGS_TEST)
	@./$@

# Ejecuta el programa princial
run:
	./$(BIN_DIR)/main/$(MAIN)

# Funcion de print usada para debuggear este makefile
print:
	@echo $(MAIN_OBJECTS)

# Regla de crear los objetos del directorio test
$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	@echo "\033[0;32m [OK] \033[0m  \033[0;33m Compiling:\033[0m" $<
	@$(CC) $< $(CPPFLAGS) -DARCHIVO=\"$<\" -c -o $@

# Regla para crear todos los objetos a partir de los sources
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "\033[0;32m [OK] \033[0m  \033[0;33m Compiling:\033[0m" $<
	@$(CC) $< $(CPPFLAGS) -c -o $@

# Elimina los posibles archivos extras que se creen en el proceso (actualmente no hace mucho)
clean:
	$(RM) *.gch