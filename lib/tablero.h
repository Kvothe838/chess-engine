#ifndef _TABLERO_H_
#define _TABLERO_H_

#include <stdbool.h>
#include <pieza.h>
#include <posicion.h>

#define ALFIL_BLANCO "AB"
#define ALFIL_NEGRO "AN"
#define CABALLO_BLANCO "CB"
#define CABALLO_NEGRO "CN"
#define PEON_BLANCO "PB"
#define PEON_NEGRO "PN"
#define REINA_BLANCO "RB"
#define REINA_NEGRO "RN"
#define REY_BLANCO "KB"
#define REY_NEGRO "KN"
#define TORRE_BLANCO "TB"
#define TORRE_NEGRO "TN"
#define NADA "  "

#define FILAS 8
#define COLUMNAS 8

typedef Posicion** Tablero;

void TableroInicializar(Tablero* tablero);
void TableroImprimir(Tablero tablero);
void TableroColocarPieza(Posicion* posicion, Pieza* pieza);
void TableroDestruir(Tablero *tablero);

#endif