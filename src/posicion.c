#include <stdio.h>
#include <stdlib.h>
#include <posicion.h>
#include <pieza.h>
#include <casilla.h>

void PosicionInicializar(Posicion* posicion, Coordenada coordenada)
{
    posicion->casilla = (Casilla*) malloc(sizeof(Casilla));
    posicion->casilla->columna = (char)(coordenada[1] + 'A');
    posicion->casilla->fila = coordenada[0];
    posicion->ranura = NULL;
}

bool PosicionEstaVacia(Posicion posicion)
{
    return posicion.ranura == NULL;
}

void PosicionDestruir(Posicion* posicion)
{
    /*
    Una posicion no tendria que destruir la pieza que
    tiene, si no que se tendria que destruir todas las piezas
    en otro lado
    */
    /*free(posicion->ranura);*/
    free(posicion->casilla);
}

int TraducirColumnaAIndice(Columna columna)
{
    return (int)(columna - 'A');
}