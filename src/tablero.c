#include<stdio.h>
#include<stdlib.h>
#include<tablero.h>
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

    PiezaCrear(&peonBlanco1, PEON, true, G, UNO);
    PiezaCrear(&peonBlanco2, PEON, true, G, DOS);
    PiezaCrear(&peonBlanco3, PEON, true, G, TRES);
    PiezaCrear(&peonBlanco4, PEON, true, G, CUATRO);
    PiezaCrear(&peonBlanco5, PEON, true, G, CINCO);
    PiezaCrear(&peonBlanco6, PEON, true, G, SEIS);
    PiezaCrear(&peonBlanco7, PEON, true, G, SIETE);
    PiezaCrear(&peonBlanco8, PEON, true, G, OCHO);
    
    PiezaCrear(&torreBlanco1, TORRE, true, H, UNO);
    PiezaCrear(&torreBlanco2, TORRE, true, H, OCHO);
    PiezaCrear(&caballoBlanco1, CABALLO, true, H, DOS);
    PiezaCrear(&caballoBlanco2, CABALLO, true, H, SIETE);
    PiezaCrear(&alfilBlanco1, ALFIL, true, H, TRES);
    PiezaCrear(&alfilBlanco2, ALFIL, true, H, SEIS);
    PiezaCrear(&reyBlanco, REY, true, H, CUATRO);
    PiezaCrear(&reinaBlanco, REINA, true, H, CINCO);

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
    
    Pieza tableroProvisorio[FILAS][COLUMNAS];

    for(int i = 0; i < CANTIDAD_PIEZAS; i++) {
        int columnaIndice = TraducirColumnaAIndice(piezas[i].columnaActual);
        tableroProvisorio[piezas[i].filaActual - 1][columnaIndice] = piezas[i];
    }

    *tablero = (Tablero) malloc(FILAS * sizeof(Pieza*));

    for (int i = 0; i < FILAS; i++)
    {
        (*tablero)[i] = tableroProvisorio[i];
    }
}

void TableroImprimir(Tablero tablero)
{
    printf("\n—————————————————————————————————————————\n");
    
    for (int i = 0; i < FILAS; i++)
    {
        printf("|");        

        for (int j = 0; j < COLUMNAS; j++)
        {
            Pieza piezaTemp = tablero[i][j];
            printf(" %c%c |", piezaTemp.esPieza ? (char)piezaTemp.tipo : ' ', piezaTemp.esPieza ? (piezaTemp.esBlanca ? 'B' : 'N') : ' ');
        }

        printf("\n—————————————————————————————————————————\n");
    }
}

void TableroDestruir(Tablero tablero)
{
    for (int i = 0; i < FILAS; i++)
    {
        free(tablero[i]);
    }

    free(tablero);
}

int TraducirColumnaAIndice(Columna columna) {
    return (int)(columna - 'A');
}