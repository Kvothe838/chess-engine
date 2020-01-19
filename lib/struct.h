#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct Pieza Pieza;
typedef struct Casilla Casilla;
typedef struct Posicion Posicion;
typedef int Coordenada[2];

typedef enum
{
    ALFIL = 'A',
    CABALLO = 'C',
    PEON = 'P',
    REINA = 'R',
    REY = 'K',
    TORRE = 'T'
} TipoPieza;

typedef enum
{
    A = 'A',
    B = 'B',
    C = 'C',
    D = 'D',
    E = 'E',
    F = 'F',
    G = 'G',
    H = 'H'
} Columna;

typedef enum
{
    UNO = 1,
    DOS = 2,
    TRES = 3,
    CUATRO = 4,
    CINCO = 5,
    SEIS = 6,
    SIETE = 7,
    OCHO = 8
} Fila;

#endif