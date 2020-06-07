#ifndef _INTERFAZ_H
    #define _INTERFAZ_H

    #include <tablero.h>

    typedef struct
    {
        Tablero tablero;

        Pieza** piezasBlancas;
        int cantidadDePiezasBlancas;

        Pieza** piezasNegras;
        int cantidadDePiezasNegras;
    } Juego;

    void Empezar(Juego*);

    void Inicializar(char[FILAS][COLUMNAS][3], Juego* juego);

    void Terminar(Juego*);
#endif