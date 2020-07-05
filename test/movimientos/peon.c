#include <test.h>
#include <tablero.h>
#define TABLERO_PERSONALIZADO
#include <tipo_tablero.h>
#include <interfaz.h>

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

    Juego testJuego;
    char jugador = 'B';

    TableroInicializar(&(testJuego.tablero));
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&(testJuego.tablero), "PA2", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[0][0].ranura == NULL);
    ASSERT(testJuego.tablero[1][0].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
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

    Juego testJuego;
    char jugador = 'B';

    TableroInicializar(&(testJuego.tablero));
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&(testJuego.tablero), "PA3", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[0][0].ranura == NULL);
    ASSERT(testJuego.tablero[2][0].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
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

    Juego testJuego;
    char jugador = 'B';

    TableroInicializar(&(testJuego.tablero));
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&(testJuego.tablero), "PA2", jugador);
    /*TableroImprimir(tablero);*/
    TableroMoverPieza(&(testJuego.tablero), "PA4", jugador);
    /*TableroImprimir(tablero);*/
    
    ASSERT(testJuego.tablero[3][0].ranura == NULL);
    ASSERT(testJuego.tablero[1][0].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

int main(void)
{
    testMoverUnPeonEnUnaPosicion();
    testMoverUnPeonDosPosicionesEnSuPosiconInicial();
    testNoMoverUnPeonDosPosicionesEnUnaPosicionesNoInicial();
    return 0;
}