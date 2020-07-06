#ifndef _JUEGO_H_
#define _JUEGO_H_

#include <tablero.h>

typedef struct
    {
        Tablero tablero;

        Pieza** piezasBlancas;
        int cantidadDePiezasBlancas;

        Pieza** piezasNegras;
        int cantidadDePiezasNegras;
    } Juego;

    void JuegoInicializar(char[FILAS][COLUMNAS][3], Juego* juego);
    void JuegoDestruir(Juego* juego);
#endif