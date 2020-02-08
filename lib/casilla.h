#ifndef _CASILLA_H_
    #define _CASILLA_H_

    #include <stdbool.h>
    #include <struct.h>

    struct Casilla {
        Columna columna;
        Fila fila;
    };

    int CasillaObtenerPosibles(Posicion* posicion, Casilla** casillas);
#endif