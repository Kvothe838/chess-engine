#include <imprimir.h>


void ImprimirLineaHorizontalSuperior(size_t largo)
{
    if(largo == 0)
    {
        return;
    }

    printf("\n");
    printf("\u250C");

    for (int i = 0; i < largo; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("\u2500");
        }

        if(i != (largo - 1))
        {
            printf("\u252C");
        }
    }

    printf("\u2510");
    printf("\n");
}

void ImprimirLineaHorizontalCentral(size_t largo)
{
    if(largo == 0)
    {
        return;
    }

    printf("\n");
    printf("\u251C");

    for (int i = 0; i < largo; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("\u2500");
        }

        if(i != (largo - 1))
        {
            printf("\u253C");
        }
    }

    printf("\u2524");
    printf("\n");
}

void ImprimirLineaHorizontalInferior(size_t largo)
{
    if(largo == 0)
    {
        return;
    }

    printf("\n");
    printf("\u2514");

    for (int i = 0; i < largo; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("\u2500");
        }

        if(i != (largo - 1))
        {
            printf("\u2534");
        }
    }

    printf("\u2518");
    printf("\n");
}