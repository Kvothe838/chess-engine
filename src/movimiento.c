#include <stdio.h>
#include <stdlib.h>
#include <movimiento.h>


status_t CalcularMovimiento(Juego* juego, char movimiento[4], char color)
{
    status_t status;
    Pieza* piezaAEvaluar;
    Pieza** piezasDelColor = color == 'B' ? juego->piezasBlancas : juego->piezasNegras;
    Pieza** piezasPosibles = NULL;
    Casilla* casillasPosibles = NULL;
    Posicion* posicionInicial;
    bool found;
    int cantidadDePiezasDelColor = color == 'B' ? juego->cantidadDePiezasBlancas : juego->cantidadDePiezasNegras;    
    int cantidadPiezasPosibles = 0;

    for (int i = 0; i < cantidadDePiezasDelColor; ++i)
    {
        Casilla* casillas = NULL;
        piezaAEvaluar = piezasDelColor[i];

        if (piezaAEvaluar->tipo == movimiento[0] && piezaAEvaluar->posicion != NULL)
        {
            posicionInicial = piezaAEvaluar->posicion;
            found = false;

            int cantidadPosiblesMovimientos = CasillaObtenerPosibles(posicionInicial, &casillas);
            

            for (int j = 0; j < cantidadPosiblesMovimientos; ++j)
            {
                if (casillas[j].columna == (Columna)movimiento[1] &&
                    casillas[j].fila == (Fila)(movimiento[2] - '0'))
                {
                    casillasPosibles = (Casilla*) realloc(casillasPosibles, (cantidadPiezasPosibles+1) * sizeof(Casilla));                    
                    casillasPosibles[cantidadPiezasPosibles] = casillas[j];
                    found = true;
                    
                    break;
                }
            }

            if(found) 
            {
                piezasPosibles = (Pieza**) realloc(piezasPosibles, (cantidadPiezasPosibles + 1) * sizeof(Pieza*));
                piezasPosibles[cantidadPiezasPosibles] = piezaAEvaluar;
                cantidadPiezasPosibles++;
            }
        }

        free(casillas);
    }

    switch(cantidadPiezasPosibles)
    {
        case 0:
            status = ST_ERR_MOV_INEXISTENTE;

            break;
        case 1:
            status = MoverPieza(&(juego->tablero), casillasPosibles[0], piezasPosibles[0]->posicion, piezasPosibles[0]);

            break;
        default:
            status = ST_ERR_MOV_INCORRECTO;

            break;
    }

    free(casillasPosibles);
    free(piezasPosibles);

    return status;
}

status_t MoverPieza(Tablero* tablero, Casilla casilla, Posicion* posicionInicial, Pieza* pieza)
{

    Posicion* posicionFinal = TableroObtenerPieza(*tablero, casilla);
    Pieza *piezaQueEstaEnLaPosicionFinal = posicionFinal->ranura;

    if (piezaQueEstaEnLaPosicionFinal != NULL)
    {
        if (pieza->esBlanca == piezaQueEstaEnLaPosicionFinal->esBlanca)
        {
            return ST_ERR_ATAQ_ALIADO;
        }

        if (pieza->esBlanca)
        {
            PiezaEsAtacada(piezaQueEstaEnLaPosicionFinal, &zonaPiezasEliminadasPorLasBlancas);
        }
        else
        {
            PiezaEsAtacada(piezaQueEstaEnLaPosicionFinal, &zonaPiezasEliminadasPorLasNegras);
        }
    }
    posicionInicial->ranura = NULL;

    TableroColocarPieza(posicionFinal, pieza);
    return ST_OK;
}