#include <stdio.h>
#include <posicion.h>
#include <stdlib.h>

void PosicionInicializar(Posicion* pocision, int coordenada[2]) {
    pocision->horiontal = (char)(coordenada[1] + 'A');
    pocision->vertical  = coordenada[0];
    pocision->ranura = NULL;
}

bool PosicionEstaVacia(Posicion posicion) {
    return posicion.ranura == NULL;
}

void PosicionDestruir(Posicion* posicion) {
    free(posicion->ranura);
}