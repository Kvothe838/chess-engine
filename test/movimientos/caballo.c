#include <test.h>
/*#include <tablero.h>*/
#include <movimiento.h>
#define TABLERO_PERSONALIZADO
#include <tipo_juego.h>
#include <juego.h>

void testMoverUnCaballo1()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, CABALLO_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "CE7", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[6][4].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

void testMoverUnCaballo2()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, CABALLO_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "CF6", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[5][5].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

void testMoverUnCaballo3()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, CABALLO_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "CF4", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[3][5].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

void testMoverUnCaballo4()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, CABALLO_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "CE3", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[2][4].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

void testMoverUnCaballo5()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, CABALLO_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "CC3", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[2][2].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

void testMoverUnCaballo6()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, CABALLO_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "CB4", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[3][1].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

void testMoverUnCaballo7()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, CABALLO_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "CB6", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[5][1].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

void testMoverUnCaballo8()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, CABALLO_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    CalcularMovimiento(&(testJuego), "CC7", jugador);
    /*TableroImprimir(tablero);*/

    ASSERT(testJuego.tablero[4][3].ranura == NULL);
    ASSERT(testJuego.tablero[6][2].ranura != NULL);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}


int main(void)
{
    testMoverUnCaballo1();
    testMoverUnCaballo2();
    testMoverUnCaballo3();
    testMoverUnCaballo4();
    testMoverUnCaballo5();
    testMoverUnCaballo6();
    testMoverUnCaballo7();
    testMoverUnCaballo8();
    return 0;
}