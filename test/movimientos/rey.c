#include <test.h>
/*#include <tablero.h>*/
#include <movimiento.h>
#define TABLERO_PERSONALIZADO
#include <tipo_juego.h>
#include <juego.h>

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

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "KD6", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[5][3].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    JuegoDestruir(&testJuego);
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

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "KD4", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[3][3].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    JuegoDestruir(&testJuego);
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

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "KC5", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[4][2].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    JuegoDestruir(&testJuego);
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

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "KE5", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[4][4].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    JuegoDestruir(&testJuego);
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

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "KC4", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[3][2].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    JuegoDestruir(&testJuego);
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

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "KE4", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[3][4].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    JuegoDestruir(&testJuego);
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

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "KC6", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[3][2].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    JuegoDestruir(&testJuego);
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

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "KE6", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[5][4].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    JuegoDestruir(&testJuego);
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