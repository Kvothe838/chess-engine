#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> 
#include <tablero.h>
#include <tipo_tablero.h>

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