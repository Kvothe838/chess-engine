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

// void TableroMovimiento(Tablero *tablero, char movimiento[3], char color) {
//     Pieza** piezasDelColor = color != 'B' ? piezasBlancas : piezasNegras;
//     int cantidadDelColor = color != 'B' ? cantidadDePiezasBlancas : cantidadDePiezasNegras;    
//     Casilla* casillas;    
//     Pieza* piezas = NULL;
//     int cantidadPiezas = 0;

//     for(int i = 0; i < cantidadDelColor; i++) {
//         Pieza piezaAEvaluar = piezasDelColor[i];
        
//         if(piezaAEvaluar->tipo == movimiento[0]) {
//             printf("ENTRÉ ACÁ POR LA PIEZA EN LA POSICIÓN %c%d", piezaAEvaluar->posicion->casilla->columna, piezaAEvaluar->posicion->casilla->fila);

//             int cantidadPosiblesMovimientos = CasillaObtenerPosibles(piezaAEvaluar->posicion, &casillas);
//             bool found = false;
            
//             for(int j = 0; j < cantidadPosiblesMovimientos; j++) {                
//                 Casilla casilla = casillas[j];
//                 char str[1] = {movimiento[2]};
//                 int filaMovimiento = atoi(str);

//                 if(casilla.columna == movimiento[1] && casilla.fila == filaMovimiento) {
//                     found = true;
//                     break;
//                 }
//             }

//             if(found) {
//                 if(piezas == NULL){
//                     *piezas = malloc(sizeof(Pieza));
//                 } else {
//                     *piezas = (Pieza*) realloc(*piezas, (cantidadPiezas + 1) * sizeof(Pieza));
//                 }

//                 piezas[cantidadPiezas] = piezaAEvaluar;
//                 cantidadPiezas++;
//             }
            
//             free(casillas);
//         }
//     }

//     switch(cantidadPiezas) {
//         case 0:
//             printf("No se pudo mover ninguna pieza.");
//             break;
//         case 1:
//             printf("Pieza movida.");
//             break;
//         default:
//             printf("Más de una pieza del tipo especificado pueden moverse a la posición especificada.\nPor favor, escriba el comando detallando la columna o fila a la que pertenece la pieza que se quiere mover.");
//             break;
//     }
// }

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

void __MoverPieza(Tablero* tablero, Casilla casilla, Posicion* posicionInicial, Pieza* pieza)
{
    Posicion* posicionFinal = TableroObtenerPieza(*tablero, casilla);
    posicionInicial->ranura = NULL;
    TableroColocarPieza(posicionFinal, pieza);
}

void TableroMoverPieza(Tablero* tablero, char movimiento[4], char color)
{
    Pieza* piezaAEvaluar;
    Pieza** piezasDelColor = color == 'B' ? piezasBlancas : piezasNegras;
    Pieza** piezasPosibles = NULL;
    Casilla* casillas;
    Casilla* casillasPosibles = NULL;
    Posicion* posicionInicial;
    bool found;
    int cantidadDePiezasDelColor = color == 'B' ? cantidadDePiezasBlancas : cantidadDePiezasNegras;    
    int cantidadPiezasPosibles = 0;

    for (int i = 0; i < cantidadDePiezasDelColor; ++i)
    {
        piezaAEvaluar = piezasDelColor[i];

        if (piezaAEvaluar->tipo == movimiento[0])
        {
            posicionInicial = piezaAEvaluar->posicion;
            found = false;

            int cantidadPosiblesMovimientos = CasillaObtenerPosibles(posicionInicial, &casillas);
            
            for (int j = 0; j < cantidadPosiblesMovimientos; ++j)
            {
                if (casillas[j].columna == (Columna)movimiento[1] &&
                    casillas[j].fila == (Fila)(movimiento[2] - '0'))
                {
                    casillasPosibles = (Casilla*) realloc(casillasPosibles, (cantidadPiezasPosibles+1) * sizeof(Casilla));                    
                    casillasPosibles[cantidadPiezasPosibles] = casillas[j];
                    found = true;
                    break;
                }
            }

            if(found) 
            {
                piezasPosibles = (Pieza**) realloc(piezasPosibles, (cantidadPiezasPosibles + 1) * sizeof(Pieza*));                
                piezasPosibles[cantidadPiezasPosibles] = piezaAEvaluar;
                cantidadPiezasPosibles++;
            }
        }
    }

    switch(cantidadPiezasPosibles){
        case 0:
            printf("No se encontraron movimientos posibles.");
            break;
        case 1:
            __MoverPieza(tablero, casillasPosibles[0], piezasPosibles[0]->posicion, piezasPosibles[0]);
            free(casillasPosibles);
            //free(piezasPosibles);

            // for(int i = 0; i < cantidadPiezasPosibles; i++)
            // {
            //     free(piezasPosibles[i]);
            // }

            // free(piezasPosibles);
            break;
        default:
            printf("Se encontró más de una pieza posible para mover.");
            break;
    }
}
