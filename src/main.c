#include<stdio.h>
#include<stdlib.h>
#include<tablero.h>


#define printf_dec_format(x) _Generic((x), \
                int: "%d",\
                float: "%f",\
                double: "%lf",\
                char: "%c",\
                char*: "%s")


#define hash(x) _Generic((x),\
    char*: hash_string)(x)\


#define printnl(x) printf(printf_dec_format(x), x), printf("\n");

#define HASH_SIZE 383
#define define_map(tipoClave, tipoValor) \
    typedef struct {\
        tipoClave clave;\
        tipoValor valor;\
        }_map_##tipoClave_##tipoValor;\
    \
    typedef struct Map_##tipoClave_##tipoValor{\
        _map_##tipoClave_##tipoValor* data;\
    }Map_##tipoClave_##tipoValor;\
    \
    unsigned hash_string(char* clave) {\
        unsigned hashval;\
        for (hashval = 0; *clave != '\0'; clave++) {\
            hashval = *clave + 31 * hashval;\
        }\
        return hashval % HASH_SIZE;\
    }\
    \
    void __put_##tipoClave_##tipoValor(Map_##tipoClave_##tipoValor* mapa, tipoClave clave, tipoValor valor) {\
        unsigned lugarAColocar = hash(clave);\
        mapa->data[lugarAColocar].clave = clave;\
        mapa->data[lugarAColocar].valor = valor;\
    }\
    \
    void __print_##tipoClave_##tipoValor(Map_##tipoClave_##tipoValor mapa, tipoClave clave) {\
        unsigned lugarAColocar = hash(clave);\
        printnl(mapa.data[lugarAColocar].valor);\
    }\
    \
    void MapCrear_##tipoClave_##tipoValor(Map_##tipoClave_##tipoValor* mapa) {\
        mapa->data = (_map_##tipoClave_##tipoValor*) calloc(HASH_SIZE, sizeof(_map_##tipoClave_##tipoValor));\
    }\
    \
    void MapDestruir_##tipoClave_##tipoValor(Map_##tipoClave_##tipoValor* mapa) {\
        free(mapa->data);\
    }

#define Map(tipoClave, tipoValor) \
    Map_##tipoClave_##tipoValor


#define MapCrear(tipoClave, tipoValor) \
    MapCrear_##tipoClave_##tipoValor

#define MapPut(tipoClave, tipoValor)\
    __put_##tipoClave_##tipoValor

#define MapPrint(tipoClave, tipoValor)\
    __print_##tipoClave_##tipoValor

#define MapDestruir(tipoClave, tipoValor) \
    MapDestruir_##tipoClave_##tipoValor


define_map(char*, double)
int main(void)
{
    Map(char*, double) test;
    MapCrear(char*, double)(&test);

    MapPut(char*, double)(&test, "hola", 34.32748);
    MapPrint(char*, double)(test, "hola");


    MapDestruir(char*, double)(&test);
    return EXIT_SUCCESS;
}