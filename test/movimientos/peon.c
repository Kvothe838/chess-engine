#include <test.h>
#include <tablero.h>
#define TABLERO_PERSONALIZADO
#include <tipo_tablero.h>

void testMoverUnPeonEnUnaPosicion()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {PEON_BLANCO, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Tablero tablero;

    TableroInicializar(&tablero);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "PA2");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[0][0].ranura == NULL);
    ASSERT(tablero[1][0].ranura != NULL);
    TableroDestruir(&tablero);
}

void testMoverUnPeonDosPosicionesEnSuPosiconInicial()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {PEON_BLANCO, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Tablero tablero;

    TableroInicializar(&tablero);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "PA3");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[0][0].ranura == NULL);
    ASSERT(tablero[2][0].ranura != NULL);
    TableroDestruir(&tablero);
}

void testNoMoverUnPeonDosPosicionesEnUnaPosicionesNoInicial()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {PEON_BLANCO, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Tablero tablero;

    TableroInicializar(&tablero);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "PA2");
    /*TableroImprimir(tablero);*/
    TableroMoverPieza(&tablero, "PA4");
    /*TableroImprimir(tablero);*/
    
    ASSERT(tablero[3][0].ranura == NULL);
    ASSERT(tablero[1][0].ranura != NULL);
    TableroDestruir(&tablero);
}

int main(void)
{
    testMoverUnPeonEnUnaPosicion();
    testMoverUnPeonDosPosicionesEnSuPosiconInicial();
    testNoMoverUnPeonDosPosicionesEnUnaPosicionesNoInicial();
    return 0;
}