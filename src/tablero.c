#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <tablero.h>
#include <posicion.h>
#include <pieza.h>
#include <casilla.h>
#include <ataques.h>
#include <imprimir.h>


#define CANTIDAD_PIEZAS 32

Pieza** piezasBlancas;
int cantidadDePiezasBlancas;

Pieza** piezasNegras;
int cantidadDePiezasNegras;

void __TableroInicializar(char tableroProvisorio[FILAS][COLUMNAS][3], Tablero* tablero)
{
    Pieza *pieza;
    int coordenada[2];
    *tablero = (Tablero) malloc(FILAS * sizeof(Posicion*));
    cantidadDePiezasBlancas = 0;
    cantidadDePiezasNegras = 0;
    
    for (int y = 0; y < FILAS; y++)
    {
        coordenada[0] = y;
        (*tablero)[y] = (Posicion*)malloc(COLUMNAS * sizeof(Posicion));

        for (int x = 0; x < COLUMNAS; x++)
        {
            coordenada[1] = x;

            PosicionInicializar(&((*tablero)[y][x]), coordenada);
            
            if (strcmp(tableroProvisorio[y][x], NADA) != 0)
            {
                pieza = (Pieza*)malloc(sizeof(Pieza));

                PiezaCrear(pieza, tableroProvisorio[y][x][0], tableroProvisorio[y][x][1] == 'B');
                TableroColocarPieza(&(*tablero)[y][x], pieza);

                if (pieza->esBlanca)
                {
                    piezasBlancas = (Pieza**)realloc(piezasBlancas,(cantidadDePiezasBlancas + 1) * sizeof(Pieza*));
                    piezasBlancas[cantidadDePiezasBlancas] = pieza;
                    cantidadDePiezasBlancas++;
                }
                else
                {
                    piezasNegras = (Pieza**)realloc(piezasNegras,(cantidadDePiezasNegras + 1) * sizeof(Pieza*));
                    piezasNegras[cantidadDePiezasNegras] = pieza;
                    cantidadDePiezasNegras++;
                }
            }            
        }
    }
}

void TableroCopiarPersonalizacion(char tablero[FILAS][COLUMNAS][3])
{
    for (int i = 0; i < FILAS; ++i)
    {
        for (int j = 0; j < COLUMNAS; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                tableroPersonalizado[i][j][k] = tablero[i][j][k];
            }
        }
    }    
}

void TableroImprimir(Tablero tablero)
{
    imprimirLineaHorizontalSuperior(COLUMNAS);
    
    for (int i = 0; i < FILAS; i++)
    {
        printf("\u2502");

        for (int j = 0; j < COLUMNAS; j++)
        {
            if(!PosicionEstaVacia(tablero[FILAS - i - 1][j])) 
            {
                Pieza piezaTemp = *tablero[FILAS - i - 1][j].ranura;
                PiezaImprimir(piezaTemp);
            } 
            else
            {
                printf("   ");
            }

            printf("\u2502");
        }
        
        if(i != (FILAS - 1))
        {
            imprimirLineaHorizontalCentral(COLUMNAS);
        }
        else
        {
            imprimirLineaHorizontalInferior(COLUMNAS);
        }        
    }
}

void TableroColocarPieza(Posicion* posicion, Pieza *pieza)
{
    posicion->ranura = pieza;

    PiezaColocar(pieza, posicion);
}
 
void TableroDestruir(Tablero *tablero)
{
    for (int i = 0; i < cantidadDePiezasBlancas; i++)
    {
        PiezaDestruir(piezasBlancas[i]);
    }

    for(int i = 0; i < cantidadDePiezasNegras; i++)
    {
        PiezaDestruir(piezasNegras[i]);
    }

    /*Libero las piezas que esten en el tablero*/
    for (int y = 0; y < FILAS; y++)
    {
        for (int x = 0; x < COLUMNAS; x++)
        {
            PosicionDestruir(&(*tablero)[y][x]);
        }
        
        free((*tablero)[y]);
    }
    
    destruirZona(&zonaPiezasEliminadasPorLasBlancas);
    destruirZona(&zonaPiezasEliminadasPorLasNegras);
    free(piezasBlancas);
    free(piezasNegras);
    free(*tablero);
}

int __TraducirFilaAInteger(Fila fila)
{
    return (int)(fila - 1);
}

int __TraducirColumnaAInteger(Columna columna)
{
    return (int)(columna - 'A');
}

Posicion* TableroObtenerPieza(Tablero tablero, Casilla casilla)
{
    int fila, columna;
    fila = __TraducirFilaAInteger(casilla.fila);
    columna = __TraducirColumnaAInteger(casilla.columna);

    return &tablero[fila][columna];
}

bool __MoverPieza(Tablero* tablero, Casilla casilla, Posicion* posicionInicial, Pieza* pieza)
{

    Posicion* posicionFinal = TableroObtenerPieza(*tablero, casilla);
    Pieza *piezaQueEstaEnLaPosicionFinal = posicionFinal->ranura;

    if (piezaQueEstaEnLaPosicionFinal != NULL)
    {
        if (pieza->esBlanca == piezaQueEstaEnLaPosicionFinal->esBlanca)
        {
            return false;
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
    return true;
}

status_t TableroMoverPieza(Tablero* tablero, char movimiento[4], char color)
{
    status_t status;
    Pieza* piezaAEvaluar;
    Pieza** piezasDelColor = color == 'B' ? piezasBlancas : piezasNegras;
    Pieza** piezasPosibles = NULL;
    Casilla* casillasPosibles = NULL;
    Posicion* posicionInicial;
    bool found;
    int cantidadDePiezasDelColor = color == 'B' ? cantidadDePiezasBlancas : cantidadDePiezasNegras;    
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
            if(__MoverPieza(tablero, casillasPosibles[0], piezasPosibles[0]->posicion, piezasPosibles[0]))
            {
                status = ST_OK;
            }
            else
            {
                status = ST_ERR_ATAQ_ALIADO;
            }

            break;
        default:
            status = ST_ERR_MOV_INCORRECTO;

            break;
    }

    free(casillasPosibles);
    free(piezasPosibles);

    return status;
}