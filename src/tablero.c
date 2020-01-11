#include<stdio.h>
#include<stdlib.h>
#include<tablero.h>
#include <posicion.h>
#include<pieza.h>

#define CANTIDAD_PIEZAS 32

int TraducirColumnaAIndice(Columna columna);

void TableroInicializar(Tablero* tablero)
{
    //Guasada monumental.
    Pieza peonBlanco1, peonBlanco2, peonBlanco3, peonBlanco4, peonBlanco5, peonBlanco6, peonBlanco7, peonBlanco8, 
    torreBlanco1, torreBlanco2, 
    caballoBlanco1, caballoBlanco2, 
    alfilBlanco1, alfilBlanco2, 
    reyBlanco, reinaBlanco,
    peonNegro1, peonNegro2, peonNegro3, peonNegro4, peonNegro5, peonNegro6, peonNegro7, peonNegro8, 
    torreNegro1, torreNegro2, 
    caballoNegro1, caballoNegro2,
    alfilNegro1, alfilNegro2,
    reyNegro, reinaNegro;    

    
    PiezaCrear(&torreBlanco1  , TORRE  , true, G, UNO);
    PiezaCrear(&torreBlanco2  , TORRE  , true, G, OCHO);
    PiezaCrear(&caballoBlanco1, CABALLO, true, G, DOS);
    PiezaCrear(&caballoBlanco2, CABALLO, true, G, SIETE);
    PiezaCrear(&alfilBlanco1  , ALFIL  , true, G, TRES);
    PiezaCrear(&alfilBlanco2  , ALFIL  , true, G, SEIS);
    PiezaCrear(&reyBlanco     , REY    , true, G, CUATRO);
    PiezaCrear(&reinaBlanco   , REINA  , true, G, CINCO);

    PiezaCrear(&peonBlanco1, PEON, true, H, UNO);
    PiezaCrear(&peonBlanco2, PEON, true, H, DOS);
    PiezaCrear(&peonBlanco3, PEON, true, H, TRES);
    PiezaCrear(&peonBlanco4, PEON, true, H, CUATRO);
    PiezaCrear(&peonBlanco5, PEON, true, H, CINCO);
    PiezaCrear(&peonBlanco6, PEON, true, H, SEIS);
    PiezaCrear(&peonBlanco7, PEON, true, H, SIETE);
    PiezaCrear(&peonBlanco8, PEON, true, H, OCHO);

    PiezaCrear(&peonNegro1, PEON, false, B, UNO);
    PiezaCrear(&peonNegro2, PEON, false, B, DOS);
    PiezaCrear(&peonNegro3, PEON, false, B, TRES);
    PiezaCrear(&peonNegro4, PEON, false, B, CUATRO);
    PiezaCrear(&peonNegro5, PEON, false, B, CINCO);
    PiezaCrear(&peonNegro6, PEON, false, B, SEIS);
    PiezaCrear(&peonNegro7, PEON, false, B, SIETE);
    PiezaCrear(&peonNegro8, PEON, false, B, OCHO);
    
    PiezaCrear(&torreNegro1, TORRE, false, A, UNO);
    PiezaCrear(&torreNegro2, TORRE, false, A, OCHO);
    PiezaCrear(&caballoNegro1, CABALLO, false, A, DOS);
    PiezaCrear(&caballoNegro2, CABALLO, false, A, SIETE);
    PiezaCrear(&alfilNegro1, ALFIL, false, A, TRES);
    PiezaCrear(&alfilNegro2, ALFIL, false, A, SEIS);
    PiezaCrear(&reyNegro, REY, false, A, CUATRO);
    PiezaCrear(&reinaNegro, REINA, false, A, CINCO);

    Pieza piezas[CANTIDAD_PIEZAS] = {
        torreBlanco1, torreBlanco2, caballoBlanco1, caballoBlanco2, alfilBlanco1, alfilBlanco2, reyBlanco, reinaBlanco,
        peonBlanco1, peonBlanco2, peonBlanco3, peonBlanco4, peonBlanco5, peonBlanco6, peonBlanco7, peonBlanco8,
        peonNegro1, peonNegro2, peonNegro3, peonNegro4, peonNegro5, peonNegro6, peonNegro7, peonNegro8,
        torreNegro1, torreNegro2, caballoNegro1, caballoNegro2, alfilNegro1, alfilNegro2, reyNegro, reinaNegro
    };

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
        }
    }

    for(int i = 0; i < CANTIDAD_PIEZAS; i++)
    {
        TableroColocarPieza(tablero, piezas[i]);
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

void TableroColocarPieza(Tablero* tablero, Pieza pieza) {
    int columnaIndice = TraducirColumnaAIndice(pieza.columnaActual);
    (*tablero)[pieza.filaActual - 1][columnaIndice].ranura = (Pieza*)malloc(sizeof(Pieza));
    PiezaCopiar((*tablero)[pieza.filaActual - 1][columnaIndice].ranura, pieza);
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

int TraducirColumnaAIndice(Columna columna) {
    return (int)(columna - 'A');
}