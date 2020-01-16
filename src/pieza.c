#include <stdio.h>
#include <locale.h>
#include <pieza.h>
#include <posicion.h>
#include <stdarg.h>
#include <stdlib.h>

void __PiezaCrearCoordenadas(Coordenada** coordenadas, int len, int** coordenadasEnNumero/*, ...*/) {
    (*coordenadas) = (Coordenada*) malloc(len * sizeof(Coordenada));

    for (int i = 0; i < len; i++) {
        (*coordenadas)[i][0] = (*coordenadasEnNumero)[2*i];
        (*coordenadas)[i][1] = (*coordenadasEnNumero)[2*i+1];
    }
}

void __PiezaRepresentacionYMovimientos(Pieza* pieza, TipoPieza tipo)
{
    setlocale(LC_ALL, "");
    int base = 0x2654;
    Coordenada* coordenadas;
    int * posiciones;

    if(pieza->esBlanca)
    {
        base += 6;
    }
    
    switch (tipo) {
        case REY:
            base += 0;
            
            posiciones = (int*) malloc(16 * sizeof(int));
            posiciones[0] = posiciones[2] = posiciones[5] = posiciones[7] = 0;
            posiciones[1] = posiciones[4] = posiciones[8] = posiciones[9] = posiciones[10] = posiciones[13] = 1;
            posiciones[3] = posiciones[6] = posiciones[11] = posiciones[12] = posiciones[14] = posiciones[15] = -1;
            //Coordenadas más visibles 
        /*  (0,1), 
            (0,-1), 
            (1,0), 
            (-1,0), 
            (1,1), 
            (1,-1), 
            (-1,1), 
            (-1,-1)  */
            __PiezaCrearCoordenadas(&coordenadas, 16, &posiciones);
            break;

        case REINA:
            base += 1;
            posiciones = (int*) malloc(56 * sizeof(int));

            for(int i = 0; i < 7; i++) {
                for(int j = i*7; j < (i+1)*7; j++) {
                    if(j >= 0 && j < 7) {
                        posiciones[2*j] = 0;
                        posiciones[2*j+1] = j+1;
                    } else if(j >= 7 && j < 14) {
                        posiciones[2*j] = 0;
                        posiciones[2*j+1] = 6-j;
                    } else if(j >= 14 && j < 21) {
                        posiciones[2*j] = j-14;
                        posiciones[2*j+1] = 0;
                    } else if(j >= 21 && j < 28) {
                        posiciones[2*j] = 21-j;
                        posiciones[2*j+1] = 0;
                    } else if (j >= 28 && j < 35) {
                        posiciones[2*j] = j-27;
                        posiciones[2*j+1] = j-27;
                    } else if (j >= 35 && j < 42) {
                        posiciones[2*j] = 34-j;
                        posiciones[2*j+1] = 34-j;
                    } else if (j >= 42 && j < 49) {
                        posiciones[2*j] = j-41;
                        posiciones[2*j+1] = 41-j;
                    } else if (j >= 49 && j < 56) {
                        posiciones[2*j] = 48-j;
                        posiciones[2*j+1] = j-48;
                    }
                }                
            }

            __PiezaCrearCoordenadas(&coordenadas, 56, &posiciones);
            break;

        case TORRE:
            base += 2;
            break;

        case ALFIL:
            base += 3;
            break;

        case CABALLO:
            base += 4;
            break;

        case PEON:
            base += 5;
            break;   
    }

    //Liberar posiciones.
    
    pieza->representacion = base;
    pieza->coordenadasMovimientosPosibles = coordenadas;
}

void PiezaCrear(Pieza* pieza, TipoPieza tipo, bool esBlanca)
{
    pieza->tipo = tipo;
    pieza->esBlanca = esBlanca;
    pieza->posicion = NULL;
    __PiezaRepresentacionYMovimientos(pieza, tipo);
}

void PiezaCopiar(Pieza* copia, Pieza original)
{
    copia->tipo = original.tipo;
    copia->esBlanca = original.esBlanca;
}

void PiezaEsColocada(Pieza* pieza, Posicion* posicion)
{
    pieza->posicion = posicion;
}

bool PiezaEstaPuesta(Pieza pieza)
{
    return pieza.posicion != NULL;
}

void PiezaImprimir(Pieza pieza)
{
    printf("\u2002%lc\u2002", pieza.representacion);
}