#include <stdio.h>
#include <pieza.h>

void PiezaCrear(Pieza* pieza, TipoPieza tipo, bool esBlanca)
{
    pieza->tipo = tipo;
    pieza->esBlanca = esBlanca;
    pieza->posicion = NULL;
}

void PiezaCopiar(Pieza* copia, Pieza original)
{
    copia->tipo = original.tipo;
    copia->esBlanca = original.esBlanca;
}

void PiezaEsColocada(Pieza* pieza, Posicion* posicion)
{
    pieza->posicion = posicion;
}

bool PiezaEstaPuesta(Pieza pieza)
{
    return pieza.posicion != NULL;
}