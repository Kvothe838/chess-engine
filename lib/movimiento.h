#ifndef _MOVIMIENTO_H
#define _MOVIMIENTO_H

#include <struct.h>
#include <tablero.h>
#include <pieza.h>
#include <posicion.h>
#include <casilla.h>
#include <ataques.h>
#include <interfaz.h>


status_t CalcularMovimiento(Juego* juego, char movimiento[4], char color);

status_t MoverPieza(Tablero* tablero, Casilla casilla, Posicion* posicionInicial, Pieza* pieza);

#endif