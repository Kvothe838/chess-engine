#include <stdio.h>
#include <locale.h>
#include <pieza.h>
#include <posicion.h>
#include <stdarg.h>
#include <stdlib.h>

void __PiezaCrearCoordenadas(Coordenada** coordenadas, int len, int** coordenadasEnNumero/*, ...*/)
{
    (*coordenadas) = (Coordenada*) malloc(len * sizeof(Coordenada));

    for (int i = 0; i < len; i++)
    {
        ((*coordenadas)[i])[0] = (*coordenadasEnNumero)[2*i];
        ((*coordenadas)[i])[1] = (*coordenadasEnNumero)[2*i+1];
    }
}

void __ValoresCoordenadasInicializar(int** valoresCoordenadas, int cantidadMovimientos)
{
    (*valoresCoordenadas) = (int*) malloc(2 * cantidadMovimientos * sizeof(int));
}

void __ValoresCoordenadasLlenar_Rey(int** valoresCoordenadas)
{
    (*valoresCoordenadas)[0] = (*valoresCoordenadas)[2] = (*valoresCoordenadas)[5] = (*valoresCoordenadas)[7] = 0;
    (*valoresCoordenadas)[1] = (*valoresCoordenadas)[4] = (*valoresCoordenadas)[8] = (*valoresCoordenadas)[9] = (*valoresCoordenadas)[10] = (*valoresCoordenadas)[13] = 1;
    (*valoresCoordenadas)[3] = (*valoresCoordenadas)[6] = (*valoresCoordenadas)[11] = (*valoresCoordenadas)[12] = (*valoresCoordenadas)[14] = (*valoresCoordenadas)[15] = -1;
/*  Coordenadas más visibles 
    (0,1), 
    (0,-1), 
    (1,0), 
    (-1,0), 
    (1,1), 
    (1,-1), 
    (-1,1), 
    (-1,-1)  */
}

void __ValoresCoordenadasLlenar_Reina(int** valoresCoordenadas)
{
    for(int j = 0; j < 56; j++)
    {
        if(j >= 0 && j < 7)
        {
            (*valoresCoordenadas)[2*j] = 0;
            (*valoresCoordenadas)[2*j+1] = j+1;
        } 
        else if(j >= 7 && j < 14)
        {
            (*valoresCoordenadas)[2*j] = 0;
            (*valoresCoordenadas)[2*j+1] = 6-j;
        } 
        else if(j >= 14 && j < 21)
        {
            (*valoresCoordenadas)[2*j] = j-13;
            (*valoresCoordenadas)[2*j+1] = 0;
        }
        else if(j >= 21 && j < 28)
        {
            (*valoresCoordenadas)[2*j] = 20-j;
            (*valoresCoordenadas)[2*j+1] = 0;
        }
        else if (j >= 28 && j < 35)
        {
            (*valoresCoordenadas)[2*j] = j-27;
            (*valoresCoordenadas)[2*j+1] = j-27;
        }
        else if (j >= 35 && j < 42)
        {
            (*valoresCoordenadas)[2*j] = 34-j;
            (*valoresCoordenadas)[2*j+1] = 34-j;
        }
        else if (j >= 42 && j < 49)
        {
            (*valoresCoordenadas)[2*j] = j-41;
            (*valoresCoordenadas)[2*j+1] = 41-j;
        }
        else if (j >= 49 && j < 56)
        {
            (*valoresCoordenadas)[2*j] = 48-j;
            (*valoresCoordenadas)[2*j+1] = j-48;
        }
    }                
}

void __ValoresCoordenadasLlenar_Torre(int** valoresCoordenadas)
{
    for(int j = 0; j < 28; j++)
    {
        if(j >= 0 && j < 7)
        {
            (*valoresCoordenadas)[2*j] = 0;
            (*valoresCoordenadas)[2*j+1] = j+1;
        }
        else if(j >= 7 && j < 14)
        {
            (*valoresCoordenadas)[2*j] = 0;
            (*valoresCoordenadas)[2*j+1] = 6-j;
        }
        else if(j >= 14 && j < 21)
        {
            (*valoresCoordenadas)[2*j] = j-13;
            (*valoresCoordenadas)[2*j+1] = 0;
        }
        else if(j >= 21 && j < 28)
        {
            (*valoresCoordenadas)[2*j] = 20-j;
            (*valoresCoordenadas)[2*j+1] = 0;
        }
    }
}

void __ValoresCoordenadasLlenar_Alfil(int** valoresCoordenadas)
{
    for(int j = 0; j < 28; j++)
    {
        if (j >= 0 && j < 7)
        {
            (*valoresCoordenadas)[2*j] = j+1;
            (*valoresCoordenadas)[2*j+1] = j+1;
        }
        else if (j >= 7 && j < 14)
        {
            (*valoresCoordenadas)[2*j] = 6-j;
            (*valoresCoordenadas)[2*j+1] = 6-j;
        }
        else if (j >= 14 && j < 21)
        {
            (*valoresCoordenadas)[2*j] = j-13;
            (*valoresCoordenadas)[2*j+1] = 13-j;
        }
        else if (j >= 21 && j < 28)
        {
            (*valoresCoordenadas)[2*j] = 20-j;
            (*valoresCoordenadas)[2*j+1] = j-20;
        }
    }
}

