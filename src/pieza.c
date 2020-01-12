#include <stdio.h>
#include <locale.h>
#include <pieza.h>

void __PiezaClasificarRepresentacion(Pieza* pieza, TipoPieza tipo)
{
    setlocale(LC_ALL, "");
    int base = 0x2654;

    if(pieza->esBlanca)
    {
        base += 6;
    }
    
    switch (tipo) {
        case REY:
            base += 0;
            break;

        case REINA:
            base += 1;
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
}

void PiezaCrear(Pieza* pieza, TipoPieza tipo, bool esBlanca)
{
    pieza->tipo = tipo;
    pieza->esBlanca = esBlanca;
    pieza->posicion = NULL;
    __PiezaClasificarRepresentacion(pieza, tipo);
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