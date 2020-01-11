#ifndef _POSICION_H_
#define _POSICION_H_

#include <stdbool.h>
#include <pieza.h>

typedef struct{
    char horiontal;
    int vertical;
    Pieza* ranura;
} Posicion;

void PosicionInicializar(Posicion*, int[2]);
bool PosicionEstaVacia(Posicion);
void PosicionDestruir(Posicion*);

#endif