void __ValoresCoordenadasLlenar_Caballo(int** valoresCoordenadas)
{
    (*valoresCoordenadas)[0] = (*valoresCoordenadas)[2] = (*valoresCoordenadas)[5] = (*valoresCoordenadas)[7] = 2;
    (*valoresCoordenadas)[1] = (*valoresCoordenadas)[4] = (*valoresCoordenadas)[8] = (*valoresCoordenadas)[15] = 1;
    (*valoresCoordenadas)[3] = (*valoresCoordenadas)[6] = (*valoresCoordenadas)[10] = (*valoresCoordenadas)[13] = -1;
    (*valoresCoordenadas)[9] = (*valoresCoordenadas)[11] = (*valoresCoordenadas)[12] = (*valoresCoordenadas)[14] = -2;
/*  Coordenadas más visibles 
    (2,1),     
    (2,-1), 
    (1,2),
    (-1,2), 
    (1,-2),     
    (-1,-2), 
    (-2,-1), 
    (-2,1)  */
}

void __ValoresCoordenadasLlenar_Peon(int** valoresCoordenadas)
{
    (*valoresCoordenadas)[0] = 1;
    (*valoresCoordenadas)[1] = 0;
}

int PiezaObtenerCantidadMovimientos(TipoPieza tipo)
{
    int cantidad;

    switch (tipo)
    {
        case REY:
            cantidad = 8;            
            break;

        case REINA:
            cantidad = 56;
            break;

        case TORRE:
            cantidad = 28;
            break;

        case ALFIL:
            cantidad = 28;
            break;

        case CABALLO:
            cantidad = 8;
            break;

        case PEON:
            cantidad = 1;
            break;
    }

    return cantidad;
}

void __PiezaRepresentacionYMovimientos(Pieza* pieza, TipoPieza tipo)
{
    setlocale(LC_ALL, "");
    
    int base = 0x2654;
    Coordenada* coordenadas;
    int* valoresCoordenadas;
    int cantidadMovimientos = PiezaObtenerCantidadMovimientos(tipo);

    __ValoresCoordenadasInicializar(&valoresCoordenadas, cantidadMovimientos);

    if(pieza->esBlanca)
    {
        base += 6;
    }
    
    switch (tipo)
    {
        case REY:
            base += 0;
            __ValoresCoordenadasLlenar_Rey(&valoresCoordenadas);
            
            break;

        case REINA:
            base += 1;
            __ValoresCoordenadasLlenar_Reina(&valoresCoordenadas);            

            break;

        case TORRE:
            base += 2;
            __ValoresCoordenadasLlenar_Torre(&valoresCoordenadas);

            break;

        case ALFIL:
            base += 3;
            __ValoresCoordenadasLlenar_Alfil(&valoresCoordenadas);

            break;

        case CABALLO:
            base += 4;
            __ValoresCoordenadasLlenar_Caballo(&valoresCoordenadas);

            break;

        case PEON:
            base += 5;
            __ValoresCoordenadasLlenar_Peon(&valoresCoordenadas);

            break;
    }

    __PiezaCrearCoordenadas(&coordenadas, cantidadMovimientos, &valoresCoordenadas);
    free(valoresCoordenadas);

    pieza->representacion = base;
    pieza->coordenadasMovimientosPosibles = coordenadas;
}

void PiezaCrear(Pieza* pieza, TipoPieza tipo, bool esBlanca)
{
    pieza->tipo = tipo;
    pieza->esBlanca = esBlanca;
    pieza->posicion = NULL;
    pieza->coordenadasMovimientosPosibles = NULL;

    __PiezaRepresentacionYMovimientos(pieza, tipo);
}

void PiezaCopiar(Pieza* copia, Pieza original)
{
    copia->tipo = original.tipo;
    copia->esBlanca = original.esBlanca;
}

void PiezaColocar(Pieza* pieza, Posicion* posicion)
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

void PiezaDestruir(Pieza* pieza)
{
    if(pieza != NULL && pieza->coordenadasMovimientosPosibles != NULL)
    {
        free(pieza->coordenadasMovimientosPosibles);
    }
}

void PiezaDestruirMultiples(Pieza*** conjuntoDePiezas, size_t cantidadDePiezas)
{
    for(size_t i = 0; i < cantidadDePiezas; ++i)
    {
        PiezaDestruir((*conjuntoDePiezas)[i]);
        free((*conjuntoDePiezas)[i]);
    }
    free(*conjuntoDePiezas);
}