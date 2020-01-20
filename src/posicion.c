#include <stdio.h>
#include <stdlib.h>
#include <posicion.h>
#include <pieza.h>
#include <casilla.h>


void PosicionInicializar(Posicion* posicion, Coordenada coordenada) {
    posicion->casilla = (Casilla*) malloc(sizeof(Casilla));
    posicion->casilla->columna = (char)(coordenada[1] + 'A');
    posicion->casilla->fila = coordenada[0];
    posicion->ranura = NULL;
}

bool PosicionEstaVacia(Posicion posicion) {
    return posicion.ranura == NULL;
}

void PosicionDestruir(Posicion* posicion) {
    free(posicion->ranura);
}

int TraducirColumnaAIndice(Columna columna)
{
    return (int)(columna - 'A');
}