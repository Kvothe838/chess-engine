#include <stdio.h>
#include <locale.h>
#include <pieza.h>
#include <posicion.h>
#include <stdarg.h>
#include <stdlib.h>

//Sacado operador ... porque por ahora está al pedo.
void __PiezaCrearCoordenadas(Coordenada* coordenadas, int len, int* coordenadasEnNumero/*, ...*/) {
    coordenadas = (Coordenada*) malloc(len * sizeof(Coordenada));

    for (int i = 0; i < len; i++) {
        /*Esta mierda es la que falla. Probé de todo, pero hay algo que no estoy entendiendo.
        (como a quién verga se le ocurrió inventar esta cosa llamada C, puaj)*/
        /*problema--->*/*(coordenadas[i]) = (Coordenada*) malloc(sizeof(Coordenada));
        coordenadas[i][0] = coordenadasEnNumero[2*i];
        coordenadas[i][1] = coordenadasEnNumero[2*i+1];
        printf("x: %d | y: %d", coordenadas[i][0], coordenadas[i][1]);    
    }
}

void __PiezaRepresentacionYMovimientos(Pieza* pieza, TipoPieza tipo)
{
    setlocale(LC_ALL, "");
    int base = 0x2654;
    Coordenada* coordenadas;

    if(pieza->esBlanca)
    {
        base += 6;
    }
    
    switch (tipo) {
        case REY:
            base += 0;
            //Ignora2 porque ya le saqué el operador ...
            // __PiezaCrearCoordenadas(&coordenadas, 8, 
            //     0, 1, 
            //     0, -1, 
            //     1, 0, 
            //     -1, 0, 
            //     1, 1, 
            //     1, -1, 
            //     -1, 1, 
            //     -1, -1);
            break;

        case REINA:
            base += 1;
            int* posicionesReina = (int*) malloc(56*sizeof(int));

            for(int i = 0; i < 7; i++) {
                if(i >= 0 && i < 7) {
                    posicionesReina[2*i] = 0;
                    posicionesReina[2*i+1] = i+1;
                } else if(i >= 7 && i < 14) {
                    posicionesReina[2*i] = 0;
                    posicionesReina[2*i+1] = 6-i;
                } else if(i >= 14 && i < 21) {
                    posicionesReina[2*i] = i-14;
                    posicionesReina[2*i+1] = 0;
                } else if(i >= 21 && i < 28) {
                    posicionesReina[2*i] = 21-i;
                    posicionesReina[2*i+1] = 0;
                } else if (i >= 28 && i < 35) {
                    posicionesReina[2*i] = i-27;
                    posicionesReina[2*i+1] = i-27;
                } else if (i >= 35 && i < 42) {
                    posicionesReina[2*i] = 34-i;
                    posicionesReina[2*i+1] = 34-i;
                } else if (i >= 42 && i < 49) {
                    posicionesReina[2*i] = i-41;
                    posicionesReina[2*i+1] = 41-i;
                } else if (i >= 49 && i < 56) {
                    posicionesReina[2*i] = 48-i;
                    posicionesReina[2*i+1] = i-48;
                }
            }

            //Estos parámetros son pruebas, la verdad no entiendo qué poronga mandar.
            __PiezaCrearCoordenadas(&(*coordenadas), 56, &(*posicionesReina));
            free(posicionesReina);
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