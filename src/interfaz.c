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
        numeroDeMovimientos++;
        jugador = turnoDeLosBlancos ? 'B' : 'N';
        
        printf("%s%s\n", TURNO, turnoDeLosBlancos ? "Blancos" : "Negros");
        printf("%s", ELEGIR);
        fgets(movimiento, 4, stdin);

        while ((c = getchar()) != '\n' && c != EOF);

        bool movimientoInexistente;
        bool movimientoCorrecto = TableroMoverPieza(&(juego->tablero), movimiento, jugador, &movimientoInexistente);
        
        if(movimientoCorrecto)
        {
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
        }
        else
        {
            printf("\n%s\n\n", movimientoInexistente ? ERROR_MOVIMIENTO_INEXISTENTE : ERROR_MOVIMIENTO_DOBLE);
        }        
    }

    TableroDestruir(&(juego->tablero));
}