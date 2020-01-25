#include <test.h>
#include <tablero.h>
#define TABLERO_PERSONALIZADO
#include <tipo_tablero.h>

void testMoverElAlfilDiagonalPositiva()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {ALFIL_BLANCO, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
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

    char* posicionInicial = "AA1";
    char* movimiento;
    movimiento = calloc(3+1, sizeof(char));
    movimiento[0] = 'A';
    movimiento[1] = 'A';
    movimiento[2] = '1';
    movimiento[3] = '\0';
    for (int i = 1; i < 8; ++i)
    {
        movimiento[1] = posicionInicial[1] + (char)i;
        movimiento[2] = posicionInicial[2] + (char)i;
        TableroMoverPieza(&tablero, movimiento);
        /*TableroImprimir(tablero);*/
        
        ASSERT(tablero[0][0].ranura == NULL);
        ASSERT(tablero[i][i].ranura != NULL);

        TableroMoverPieza(&tablero, posicionInicial);
        ASSERT(tablero[0][0].ranura != NULL);
        ASSERT(tablero[i][i].ranura == NULL);

    }
    
    free(movimiento);
    TableroDestruir(&tablero);
}

void testMoverElAlfilDiagonalNegatica()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, ALFIL_BLANCO},
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

    char* posicionInicial = "AH1";
    char* movimiento;
    movimiento = calloc(3+1, sizeof(char));
    movimiento[0] = 'A';
    movimiento[1] = 'H';
    movimiento[2] = '1';
    movimiento[3] = '\0';
    for (int i = 1; i < 8; ++i)
    {
        movimiento[1] = posicionInicial[1] - (char)i;
        movimiento[2] = posicionInicial[2] + (char)i;
        TableroMoverPieza(&tablero, movimiento);
        /*TableroImprimir(tablero);*/
        
        ASSERT(tablero[0][7].ranura == NULL);
        ASSERT(tablero[i][7 - i].ranura != NULL);

        TableroMoverPieza(&tablero, posicionInicial);
        ASSERT(tablero[0][7].ranura != NULL);
        ASSERT(tablero[i][7 - i].ranura == NULL);

    }
    
    free(movimiento);
    TableroDestruir(&tablero);
}

int main(void)
{   
    testMoverElAlfilDiagonalPositiva();
    testMoverElAlfilDiagonalNegatica();
    return 0;
}