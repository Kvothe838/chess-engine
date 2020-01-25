#include <test.h>
#include <tablero.h>
#define TABLERO_PERSONALIZADO
#include <tipo_tablero.h>

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

    Tablero tablero;

    TableroInicializar(&tablero);
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
        TableroMoverPieza(&tablero, movimiento);
        /*TableroImprimir(tablero);*/
        
        ASSERT(tablero[0][3].ranura == NULL);
        ASSERT(tablero[i][3].ranura != NULL);

        TableroMoverPieza(&tablero, posicionInicial);
        ASSERT(tablero[0][3].ranura != NULL);
        ASSERT(tablero[i][3].ranura == NULL);

    }
    
    free(movimiento);
    TableroDestruir(&tablero);
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

    Tablero tablero;

    TableroInicializar(&tablero);
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
        TableroMoverPieza(&tablero, movimiento);
        /*TableroImprimir(tablero);*/
        
        ASSERT(tablero[4][0].ranura == NULL);
        ASSERT(tablero[4][i].ranura != NULL);

        TableroMoverPieza(&tablero, posicionInicial);
        /*TableroImprimir(tablero);*/
        ASSERT(tablero[4][0].ranura != NULL);
        ASSERT(tablero[4][i].ranura == NULL);

    }
    
    free(movimiento);
    TableroDestruir(&tablero);
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

    Tablero tablero;

    TableroInicializar(&tablero);
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

    Tablero tablero;

    TableroInicializar(&tablero);
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
    testMoverLaReinaVertical();
    testMoverLaReinaHorizontal();
    testMoverLaReinaDiagonalPositiva();
    testMoverLaReinaDiagonalNegatica();
    return 0;
}