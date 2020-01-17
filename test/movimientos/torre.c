#include <test.h>
#include <tableroPersonabilizable.h>

void TableroMoverPieza(Tablero* tablero, char coordenadas[4])
{

}

void testMoverLaTorreHaciaAbajo()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, TORRE_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };

    Tablero tablero;

    TableroInicializarDeCiertaForma(&tablero, tableroProvisorio);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "TD7");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[4][3].ranura == NULL);
    ASSERT(tablero[6][3].ranura != NULL);
    TableroDestruir(&tablero);
}

void testMoverLaTorreHaciaArriba()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, TORRE_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };

    Tablero tablero;

    TableroInicializarDeCiertaForma(&tablero, tableroProvisorio);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "TD3");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[4][3].ranura == NULL);
    ASSERT(tablero[2][3].ranura != NULL);
    TableroDestruir(&tablero);
}

void testMoverLaTorreHaciaLaIzquierda()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, TORRE_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };

    Tablero tablero;

    TableroInicializarDeCiertaForma(&tablero, tableroProvisorio);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "TA5");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[4][3].ranura == NULL);
    ASSERT(tablero[4][0].ranura != NULL);
    TableroDestruir(&tablero);
}


void testMoverLaTorreHaciaLaDerecha()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, TORRE_BLANCO, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };

    Tablero tablero;

    TableroInicializarDeCiertaForma(&tablero, tableroProvisorio);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "TH5");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[4][3].ranura == NULL);
    ASSERT(tablero[4][7].ranura != NULL);
    TableroDestruir(&tablero);
}

int main(void)
{   
    testMoverLaTorreHaciaAbajo();
    testMoverLaTorreHaciaArriba();
    testMoverLaTorreHaciaLaIzquierda();
    testMoverLaTorreHaciaLaDerecha();
    return 0;
}