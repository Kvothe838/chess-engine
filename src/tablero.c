#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <tablero.h>
#include <posicion.h>
#include <pieza.h>
#include <casilla.h>

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
    int coordenada[2];

    *tablero = (Tablero) malloc(FILAS * sizeof(Posicion*));
    
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

void __imprimirLineaHorizontalSuperior(size_t largo)
{
    printf("\n");
    printf("\u250C");

    for (int i = 0; i < largo; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("\u2500");
        }

        if(i != (largo - 1))
        {
            printf("\u252C");
        }        
    }

    printf("\u2510");
    printf("\n");   
}

void __imprimirLineaHorizontalCentral(size_t largo)
{
    printf("\n");
    printf("\u251C");

    for (int i = 0; i < largo; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("\u2500");
        }

        if(i != (largo - 1))
        {
            printf("\u253C");
        }        
    }

    printf("\u2524");
    printf("\n");   
}

void __imprimirLineaHorizontalInferior(size_t largo)
{
    printf("\n");
    printf("\u2514");

    for (int i = 0; i < largo; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("\u2500");
        }

        if(i != (largo - 1))
        {
            printf("\u2534");
        }        
    }

    printf("\u2518");
    printf("\n");
   
}

void TableroImprimir(Tablero tablero)
{
    __imprimirLineaHorizontalSuperior(COLUMNAS);
    
    for (int i = 0; i < FILAS; i++)
    {
        printf("\u2502");

        for (int j = 0; j < COLUMNAS; j++)
        {
            if(!PosicionEstaVacia(tablero[i][j])) 
            {
                Pieza piezaTemp = *tablero[i][j].ranura;
                PiezaImprimir(piezaTemp);
            } 
            else
            {
                printf("   ");
            }

            printf("\u2502");
        }
        
        if(i != (FILAS - 1))
        {
            __imprimirLineaHorizontalCentral(COLUMNAS);
        }
        else
        {
            __imprimirLineaHorizontalInferior(COLUMNAS);
        }        
    }
}

void TableroColocarPieza(Posicion* posicion, Pieza *pieza)
{
    posicion->ranura = pieza;
    PiezaColocar(pieza, posicion);
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

void TableroMovimiento(Tablero *tablero) {
    Pieza* pieza = tablero[0][0]->ranura;
    Posicion* posicion = pieza->posicion;
    Casilla* casillas;
    int cantidadPosiblesMovimientos = CasillaObtenerPosibles(posicion, &casillas);

    printf("COLOR: %c\n", pieza->esBlanca ? 'B' : 'N');
    printf("TIPO: %c\n", pieza->tipo);
    printf("CANTIDAD: %d\n", cantidadPosiblesMovimientos);
    printf("CASILLAS A LAS QUE SE PUEDE MOVER: \n\n");

    for(int i = 0; i < cantidadPosiblesMovimientos; i++) {
        printf("CASILLA %d: %c%d\n", i, casillas[i].columna, casillas[i].fila);
    }
}