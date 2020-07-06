#include <stdio.h>
#include <stdbool.h>
#include <interfaz.h>
#include <string.h>
#include <tablero.h>
#include <ataques.h>
#include <movimiento.h>
#include <tipo_juego.h>
#include <stdlib.h>

#define TURNO "Turno de los "
#define ELEGIR "Movimiento: "
#define CONTINUAR "Desea continuar la partida? (Y/N): "
#define ERROR_MOVIMIENTO_INEXISTENTE "El movimiento que intenta hacer no es posible. Reintente."
#define ERROR_MOVIMIENTO_DOBLE "Hay dos piezas que pueden realizar el movimiento deseado.\nPor favor, especifique con la notación específica."
#define ERROR_ATAQUE_ALIADO "Esta intentando atacar una pieza que le pertenece. Reintente."

void Empezar(Juego* juego)
{
    INICIALIZAR_JUEGO(juego);
    
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

        status_t statusMovimiento = CalcularMovimiento(juego, movimiento, jugador);
        
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
    JuegoDestruir(juego);
}