#include <casilla.h>
#include <pieza.h>
#include <posicion.h>
#include <stdlib.h>
#include <stdio.h>

bool __posicionPosibleValida(Coordenada coordenadaRelativa, Casilla casillaPieza, Casilla* casillaTemp)
{
    int filaPosible = coordenadaRelativa[0] + casillaPieza.fila + 1;

    if(filaPosible < UNO || filaPosible > OCHO)
    {
        return false;
    }

    int columnaPosible = coordenadaRelativa[1] + (int)casillaPieza.columna;

    if(columnaPosible < A || columnaPosible > H)
    {
        return false;
    }

    (*casillaTemp).columna = columnaPosible;
    (*casillaTemp).fila = filaPosible;

    return true;
}

/* Basado en la casilla de la posicion y los movimientos relativos posibles de la ranura
de la posicion, filtra y transforma las casillas posibles (movimientos absolutos),
y devuelve la cantidad de movimientos posibles absolutos.*/
int CasillaObtenerPosibles(Posicion* posicion, Casilla** casillas)
{
    int cantidadMovimientosPosibles = PiezaObtenerCantidadMovimientos(posicion->ranura->tipo);
    int cantidadMovimientos = 0;
    Coordenada* movimientosPosibles = posicion->ranura->coordenadasMovimientosPosibles;
    (*casillas) = NULL;

    int cantidadMovimientosTotales = PiezaObtenerMovimientosEspecialesPosibles((*posicion->casilla), posicion->ranura->tipo, posicion->ranura->esBlanca, &movimientosPosibles, cantidadMovimientosPosibles);

    for(int i = 0; i < cantidadMovimientosTotales; i++)
    {
        Casilla* casillaTemp = (Casilla*)malloc(sizeof(Casilla));

        if(__posicionPosibleValida(movimientosPosibles[i], *(posicion->casilla), casillaTemp))
        {
            cantidadMovimientos++;
            (*casillas) = realloc(*casillas, cantidadMovimientos * sizeof(Coordenada));
            (*casillas)[cantidadMovimientos-1] = *casillaTemp;
        }

        free(casillaTemp);
    }


    return cantidadMovimientosTotales;
}