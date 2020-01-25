#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> 
#include <tablero.h>
#include <tipo_tablero.h>

int main(void)
{
    Tablero tablero;

    TableroInicializar(&tablero);
    TableroMovimiento(&tablero);
    TableroImprimir(tablero);
    TableroDestruir(&tablero);

    return EXIT_SUCCESS;
}