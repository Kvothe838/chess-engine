#ifndef _POSICION_H_
#define _POSICION_H_

#include <stdbool.h>
#include <struct.h>

typedef int Coordenada[2];

struct Posicion
{
    char horizontal;
    int vertical;
    Pieza* ranura;
};

void PosicionInicializar(Posicion* posicion, Coordenada coordenada);
bool PosicionEstaVacia(Posicion posicion);
void PosicionDestruir(Posicion* posicion);

#endif