#ifndef _INTERFAZ_H
    #define _INTERFAZ_H

    #include <tablero.h>

    typedef struct
    {
        Tablero tablero;
    } Juego;

    void Empezar(Juego*);
    void Terminar(Juego*);
#endif