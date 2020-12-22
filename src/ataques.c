#include <stdio.h>
#include <ataques.h>
#include <pieza.h>
#include <imprimir.h>

void __inicializarZona(zonaPiezasEliminadas* zona)
{
    if(!zona->estaInicializado)
    {
        zona->estaInicializado = true;
        zona->contador = 0;
    }
}

void PiezaEsAtacada(Pieza* pieza, zonaPiezasEliminadas* zona)
{
    __inicializarZona(zona);
    zona->piezas[zona->contador++] = pieza;
    pieza->posicion = NULL;
}

void MostrarPiezasEliminadas(zonaPiezasEliminadas zona)
{
    if(zona.contador == 0)
    {
        return;
    }

    int limiteHorizontal = 8;

    ImprimirLineaHorizontalSuperior(zona.contador);

    for(int i = 0; i < zona.contador; i++)
    {
        if (i == limiteHorizontal)
        {
            printf("\n");
        }
        printf("\u2502");
        PiezaImprimir(*(zona.piezas[i]));
    }

    printf("\u2502");
    ImprimirLineaHorizontalInferior(zona.contador);
    printf("\n");
}

void DestruirZona(zonaPiezasEliminadas* zona)
{
    for(int i = 0; i < zona->contador; i++)
    {
        free(zona->piezas[i]);
    }
}
