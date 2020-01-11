#include<stdio.h>
#include<stdlib.h>
#include<tablero.h>

int main(void)
{
    Tablero tablero;

    TableroInicializar(&tablero);

    TableroImprimir(tablero);

    TableroDestruir(tablero);

    return EXIT_SUCCESS;
}