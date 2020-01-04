#include<stdio.h>
#include<stdlib.h>

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

void imprimirTablero(char*** tablero)
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

char*** obtenerTableroInicial()
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

    char*** tablero = (char***) malloc(FILAS * sizeof(char**));

    for (int i = 0; i < FILAS; i++)
    {
        tablero[i] = (char**) malloc(COLUMNAS * sizeof(char*));

        for (int j = 0; j < COLUMNAS; j++)
        {
            tablero[i][j] = (char*) malloc(COLUMNAS * sizeof(char));

            for (int k = 0; k < 3; k++)
            {
                tablero[i][j][k] = tableroProvisorio[i][j][k];
            }
        }
    }

    return tablero;
}