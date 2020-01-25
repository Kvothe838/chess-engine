#include <test.h>
#include <tablero.h>
#define TABLERO_PERSONALIZADO
#include <tipo_tablero.h>

void testMoverLaReinaHaciaAbajo()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REINA_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Tablero tablero;

    TableroInicializar(&tablero);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "RD7");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[4][3].ranura == NULL);
    ASSERT(tablero[6][3].ranura != NULL);
    TableroDestruir(&tablero);
}

void testMoverLaReinaHaciaArriba()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REINA_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Tablero tablero;

    TableroInicializar(&tablero);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "RD3");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[4][3].ranura == NULL);
    ASSERT(tablero[2][3].ranura != NULL);
    TableroDestruir(&tablero);
}

void testMoverLaReinaHaciaLaIzquierda()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REINA_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Tablero tablero;

    TableroInicializar(&tablero);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "RA5");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[4][3].ranura == NULL);
    ASSERT(tablero[4][0].ranura != NULL);
    TableroDestruir(&tablero);
}


void testMoverLaReinaHaciaLaDerecha()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REINA_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Tablero tablero;

    TableroInicializar(&tablero);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "RH5");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[4][3].ranura == NULL);
    ASSERT(tablero[4][7].ranura != NULL);
    TableroDestruir(&tablero);
}

void testMoverLaReinaDiagonalSuperiorIzquierda()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REINA_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Tablero tablero;

    TableroInicializar(&tablero);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "RB3");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[4][3].ranura == NULL);
    ASSERT(tablero[2][1].ranura != NULL);
    TableroDestruir(&tablero);
}

void testMoverLaReinaDiagonalSuperiorDerecha()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REINA_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Tablero tablero;

    TableroInicializar(&tablero);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "RE4");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[4][3].ranura == NULL);
    ASSERT(tablero[3][4].ranura != NULL);
    TableroDestruir(&tablero);
}

void testMoverLaReinaDiagonalInferiorIzquierda()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REINA_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Tablero tablero;

    TableroInicializar(&tablero);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "RB7");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[4][3].ranura == NULL);
    ASSERT(tablero[6][1].ranura != NULL);
    TableroDestruir(&tablero);
}


void testMoverLaReinaDiagonalInferiorDerecha()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, REINA_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Tablero tablero;

    TableroInicializar(&tablero);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "RG8");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[4][3].ranura == NULL);
    ASSERT(tablero[7][6].ranura != NULL);
    TableroDestruir(&tablero);
}

int main(void)
{   
    testMoverLaReinaHaciaAbajo();
    testMoverLaReinaHaciaArriba();
    testMoverLaReinaHaciaLaIzquierda();
    testMoverLaReinaHaciaLaDerecha();
    testMoverLaReinaDiagonalSuperiorIzquierda();
    testMoverLaReinaDiagonalSuperiorDerecha();
    testMoverLaReinaDiagonalInferiorIzquierda();
    testMoverLaReinaDiagonalInferiorDerecha();
    return 0;
}