#ifndef _POSICION_H_
#define _POSICION_H_

#include <stdbool.h>
#include <struct.h>

struct Posicion
{
    char horizontal;
    int vertical;
    Pieza* ranura;
};

void PosicionInicializar(Posicion* posicion, int coordenada[2]);
bool PosicionEstaVacia(Posicion posicion);
void PosicionDestruir(Posicion* posicion);

#endif