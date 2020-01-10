#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdbool.h>

#define FILAS 8
#define COLUMNAS 8

// #define ALFIL 'A'
// #define CABALLO 'C'
// #define PEON 'P'
// #define REINA 'R'
// #define REY 'K'
// #define TORRE 'T'
// #define NADA ' '

typedef enum {
    ALFIL = 'A',
    CABALLO = 'C',
    PEON = 'P',
    REINA = 'R',
    REY = 'K',
    TORRE = 'T',
    NADA = ' '
} TipoPieza;

typedef enum {
    A = 'A',
    B = 'B',
    C = 'C',
    D = 'D',
    E = 'E',
    F = 'F',
    G = 'G',
    H = 'H'
} Columna;

typedef enum {
    UNO = 1,
    DOS = 2,
    TRES = 3,
    CUATRO = 4,
    CINCO = 5,
    SEIS = 6,
    SIETE = 7,
    OCHO = 8
} Fila;

typedef struct {
    TipoPieza tipo;
    bool esBlanca;
    Columna columnaActual;
    Fila filaActual;
    //función diciendo si se puede mover a tal lugar?
} Pieza;

typedef Pieza** Tablero;

void TableroInicializar(Tablero* tablero);
void TableroImprimir(Tablero tablero);
void TableroDestruir(Tablero tablero);

#endif