#ifndef _MOVIMIENTO_H
#define _MOVIMIENTO_H

#include <struct.h>
#include <tablero.h>
#include <pieza.h>
#include <posicion.h>
#include <casilla.h>
#include <ataques.h>
#include <interfaz.h>

typedef enum {
    ORIENT_COLUMNA,
    ORIENT_FILA,
    ORIENT_DIAG_IGUAL,
    ORIENT_DIAG_CRUZ,
    ORIENT_NO

} orientacion_t;


status_t CalcularMovimiento(Juego* juego, char movimiento[4], char color);

status_t MoverPieza(Tablero* tablero, Casilla casilla, Posicion* posicionInicial, Pieza* pieza);

void bloquearSaltosDeCasillas(Juego, Casilla**, int*, Casilla);

#endif