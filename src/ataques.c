#include <stdio.h>
#include <ataques.h>
#include <pieza.h>
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
    initializarZona(zona);
    zona->piezas[zona->contador++] = pieza;
    pieza->posicion = NULL;
}

void mostrarPiezasEliminadas(zonaPiezasEliminadas zona)
{
    int limiteHorizontal = 8;
    for(int i = 0; i < zona.contador; i++)
    {
        if (i == limiteHorizontal)
        {
            printf("\n");
        }
        
        PiezaImprimir(*(zona.piezas[i]));
        printf("  ");
    }
    printf("\n");
}