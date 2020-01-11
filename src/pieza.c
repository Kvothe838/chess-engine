#include <pieza.h>

void PiezaCrear(Pieza* pieza, TipoPieza tipo, bool esBlanca, Columna columna, Fila fila) {
    pieza->tipo = (TipoPieza)tipo;
    pieza->esBlanca = esBlanca;
    pieza->esPieza = true; //Lo más sad que vas a ver hoy.
    pieza->columnaActual = (Columna)columna;
    pieza->filaActual = (Fila)fila;
}
