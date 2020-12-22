#ifndef _ATAQUES_H_
#define _ATAQUES_H_

#include <struct.h>
#include <stdbool.h>
/*Pieza* zonaPiezasBlancas[16];
int contadorPiezasBlancasEliminadas = 0;
Pieza* zonaPiezasNegras[16];
int contadorPiezasNegrasEliminadas = 0;*/
typedef struct
{
    Pieza* piezas[16];
    int contador;
    bool estaInicializado;
} zonaPiezasEliminadas;


zonaPiezasEliminadas zonaPiezasEliminadasPorLasBlancas;
zonaPiezasEliminadas zonaPiezasEliminadasPorLasNegras;
void PiezaEsAtacada(Pieza*, zonaPiezasEliminadas*);
void MostrarPiezasEliminadas(zonaPiezasEliminadas);
void DestruirZona(zonaPiezasEliminadas*);


#endif