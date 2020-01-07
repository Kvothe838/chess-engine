#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define APROBADO "El test fue aprobado"
#define FALLO "Fallo en el test con la condicion:"
#define RESULTADO "Numero de tests aprobadas en"

size_t NUMERO_PRUEBAS = 0;
size_t PRUEBAS_APROBADAS = 0;
bool EJECUTAR_FINAL = true;

#define FUNCION_FINAL \
void __attribute__  ((destructor)) resultado()\
{\
    if (EJECUTAR_FINAL)\
    {\
            printf("%s %s: %lu/%lu\n\n", RESULTADO, __FILE__, PRUEBAS_APROBADAS, NUMERO_PRUEBAS);\
            EJECUTAR_FINAL = false;\
    }\
}

#define ASSERT(CONDICION)\
{\
    NUMERO_PRUEBAS++;\
    printf("Probando %s: ", __FUNCTION__);\
    if(CONDICION)\
    {\
        printf("%s\n", APROBADO), PRUEBAS_APROBADAS++;\
    }\
    else\
    {\
        printf("%s %s\n", FALLO, #CONDICION);\
    }\
    printf("\n");\
    FUNCION_FINAL\
}

