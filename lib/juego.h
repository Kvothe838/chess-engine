#ifndef _JUEGO_H_
#define _JUEGO_H_

typedef struct
    {
        Tablero tablero;

        Pieza** piezasBlancas;
        int cantidadDePiezasBlancas;

        Pieza** piezasNegras;
        int cantidadDePiezasNegras;
    } Juego;

    void JuegoInicializar(char[FILAS][COLUMNAS][3], Juego* juego);
#endif