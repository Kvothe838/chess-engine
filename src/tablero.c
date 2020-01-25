#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <tablero.h>
#include <posicion.h>
#include <pieza.h>
#include <casilla.h>

#define CANTIDAD_PIEZAS 32

Pieza** piezasBlancas;
int cantidadDePiezasBlancas;

Pieza** piezasNegras;
int cantidadDePiezasNegras;

void __TableroInicializar(char tableroProvisorio[FILAS][COLUMNAS][3], Tablero* tablero)
{
    Pieza *pieza;
    int coordenada[2];

    *tablero = (Tablero) malloc(FILAS * sizeof(Posicion*));

    cantidadDePiezasBlancas = 0;
    cantidadDePiezasNegras = 0;
    
    for (int y = 0; y < FILAS; y++)
    {
        coordenada[0] = y;
        (*tablero)[y] = (Posicion*)malloc(COLUMNAS * sizeof(Posicion));

        for (int x = 0; x < COLUMNAS; x++)
        {
            coordenada[1] = x;
            PosicionInicializar(&((*tablero)[y][x]), coordenada);
            
            if (strcmp(tableroProvisorio[y][x], NADA) != 0)
            {
                pieza = (Pieza*)malloc(sizeof(Pieza));
                PiezaCrear(pieza, tableroProvisorio[y][x][0], tableroProvisorio[y][x][1] == 'B');
                TableroColocarPieza(&(*tablero)[y][x], pieza);

                if (pieza->esBlanca)
                {
                    piezasBlancas = (Pieza**)realloc(piezasBlancas,(cantidadDePiezasBlancas + 1) * sizeof(Pieza*));
                    piezasBlancas[cantidadDePiezasBlancas] = pieza;
                    cantidadDePiezasBlancas++;
                }
                else
                {
                    piezasNegras = (Pieza**)realloc(piezasNegras,(cantidadDePiezasNegras + 1) * sizeof(Pieza*));
                    piezasNegras[cantidadDePiezasNegras] = pieza;
                    cantidadDePiezasNegras++;
                }
            }            
        }
    }
}

void TableroCopiarPersonalizacion(char tablero[FILAS][COLUMNAS][3])
{
    for (int i = 0; i < FILAS; ++i)
    {
        for (int j = 0; j < COLUMNAS; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                tableroPersonalizado[i][j][k] = tablero[i][j][k];
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

    free(piezasBlancas);
    free(piezasNegras);

    free(*tablero);
}

void TableroMovimiento(Tablero *tablero) {
    Posicion* posicion = &((*tablero)[0][2]);
    Pieza* pieza = posicion->ranura;
    
    if(pieza == NULL){
        printf("No hay pieza.");
        return;
    }

    Casilla* casillas;
    int cantidadPosiblesMovimientos = CasillaObtenerPosibles(posicion, &casillas);

    printf("COLOR: %c\n", pieza->esBlanca ? 'B' : 'N');
    printf("TIPO: %c\n", pieza->tipo);
    printf("POSICION: %c%d\n", posicion->casilla->columna, posicion->casilla->fila+1);
    printf("CANTIDAD: %d\n", cantidadPosiblesMovimientos);
    printf("CASILLAS A LAS QUE SE PUEDE MOVER: \n\n");

    for(int i = 0; i < cantidadPosiblesMovimientos; i++) {
        printf("CASILLA %d: %c%d\n", i, casillas[i].columna, casillas[i].fila);
    }
    free(casillas);
}

int __TraducirFilaAInteger(Fila fila)
{
    return (int)(fila - 1);
}

int __TraducirColumnaAInteger(Columna columna)
{
    return (int)(columna - 'A');
}

Posicion* TableroObtenerPieza(Tablero tablero, Casilla casilla)
{
    int fila, columna;
    fila = __TraducirFilaAInteger(casilla.fila);
    columna = __TraducirColumnaAInteger(casilla.columna);
    return &tablero[fila][columna];
}

void TableroMoverPieza(Tablero* tablero, char movimiento[4])
{
    //Supongo que siempre mueve las blancas, hay que hacer algo para alternar
    Pieza* pieza;
    Casilla* casillas;
    Posicion* posicionInicial, * posicionFinal;
    bool salir;

    for (int i = 0; i < cantidadDePiezasBlancas; ++i)
    {
        if (piezasBlancas[i]->tipo == movimiento[0])
        {
            /*printf("%s\n", "SE ECONTRO EL TIPO DE PIEZA");*/
            pieza = piezasBlancas[i];
            posicionInicial = pieza->posicion;
            salir = false;

            int cantidadPosiblesMovimientos = CasillaObtenerPosibles(posicionInicial, &casillas);
            for (int j = 0; j < cantidadPosiblesMovimientos; ++j)
            {
                /*printf("%c%d\n", casillas[j].columna, casillas[j].fila);*/
                if (casillas[j].columna == (Columna)movimiento[1] &&
                    casillas[j].fila == (Fila)(movimiento[2] - '0'))
                {
                    /*printf("%s\n", "ECONTRO LA CASILLA");*/

                    posicionFinal = TableroObtenerPieza(*tablero, casillas[j]);
                    posicionInicial->ranura = NULL;
                    TableroColocarPieza(posicionFinal, pieza);
                    salir = true;
                    break;
                }
            }
            if (salir)
            {
                break;
            }
        }
    }
}