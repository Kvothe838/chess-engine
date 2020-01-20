#ifndef _PIEZA_H_
#define _PIEZA_H_

#include <stdbool.h>
#include <struct.h>

struct Pieza
{
    TipoPieza tipo;
    bool esBlanca;
    int representacion;
    Posicion* posicion;
    Coordenada* coordenadasMovimientosPosibles;
};

void PiezaCrear(Pieza* pieza, TipoPieza tipo, bool esBlanca);
void PiezaCopiar(Pieza* copia, Pieza original);
bool PiezaEstaPuesta(Pieza pieza);
void PiezaColocar(Pieza* pieza, Posicion* posicion);
void PiezaImprimir(Pieza pieza);
int PiezaObtenerCantidadMovimientos(TipoPieza tipo);

#endif