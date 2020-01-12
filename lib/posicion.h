#ifndef _POSICION_H_
#define _POSICION_H_

#include <stdbool.h>
#include <struct.h>

struct Posicion
{
    char horiontal;
    int vertical;
    Pieza* ranura;
};

void PosicionInicializar(Posicion*, int[2]);
bool PosicionEstaVacia(Posicion);
void PosicionDestruir(Posicion*);

#endif