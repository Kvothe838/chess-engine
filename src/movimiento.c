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

/*bloquearSaltosDeCasillas(*juego, &casillas, &cantidadPosiblesMovimientos, *(piezasPosibles[0]->posicion->casilla));*/

void bloquearSaltosDeCasillas(Juego juego, Casilla** casillas, int* cantidadPosiblesMovimientos, Casilla casillaInicial)
{
    /*
    Lo que tendria que hacer es escribir un programa que detecte casillas con piezas 
    (corregir que no son jugadores), una vez que las dectecto, tengo que saber si
    las piezas estan una fila, columna, o diagonal (directa o cruzada) de la pieza
    principal. Una vez que se esto, tengo que obtener eltestJuego.tablero valor de la diferencia
    y me tengo que quedar que el menor valor positivo y el mayor valor negativo de cada uno.
    Por ejemplo, comparar la diferencia de las filas de todas las posiciones con piezas
    y quedarme con la cota minima para saber cuales coordenadas con piezas esta mas cerca
    y una vez que se esto, filtro con todas las piezas.
    */
    if ((*cantidadPosiblesMovimientos) == 0)
    {
        return;
    }
    Posicion* chequeoDePosicion;
    Casilla* casillasFiltradas = NULL, *casillasConJugadores = NULL, casillaConJugador;
    size_t cantidadDeCasillasFiltradas = 0, cantidadDeCasillasConJugadores = 0;
    orientacion_t orientacion;
    for (int i = 0; i < *cantidadPosiblesMovimientos; ++i)
    {
        chequeoDePosicion = TableroObtenerPieza(juego.tablero, (*casillas)[i]);
        if (chequeoDePosicion->ranura != NULL)
        {
            casillasConJugadores = (Casilla*) realloc(casillasConJugadores, (cantidadDeCasillasConJugadores+1) * sizeof(Casilla));
            casillasConJugadores[cantidadDeCasillasConJugadores++] = *(chequeoDePosicion->casilla);
        
            casillaConJugador = casillasConJugadores[cantidadDeCasillasConJugadores-1];
            if (casillaInicial.columna == casillaConJugador.columna)
            {
                orientacion = ORIENT_COLUMNA;

            }
            else if (casillaInicial.fila == casillaConJugador.fila)
            {
                orientacion = ORIENT_FILA;
            }

            if ((Fila)(casillaInicial.columna - casillaConJugador.columna) == (casillaInicial.fila == casillaConJugador.fila))
            {
                orientacion = ORIENT_DIAG_IGUAL;
            }
            else if ((Fila)(casillaInicial.columna - casillaConJugador.columna) == -1*(casillaInicial.fila == casillaConJugador.fila))
            {
                orientacion = ORIENT_DIAG_CRUZ;
            }

        }

    }
    /*
    Parece redudnate el ultimo else ya que casi se probaron todos lo casos,
    pero de esta forma se chequea todos los casos de movimientos por filas
    y columnas y permite que el caballo siga saltando
    */

    switch (orientacion) 
    {
        case ORIENT_COLUMNA:


        default:
            printf("%s\n", "No tendria que llegar aca");
    }


    *cantidadPosiblesMovimientos = cantidadDeCasillasFiltradas;
    *casillas = casillasFiltradas;
}