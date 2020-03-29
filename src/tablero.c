#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <tablero.h>
#include <posicion.h>
#include <pieza.h>
#include <casilla.h>

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

void __imprimirLineaHorizontalSuperior(size_t largo)
{
    printf("\n");
    printf("\u250C");

    for (int i = 0; i < largo; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("\u2500");
        }

        if(i != (largo - 1))
        {
            printf("\u252C");
        }        
    }

    printf("\u2510");
    printf("\n");   
}

void __imprimirLineaHorizontalCentral(size_t largo)
{
    printf("\n");
    printf("\u251C");

    for (int i = 0; i < largo; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("\u2500");
        }

        if(i != (largo - 1))
        {
            printf("\u253C");
        }        
    }

    printf("\u2524");
    printf("\n");   
}

void __imprimirLineaHorizontalInferior(size_t largo)
{
    printf("\n");
    printf("\u2514");

    for (int i = 0; i < largo; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("\u2500");
        }

        if(i != (largo - 1))
        {
            printf("\u2534");
        }        
    }

    printf("\u2518");
    printf("\n");
   
}

void TableroImprimir(Tablero tablero)
{
    __imprimirLineaHorizontalSuperior(COLUMNAS);
    
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
            __imprimirLineaHorizontalCentral(COLUMNAS);
        }
        else
        {
            __imprimirLineaHorizontalInferior(COLUMNAS);
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

    for (int y = 0; y < FILAS; y++)
    {
        for (int x = 0; x < COLUMNAS; x++)
        {
            PosicionDestruir(&(*tablero)[y][x]);
        }
        
        free((*tablero)[y]);
    }
    
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

void __MoverPieza(Tablero* tablero, Casilla casilla, Posicion* posicionInicial, Pieza* pieza)
{
    Posicion* posicionFinal = TableroObtenerPieza(*tablero, casilla);
    posicionInicial->ranura = NULL;

    TableroColocarPieza(posicionFinal, pieza);
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

        if (piezaAEvaluar->tipo == movimiento[0])
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
            __MoverPieza(tablero, casillasPosibles[0], piezasPosibles[0]->posicion, piezasPosibles[0]);
            status = ST_OK;

            break;
        default:
            status = ST_ERR_MOV_INCORRECTO;

            break;
    }

    free(casillasPosibles);
    free(piezasPosibles);

    return status;
}