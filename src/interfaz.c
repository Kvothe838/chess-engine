#include <stdio.h>
#include <stdbool.h>
#include <interfaz.h>
#include <tablero.h>
#include <tipo_tablero.h>
#include <stdlib.h>

#define TURNO "Turno de los "
#define ELEGIR "Movimiento: "
#define CONTINUAR "Desea continuar la partida? (Y/N): "
#define ERROR_MOVIMIENTO_INEXISTENTE "El movimiento que intenta hacer no es posible. Reintente."
#define ERROR_MOVIMIENTO_DOBLE "Hay dos piezas que pueden realizar el movimiento deseado.\nPor favor, especifique con la notación específica."

void Empezar(Juego* juego)
{
    TableroInicializar(&(juego->tablero));
    
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

        status_t statusMovimiento = TableroMoverPieza(&(juego->tablero), movimiento, jugador);
        
        switch(statusMovimiento)
        {
            case ST_OK:
                numeroDeMovimientos++;
                TableroImprimir(juego->tablero);

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
        }   
    }

    TableroDestruir(&(juego->tablero));
}
