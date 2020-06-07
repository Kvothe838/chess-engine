#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <tablero.h>
#include <posicion.h>
#include <pieza.h>
#include <casilla.h>
#include <ataques.h>
#include <imprimir.h>

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

void TableroDestruir(Tablero *tablero)
{
    for (int y = 0; y < FILAS; y++)
    {
        for (int x = 0; x < COLUMNAS; x++)
        {
            PosicionDestruir(&(*tablero)[y][x]);
        }
        
        free((*tablero)[y]);
    }
    
    free(*tablero);
}