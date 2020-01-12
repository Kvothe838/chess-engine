#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <tablero.h>
#include <posicion.h>
#include <pieza.h>

#define CANTIDAD_PIEZAS 32

int TraducirColumnaAIndice(Columna columna);

void TableroInicializar(Tablero* tablero)
{
    char tableroProvisorio[FILAS][COLUMNAS][3] = 
    {
        {TORRE_BLANCO, CABALLO_BLANCO, ALFIL_BLANCO, REY_BLANCO, REINA_BLANCO, ALFIL_BLANCO, CABALLO_BLANCO, TORRE_BLANCO},
        {PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},
        {PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO},
        {TORRE_NEGRO, CABALLO_NEGRO, ALFIL_NEGRO, REY_NEGRO, REINA_NEGRO, ALFIL_NEGRO, CABALLO_NEGRO, TORRE_NEGRO}
        
    };
    
    Pieza *pieza;

    *tablero = (Tablero) malloc(FILAS * sizeof(Posicion*));
    int coordenada[2];
    for (int y = 0; y < FILAS; y++)
    {
        coordenada[1] = y;
        (*tablero)[y] = (Posicion*)malloc(COLUMNAS * sizeof(Posicion));
        for (int x = 0; x < COLUMNAS; x++)
        {
            coordenada[0] = x;
            PosicionInicializar(&((*tablero)[y][x]), coordenada);
            
            if (strcmp(tableroProvisorio[y][x], NADA) != 0)
            {
                pieza = (Pieza*)malloc(sizeof(Pieza));
                PiezaCrear(pieza, tableroProvisorio[y][x][0], tableroProvisorio[y][x][1] == 'B');
                TableroColocarPieza(&(*tablero)[y][x], pieza);
            }
            
        }
    }

}

void __imprimirLineaHorizontal(size_t largo)
{
    printf("\n");
    for (int i = 0; i < (5*largo)+1; ++i)
    {
        printf("%s", "—");
    }
    printf("\n");
   
}

void TableroImprimir(Tablero tablero)
{
    __imprimirLineaHorizontal(COLUMNAS);
    
    for (int i = 0; i < FILAS; i++)
    {
        printf("|");        

        for (int j = 0; j < COLUMNAS; j++)
        {
            if(!PosicionEstaVacia(tablero[i][j])) 
            {
                Pieza piezaTemp = *tablero[i][j].ranura;
                printf(" %c%c ", piezaTemp.tipo, (piezaTemp.esBlanca ? 'B' : 'N'));
            }
            else
            {
                printf("    ");
            }
            printf("|");
        }

        __imprimirLineaHorizontal(COLUMNAS);
    }
}

void TableroColocarPieza(Posicion* posicion, Pieza *pieza)
{
    posicion->ranura = pieza;
    PiezaEsColocada(pieza, posicion);
}
 
void TableroDestruir(Tablero *tablero)
{
    for (int y = 0; y < FILAS; y++)
    {
        for (int x = 0; x < COLUMNAS; x++)
        {
            PosicionDestruir(&(*tablero)[y][x]);
        }
        free((*tablero)[y]);
    }

    free(*tablero);
}

int TraducirColumnaAIndice(Columna columna)
{
    return (int)(columna - 'A');
}