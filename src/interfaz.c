#include <stdio.h>
#include <stdbool.h>
#include <interfaz.h>
#include <string.h>
#include <tablero.h>
#include <ataques.h>
#include <movimiento.h>
#include <tipo_tablero.h>
#include <stdlib.h>

#define TURNO "Turno de los "
#define ELEGIR "Movimiento: "
#define CONTINUAR "Desea continuar la partida? (Y/N): "
#define ERROR_MOVIMIENTO_INEXISTENTE "El movimiento que intenta hacer no es posible. Reintente."
#define ERROR_MOVIMIENTO_DOBLE "Hay dos piezas que pueden realizar el movimiento deseado.\nPor favor, especifique con la notación específica."
#define ERROR_ATAQUE_ALIADO "Esta intentando atacar una pieza que le pertenece. Reintente."

void Empezar(Juego* juego)
{
    TableroInicializar(juego);
    
    size_t numeroDeMovimientos = 0;
    char jugador = 'B';
    bool juegoTerminado = false, turnoDeLosBlancos = true;
    char continuarLaPartida[2];
    char movimiento[4];
    char c;

    TableroImprimir(juego->tablero);

    while (!juegoTerminado)
    {
        jugador = turnoDeLosBlancos ? 'B' : 'N';
        
        printf("%s%s\n", TURNO, turnoDeLosBlancos ? "Blancos" : "Negros");
        printf("%s", ELEGIR);
        fgets(movimiento, 4, stdin);

        while ((c = getchar()) != '\n' && c != EOF);

        status_t statusMovimiento = CalcularMovimiento(juego, movimiento, jugador);/*TableroMoverPieza(&(juego->tablero), movimiento, jugador);*/
        
        switch(statusMovimiento)
        {
            case ST_OK:
                numeroDeMovimientos++;

                mostrarPiezasEliminadas(zonaPiezasEliminadasPorLasNegras);
                TableroImprimir(juego->tablero);
                mostrarPiezasEliminadas(zonaPiezasEliminadasPorLasBlancas);

                if (numeroDeMovimientos % 2 == 0)
                {
                    printf("%s", CONTINUAR);
                    fgets(continuarLaPartida, 2, stdin);

                    while ((c = getchar()) != '\n' && c != EOF);

                    if (continuarLaPartida[0] == 'N' || continuarLaPartida[0] == 'n')
                    {
                        juegoTerminado = true;
                    }
                }
            
                turnoDeLosBlancos = !turnoDeLosBlancos;

                break;
            case ST_ERR_MOV_INEXISTENTE:
                printf("\n%s\n\n", ERROR_MOVIMIENTO_INEXISTENTE);

                break;
            case ST_ERR_MOV_INCORRECTO:
                printf("\n%s\n\n", ERROR_MOVIMIENTO_DOBLE);

                break;
            case ST_ERR_ATAQ_ALIADO:
                printf("\n%s\n\n", ERROR_ATAQUE_ALIADO);

                break;
        }   
    }
}

void Inicializar(char tableroProvisorio[FILAS][COLUMNAS][3], Juego* juego)
{
    Pieza *pieza;
    int coordenada[2];
    juego->tablero = (Tablero) malloc(FILAS * sizeof(Posicion*));
    juego->cantidadDePiezasBlancas = 0;
    juego->cantidadDePiezasNegras = 0;
    juego->piezasBlancas = NULL;
    juego->piezasNegras = NULL;

    for (int y = 0; y < FILAS; y++)
    {
        coordenada[0] = y;
        (juego->tablero)[y] = (Posicion*)malloc(COLUMNAS * sizeof(Posicion));

        for (int x = 0; x < COLUMNAS; x++)
        {
            coordenada[1] = x;

            PosicionInicializar(&((juego->tablero)[y][x]), coordenada);
            
            if (strcmp(tableroProvisorio[y][x], NADA) != 0)
            {
                pieza = (Pieza*)malloc(sizeof(Pieza));

                PiezaCrear(pieza, tableroProvisorio[y][x][0], tableroProvisorio[y][x][1] == 'B');
                TableroColocarPieza(&(juego->tablero)[y][x], pieza);

                if (pieza->esBlanca)
                {
                    juego->piezasBlancas = (Pieza**)realloc(juego->piezasBlancas,(juego->cantidadDePiezasBlancas + 1) * sizeof(Pieza*));
                    juego->piezasBlancas[juego->cantidadDePiezasBlancas] = pieza;
                    juego->cantidadDePiezasBlancas++;
                }
                else
                {
                    juego->piezasNegras = (Pieza**)realloc(juego->piezasNegras,(juego->cantidadDePiezasNegras + 1) * sizeof(Pieza*));
                    juego->piezasNegras[juego->cantidadDePiezasNegras] = pieza;
                    juego->cantidadDePiezasNegras++;
                }
            }            
        }
    }
}


void Terminar(Juego* juego)
{
    PiezaDestruirMultiples(&(juego->piezasBlancas), juego->cantidadDePiezasBlancas);
    PiezaDestruirMultiples(&(juego->piezasNegras), juego->cantidadDePiezasNegras);

    TableroDestruir(&(juego->tablero));
}
