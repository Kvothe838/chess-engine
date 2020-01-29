#include<stdio.h>
#include<stdlib.h>
#include<tablero.h>

int main(void)
{
    Tablero tablero;
    char movimiento[4]= "CA3";

    TableroInicializar(&tablero);
    TableroMoverPieza(&tablero, movimiento, 'B');
    TableroImprimir(tablero);
    TableroDestruir(&tablero);

    return EXIT_SUCCESS;
}