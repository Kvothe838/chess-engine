#ifndef _POSICION_H_
    #define _POSICION_H_

    #include <stdbool.h>
    #include <struct.h>

    struct Posicion
    {
        Casilla* casilla;
        Pieza* ranura;
    };

    void PosicionInicializar(Posicion* posicion, Coordenada coordenada);
    bool PosicionEstaVacia(Posicion posicion);
    void PosicionDestruir(Posicion* posicion);
#endif