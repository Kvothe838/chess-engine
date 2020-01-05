#ifndef _MAIN_H_
#define _MAIN_H_

#define FILAS 8
#define COLUMNAS 8

#define ALFIL_BLANCO "AB"
#define ALFIL_NEGRO "AN"
#define CABALLO_BLANCO "CB"
#define CABALLO_NEGRO "CN"
#define PEON_BLANCO "PB"
#define PEON_NEGRO "PN"
#define REINA_BLANCO "RB"
#define REINA_NEGRO "RN"
#define REY_BLANCO "YB"
#define REY_NEGRO "YN"
#define TORRE_BLANCO "TB"
#define TORRE_NEGRO "TN"
#define NADA "  "

typedef char*** Tablero;

void TableroInicializar(Tablero* tablero);
void TableroImprimir(Tablero tablero);
void TableroDestruir(Tablero tablero);

#endif