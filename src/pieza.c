#include <pieza.h>

void CrearPieza(Pieza* pieza, TipoPieza tipo, bool esBlanca, Columna columna, Fila fila) {
    pieza->tipo = tipo;
    pieza->esBlanca = esBlanca;
    pieza->columnaActual = columna;
    pieza->filaActual = fila;
}
