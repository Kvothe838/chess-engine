#include <test.h>
/*#include <tablero.h>*/
#include <movimiento.h>
#define TABLERO_PERSONALIZADO
#include <tipo_juego.h>
#include <interfaz.h>

void testMoverLaTorreVertical()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, TORRE_BLANCO, NADA, NADA, NADA, NADA},
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

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    char* posicionInicial = "TD1";
    char* movimiento;
    movimiento = calloc(3+1, sizeof(char));
    movimiento[0] = 'T';
    movimiento[1] = 'D';
  //movimiento[2] = '1';
    movimiento[3] = '\0';
    for (int i = 1; i < 8; ++i)
    {
        movimiento[2] = posicionInicial[2] + (char)i;
        CalcularMovimiento(&(testJuego), movimiento, jugador);
        /*TableroImprimir(tablero);*/
        
        ASSERT(testJuego.tablero[0][3].ranura == NULL);
        ASSERT(testJuego.tablero[i][3].ranura != NULL);

        CalcularMovimiento(&(testJuego), posicionInicial, jugador);
        ASSERT(testJuego.tablero[0][3].ranura != NULL);
        ASSERT(testJuego.tablero[i][3].ranura == NULL);

    }
    
    free(movimiento);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

void testMoverLaTorreHorizontal()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {TORRE_BLANCO, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    char* posicionInicial = "TA5";
    char* movimiento;
    movimiento = calloc(3+1, sizeof(char));
    movimiento[0] = 'T';
  //movimiento[1] = 'A';
    movimiento[2] = '5';
    movimiento[3] = '\0';
    for (int i = 1; i < 8; ++i)
    {
        movimiento[1] = posicionInicial[1] + (char)i;
        CalcularMovimiento(&(testJuego), movimiento, jugador);
        /*TableroImprimir(tablero);*/
        
        ASSERT(testJuego.tablero[4][0].ranura == NULL);
        ASSERT(testJuego.tablero[4][i].ranura != NULL);

        CalcularMovimiento(&(testJuego), posicionInicial, jugador);
        /*TableroImprimir(tablero);*/
        ASSERT(testJuego.tablero[4][0].ranura != NULL);
        ASSERT(testJuego.tablero[4][i].ranura == NULL);

    }
    
    free(movimiento);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}


int main(void)
{   
    testMoverLaTorreVertical();
    testMoverLaTorreHorizontal();
    return 0;
}