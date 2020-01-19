#include <test.h>
#include <tableroPersonabilizable.h>

void TableroMoverPieza(Tablero* tablero, char coordenadas[4])
{

}

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

    Tablero tablero;

    TableroInicializarDeCiertaForma(&tablero, tableroProvisorio);
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
        movimiento[2] = '1' + (char)i;
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

    Tablero tablero;

    TableroInicializarDeCiertaForma(&tablero, tableroProvisorio);
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
        movimiento[1] = 'A' + (char)i;
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


int main(void)
{   
    testMoverLaTorreVertical();
    testMoverLaTorreHorizontal();
    return 0;
}