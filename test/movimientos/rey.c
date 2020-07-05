#include <test.h>
#include <tablero.h>
#define TABLERO_PERSONALIZADO
#include <tipo_tablero.h>
#include <interfaz.h>

void testMoverElReyHaciaAbajo()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REY_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    TableroInicializar(&(testJuego.tablero));
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&(testJuego.tablero), "KD6", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[5][3].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

void testMoverElReyHaciaArriba()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REY_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    TableroInicializar(&(testJuego.tablero));
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&(testJuego.tablero), "KD4", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[3][3].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

void testMoverElReyHaciaLaIzquierda()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REY_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    TableroInicializar(&(testJuego.tablero));
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&(testJuego.tablero), "KC5", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[4][2].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}


void testMoverElReyHaciaLaDerecha()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REY_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    TableroInicializar(&(testJuego.tablero));
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&(testJuego.tablero), "KE5", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[4][4].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

void testMoverElReyDiagonalSuperiorIzquierda()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REY_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    TableroInicializar(&(testJuego.tablero));
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&(testJuego.tablero), "KC4", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[3][2].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

void testMoverElReyDiagonalSuperiorDerecha()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REY_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    TableroInicializar(&(testJuego.tablero));
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&(testJuego.tablero), "KE4", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[3][4].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

void testMoverElReyDiagonalInferiorIzquierda()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REY_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    TableroInicializar(&(testJuego.tablero));
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&(testJuego.tablero), "KC6", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[3][2].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}


void testMoverElReyDiagonalInferiorDerecha()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REY_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    TableroInicializar(&(testJuego.tablero));
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&(testJuego.tablero), "KE6", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[5][4].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

int main(void)
{   
    testMoverElReyHaciaAbajo();
    testMoverElReyHaciaArriba();
    testMoverElReyHaciaLaIzquierda();
    testMoverElReyHaciaLaDerecha();
    testMoverElReyDiagonalSuperiorIzquierda();
    testMoverElReyDiagonalSuperiorDerecha();
    testMoverElReyDiagonalInferiorIzquierda();
    testMoverElReyDiagonalInferiorDerecha();
    return 0;
}