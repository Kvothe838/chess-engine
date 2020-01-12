#include <stdio.h>
#include <posicion.h>
#include <stdlib.h>

void PosicionInicializar(Posicion* posicion, int coordenada[2]) {
    posicion->horizontal = (char)(coordenada[1] + 'A');
    posicion->vertical = coordenada[0];
    posicion->ranura = NULL;
}

bool PosicionEstaVacia(Posicion posicion) {
    return posicion.ranura == NULL;
}

void PosicionDestruir(Posicion* posicion) {
    free(posicion->ranura);
}