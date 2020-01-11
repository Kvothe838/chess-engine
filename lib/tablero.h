#ifndef _TABLERO_H_
#define _TABLERO_H_

#include <stdbool.h>
#include <pieza.h>

#define FILAS 8
#define COLUMNAS 8

typedef Pieza** Tablero;

void TableroInicializar(Tablero* tablero);
void TableroImprimir(Tablero tablero);
void TableroDestruir(Tablero tablero);

#endif