#include<stdio.h>
#include<stdlib.h>
#include<tablero.h>

int main(void)
{
    char*** tablero = TableroInicializar();

    TableroImprimir(tablero);

    FreeTablero(tablero);    

    return EXIT_SUCCESS;
}

void FreeTablero(char*** tablero)
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