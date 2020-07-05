#include <test.h>
/*#include <tablero.h>*/
#include <movimiento.h>
#define TABLERO_PERSONALIZADO
#include <tipo_juego.h>
#include <interfaz.h>

void testMoverLaReinaVertical()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, REINA_BLANCO, NADA, NADA, NADA, NADA},
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

    char* posicionInicial = "RD1";
    char* movimiento;
    movimiento = calloc(3+1, sizeof(char));
    movimiento[0] = 'R';
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

void testMoverLaReinaHorizontal()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {REINA_BLANCO, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA}
    };
    TableroCopiarPersonalizacion(tableroProvisorio);

    Juego testJuego;
    char jugador = 'B';

    INICIALIZAR_JUEGO(&(testJuego));
    /*TableroImprimir(tablero);*/

    char* posicionInicial = "RA5";
    char* movimiento;
    movimiento = calloc(3+1, sizeof(char));
    movimiento[0] = 'R';
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


void testMoverLaReinaDiagonalPositiva()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {REINA_BLANCO, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
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

    char* posicionInicial = "RA1";
    char* movimiento;
    movimiento = calloc(3+1, sizeof(char));
    movimiento[0] = 'R';
    movimiento[1] = 'A';
    movimiento[2] = '1';
    movimiento[3] = '\0';
    for (int i = 1; i < 8; ++i)
    {
        movimiento[1] = posicionInicial[1] + (char)i;
        movimiento[2] = posicionInicial[2] + (char)i;
        CalcularMovimiento(&(testJuego), movimiento, jugador);
        /*TableroImprimir(tablero);*/
        
        ASSERT(testJuego.tablero[0][0].ranura == NULL);
        ASSERT(testJuego.tablero[i][i].ranura != NULL);

        CalcularMovimiento(&(testJuego), posicionInicial, jugador);
        ASSERT(testJuego.tablero[0][0].ranura != NULL);
        ASSERT(testJuego.tablero[i][i].ranura == NULL);

    }
    
    free(movimiento);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}

void testMoverLaReinaDiagonalNegatica()
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, REINA_BLANCO},
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

    char* posicionInicial = "RH1";
    char* movimiento;
    movimiento = calloc(3+1, sizeof(char));
    movimiento[0] = 'R';
    movimiento[1] = 'H';
    movimiento[2] = '1';
    movimiento[3] = '\0';
    for (int i = 1; i < 8; ++i)
    {
        movimiento[1] = posicionInicial[1] - (char)i;
        movimiento[2] = posicionInicial[2] + (char)i;
        CalcularMovimiento(&(testJuego), movimiento, jugador);
        /*TableroImprimir(tablero);*/
        
        ASSERT(testJuego.tablero[0][7].ranura == NULL);
        ASSERT(testJuego.tablero[i][7 - i].ranura != NULL);

        CalcularMovimiento(&(testJuego), posicionInicial, jugador);
        ASSERT(testJuego.tablero[0][7].ranura != NULL);
        ASSERT(testJuego.tablero[i][7 - i].ranura == NULL);

    }
    
    free(movimiento);
    /*TableroDestruir(&(testJuego.tablero));*/
    Terminar(&testJuego);
}


int main(void)
{   
    testMoverLaReinaVertical();
    testMoverLaReinaHorizontal();
    testMoverLaReinaDiagonalPositiva();
    testMoverLaReinaDiagonalNegatica();
    return 0;
}