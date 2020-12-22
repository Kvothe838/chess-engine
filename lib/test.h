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

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define PRINT_ANALISIS()\
{\
    if(FUNCION_PASA)\
    {\
        printf(ANSI_COLOR_GREEN "%s\n" ANSI_COLOR_RESET, APROBADO);\
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
        printf(ANSI_COLOR_RED "%s%d%s\"%s\"\n" ANSI_COLOR_RESET, FALLO1, __LINE__, FALLO2, #CONDICION);\
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