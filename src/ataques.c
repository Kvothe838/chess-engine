#include <stdio.h>
#include <ataques.h>
#include <pieza.h>
#include <imprimir.h>

void initializarZona(zonaPiezasEliminadas* zona)
{
    if(!zona->estaInicializado)
    {
        zona->estaInicializado = true;
        zona->contador = 0;
    }
}

void PiezaEsAtacada(Pieza* pieza, zonaPiezasEliminadas* zona)
{   
    /*
    Truquito, como la posicion en donde esta la pieza
    va a ser ocupada con la pieza que la esta atacando
    no tengo que modificarlo.
    */
    initializarZona(zona);
    zona->piezas[zona->contador++] = pieza;
    pieza->posicion = NULL;
}

void mostrarPiezasEliminadas(zonaPiezasEliminadas zona)
{
    if(zona.contador == 0)
    {
        return;
    }
    int limiteHorizontal = 8;
    imprimirLineaHorizontalSuperior(zona.contador);
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
    imprimirLineaHorizontalInferior(zona.contador);
    printf("\n");
}

void destruirZona(zonaPiezasEliminadas* zona)
{
    for(int i = 0; i < zona->contador; i++)
    {
        free(zona->piezas[i]);
    }
}