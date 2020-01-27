#include<stdio.h>
#include<stdlib.h>
#include<tablero.h>

int main(void)
{
    Tablero tablero;
    char movimiento[4]= "TA1";

    TableroInicializar(&tablero);
    TableroMoverPieza(&tablero, movimiento, 'N');
    TableroImprimir(tablero);
    TableroDestruir(&tablero);

    return EXIT_SUCCESS;
}