#include<stdio.h>
#include<stdlib.h>
#include<tablero.h>

void TableroInicializar(Tablero* tablero)
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO},
        {TORRE_BLANCO, CABALLO_BLANCO, ALFIL_BLANCO, REY_BLANCO, REINA_BLANCO, ALFIL_BLANCO, CABALLO_BLANCO, TORRE_BLANCO},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {TORRE_NEGRO, CABALLO_NEGRO, ALFIL_NEGRO, REY_NEGRO, REINA_NEGRO, ALFIL_NEGRO, CABALLO_NEGRO, TORRE_NEGRO},
        {PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO}
    };

    *tablero = (Tablero) malloc(FILAS * sizeof(char**));

    for (int i = 0; i < FILAS; i++)
    {
        (*tablero)[i] = (char**) malloc(COLUMNAS * sizeof(char*));

        for (int j = 0; j < COLUMNAS; j++)
        {
            (*tablero)[i][j] = (char*) malloc(COLUMNAS * sizeof(char));

            for (int k = 0; k < 3; k++)
            {
                (*tablero)[i][j][k] = tableroProvisorio[i][j][k];
            }
        }
    }
}

void TableroImprimir(Tablero tablero)
{
    printf("\n—————————————————————————————————————————\n");
    
    for (int i = 0; i < FILAS; i++)
    {
        printf("|");

        for (int j = 0; j < COLUMNAS; j++)
        {
            printf(" %s |", tablero[i][j]);            
        }

        printf("\n—————————————————————————————————————————\n");
    }
}

void TableroDestruir(Tablero tablero)
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            free(tablero[i][j]);
        }

        free(tablero[i]);
    }

    free(tablero);
}