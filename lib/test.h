#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define APROBADO "El test fue aprobado"
#define FALLO1 "Fallo el test en la linea: "
#define FALLO2 ", con la condicion: "
#define RESULTADO "Numero de tests aprobadas en"

size_t NUMERO_PRUEBAS = 0;
size_t PRUEBAS_APROBADAS = 0;
char* FUNCION_ACTUAL = NULL;
bool FUNCION_PASA = true;

#define PRINT_ANALISIS()\
{\
    if(FUNCION_PASA)\
    {\
        printf("%s\n", APROBADO);\
        PRUEBAS_APROBADAS++;\
    }\
    printf("\n");\
}

#define ASSERT(CONDICION)\
{\
    if(FUNCION_ACTUAL == NULL || strcmp(FUNCION_ACTUAL, __func__) != 0)\
    {\
        if (FUNCION_ACTUAL != NULL)\
        {\
            PRINT_ANALISIS();\
            \
            FUNCION_PASA = true;\
        }\
        \
        printf("Probando %s: \n", __func__);\
        FUNCION_ACTUAL = (char*)realloc(FUNCION_ACTUAL, sizeof(char)*(strlen(__func__)+1));\
        strcpy(FUNCION_ACTUAL, __func__);\
        NUMERO_PRUEBAS++;\
    }\
    \
    if(!(CONDICION))\
    {\
        FUNCION_PASA = false;\
        printf("%s%d%s\"%s\"\n", FALLO1, __LINE__, FALLO2, #CONDICION);\
    }\
}

void __attribute__((destructor)) resultado()
{
    if(FUNCION_ACTUAL != NULL)
    {
        PRINT_ANALISIS();
        free(FUNCION_ACTUAL);
    }
    printf("%s %s: %lu/%lu\n\n", RESULTADO, ARCHIVO, PRUEBAS_APROBADAS, NUMERO_PRUEBAS);
}

