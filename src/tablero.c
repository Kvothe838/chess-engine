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

    CrearPieza(&peonBlanco1, PEON, true, G, UNO);
    CrearPieza(&peonBlanco2, PEON, true, G, DOS);
    CrearPieza(&peonBlanco3, PEON, true, G, TRES);
    CrearPieza(&peonBlanco4, PEON, true, G, CUATRO);
    CrearPieza(&peonBlanco5, PEON, true, G, CINCO);
    CrearPieza(&peonBlanco6, PEON, true, G, SEIS);
    CrearPieza(&peonBlanco7, PEON, true, G, SIETE);
    CrearPieza(&peonBlanco8, PEON, true, G, OCHO);
    
    CrearPieza(&torreBlanco1, TORRE, true, H, UNO);
    CrearPieza(&torreBlanco2, TORRE, true, H, OCHO);
    CrearPieza(&caballoBlanco1, CABALLO, true, H, DOS);
    CrearPieza(&caballoBlanco2, CABALLO, true, H, SIETE);
    CrearPieza(&alfilBlanco1, ALFIL, true, H, TRES);
    CrearPieza(&alfilBlanco2, ALFIL, true, H, SEIS);
    CrearPieza(&reyBlanco, REY, true, H, CUATRO);
    CrearPieza(&reinaBlanco, REINA, true, H, CINCO);

    CrearPieza(&peonNegro1, PEON, false, B, UNO);
    CrearPieza(&peonNegro2, PEON, false, B, DOS);
    CrearPieza(&peonNegro3, PEON, false, B, TRES);
    CrearPieza(&peonNegro4, PEON, false, B, CUATRO);
    CrearPieza(&peonNegro5, PEON, false, B, CINCO);
    CrearPieza(&peonNegro6, PEON, false, B, SEIS);
    CrearPieza(&peonNegro7, PEON, false, B, SIETE);
    CrearPieza(&peonNegro8, PEON, false, B, OCHO);
    
    CrearPieza(&torreNegro1, TORRE, false, A, UNO);
    CrearPieza(&torreNegro2, TORRE, false, A, OCHO);
    CrearPieza(&caballoNegro1, CABALLO, false, A, DOS);
    CrearPieza(&caballoNegro2, CABALLO, false, A, SIETE);
    CrearPieza(&alfilNegro1, ALFIL, false, A, TRES);
    CrearPieza(&alfilNegro2, ALFIL, false, A, SEIS);
    CrearPieza(&reyNegro, REY, false, A, CUATRO);
    CrearPieza(&reinaNegro, REINA, false, A, CINCO);

    Pieza piezas[CANTIDAD_PIEZAS] = {
        peonBlanco1, peonBlanco2, peonBlanco3, peonBlanco4, peonBlanco5, peonBlanco6, peonBlanco7, peonBlanco8,
        torreBlanco1, torreBlanco2, caballoBlanco1, caballoBlanco2, alfilBlanco1, alfilBlanco2, reyBlanco, reinaBlanco,
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
            char variableTurbiaParaMostrar[2];
            variableTurbiaParaMostrar[0] = tablero[i][j].tipo;
            variableTurbiaParaMostrar[1] = (tablero[i][j].esBlanca ? 'B' : 'N');
            printf(" %s |", variableTurbiaParaMostrar);
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