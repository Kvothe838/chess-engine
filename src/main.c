#include<stdio.h>
#include<stdlib.h>
#include<tablero.h>

int main(void)
{
    Tablero tablero;
    char movimiento[3]= "CA3";

    TableroInicializar(&tablero);
    TableroMovimiento(&tablero, movimiento, 'N');
    TableroImprimir(tablero);
    TableroDestruir(&tablero);

    return EXIT_SUCCESS;
}