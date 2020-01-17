#include <test.h>
#include <tableroPersonabilizable.h>

void TableroMoverPieza(Tablero* tablero, char coordenadas[4])
{

}

void testMoverUnCaballoComoL()
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

    Tablero tablero;

    TableroInicializarDeCiertaForma(&tablero, tableroProvisorio);
    /*TableroImprimir(tablero);*/

    TableroMoverPieza(&tablero, "CE7");
    /*TableroImprimir(tablero);*/

    ASSERT(tablero[6][4].ranura == NULL);
    ASSERT(tablero[1][0].ranura != NULL);
    TableroDestruir(&tablero);
}

int main(void)
{
    testMoverUnCaballoComoL();
    return 0;
}