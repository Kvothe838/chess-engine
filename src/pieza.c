#include <pieza.h>

void PiezaCrear(Pieza* pieza, TipoPieza tipo, bool esBlanca, Columna columna, Fila fila) {
    pieza->tipo = tipo;
    pieza->esBlanca = esBlanca;
    pieza->columnaActual = columna;
    pieza->filaActual = fila;
}

void PiezaCopiar(Pieza* copia, Pieza original) {
    copia->tipo = original.tipo;
    copia->esBlanca = original.esBlanca;
    copia->columnaActual = original.columnaActual;
    copia->filaActual = original.filaActual;
}