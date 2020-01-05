#include<stdio.h>
#include<stdlib.h>
#include<tablero.h>

int main(void)
{
    char*** tablero = TableroInicializar();

    TableroImprimir(tablero);

    return EXIT_SUCCESS;
}