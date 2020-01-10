#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define APROBADO "El test fue aprobado"
#define FALLO "Fallo en el test con la condicion:"
#define RESULTADO "Numero de tests aprobadas en"

size_t NUMERO_PRUEBAS = 0;
size_t PRUEBAS_APROBADAS = 0;

#define ASSERT(CONDICION)\
{\
    NUMERO_PRUEBAS++;\
    printf("Probando %s: ", __func__);\
    if(CONDICION)\
    {\
        printf("%s\n", APROBADO), PRUEBAS_APROBADAS++;\
    }\
    else\
    {\
        printf("%s %s\n", FALLO, #CONDICION);\
    }\
    printf("\n");\
}

void __attribute__((destructor)) resultado()
{
    printf("%s %s: %lu/%lu\n\n", RESULTADO, ARCHIVO, PRUEBAS_APROBADAS, NUMERO_PRUEBAS);
}

