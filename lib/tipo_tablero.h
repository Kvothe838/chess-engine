#ifndef _TIPO_TABLERO_H
    #define _TIPO_TABLERO_H

    char __tablero_inicial[FILAS][COLUMNAS][3] = {\
            {TORRE_BLANCO, CABALLO_BLANCO, ALFIL_BLANCO, REINA_BLANCO, REY_BLANCO, ALFIL_BLANCO, CABALLO_BLANCO, TORRE_BLANCO},\
            {PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO, PEON_BLANCO},\
            {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},\
            {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},\
            {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},\
            {NADA, NADA, NADA, NADA, NADA, NADA, NADA, NADA},\
            {PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO, PEON_NEGRO},\
            {TORRE_NEGRO, CABALLO_NEGRO, ALFIL_NEGRO, REINA_NEGRO, REY_NEGRO , ALFIL_NEGRO, CABALLO_NEGRO, TORRE_NEGRO}\
    };

    #if defined(TABLERO_PERSONALIZADO)
        #define TableroInicializar(args) __TableroInicializar(tableroPersonalizado, args)

    #else
        #define TableroInicializar(args) __TableroInicializar(__tablero_inicial, args)

    #endif
#endif