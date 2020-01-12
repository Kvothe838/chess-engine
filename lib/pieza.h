#ifndef _PIEZA_H_
#define _PIEZA_H_

#include <stdbool.h>
#include <struct.h>

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

struct Pieza
{
    TipoPieza tipo;
    bool esBlanca;
    int representacion;
    Posicion* posicion;
};

void PiezaCrear(Pieza* pieza, TipoPieza tipo, bool esBlanca);
void PiezaCopiar(Pieza* copia, Pieza original);
bool PiezaEstaPuesta(Pieza pieza);
void PiezaEsColocada(Pieza* pieza, Posicion* posicion);
void PiezaImprimir(Pieza pieza);

#endif