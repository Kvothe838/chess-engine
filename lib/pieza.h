#ifndef _PIEZA_H_
#define _PIEZA_H_

#include <stdbool.h>

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
    bool esPieza; //C WITHOUT POO FTW
    Columna columnaActual;
    Fila filaActual;
    //función diciendo si se puede mover a tal lugar?
} Pieza;

void PiezaCrear(Pieza* pieza, TipoPieza tipo, bool esBlanca, Columna columna, Fila fila);

#endif