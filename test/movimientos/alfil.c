#include <test.h>
#include <tablero.h>
#define TABLERO_PERSONALIZADO
#include <tipo_tablero.h>
#include <interfaz.h>

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

    Juego testJuego;
    char jugador = 'B';
    

    TableroInicializar(&(testJuego.tablero));
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
        TableroMoverPieza(&(testJuego.tablero), movimiento, jugador);
        /*TableroImprimir(tablero);*/
        
        ASSERT(testJuego.tablero[0][0].ranura == NULL);
        ASSERT(testJuego.tablero[i][i].ranura != NULL);

        TableroMoverPieza(&(testJuego.tablero), movimiento, jugador);
        ASSERT(testJuego.tablero[0][0].ranura != NULL);
        ASSERT(testJuego.tablero[i][i].ranura == NULL);

    }
    
    free(movimiento);
    Terminar(&testJuego);
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

    Juego testJuego;
    char jugador = 'B';

    TableroInicializar(&(testJuego.tablero));
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
        TableroMoverPieza(&(testJuego.tablero), movimiento, jugador);
        /*TableroImprimir(tablero);*/
        
        ASSERT(testJuego.tablero[0][7].ranura == NULL);
        ASSERT(testJuego.tablero[i][7 - i].ranura != NULL);

        TableroMoverPieza(&(testJuego.tablero), movimiento, jugador);
        ASSERT(testJuego.tablero[0][7].ranura != NULL);
        ASSERT(testJuego.tablero[i][7 - i].ranura == NULL);

    }
    
    free(movimiento);
    Terminar(&testJuego);
}

int main(void)
{   
    testMoverElAlfilDiagonalPositiva();
    testMoverElAlfilDiagonalNegatica();
    return 0;
}