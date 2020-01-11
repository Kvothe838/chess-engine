#ifndef _TABLERO_H_
#define _TABLERO_H_

#include <stdbool.h>
#include <pieza.h>
#include <posicion.h>

#define FILAS 8
#define COLUMNAS 8

typedef Posicion** Tablero;

void TableroInicializar(Tablero* tablero);
void TableroImprimir(Tablero tablero);
void TableroColocarPieza(Tablero*, Pieza);
void TableroDestruir(Tablero *tablero);

#endif