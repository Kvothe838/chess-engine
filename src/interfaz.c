#include <stdio.h>
#include <stdbool.h>
#include <interfaz.h>
#include <tablero.h>
#include <tipo_tablero.h>
#include <stdlib.h>

#define TURNO "Turno de los "
#define ELEGIR "Movimiento: "
#define CONTINUAR "Desea continuar la partida? (Y/N): "

void Empezar(Juego* juego)
{
    TableroInicializar(&(juego->tablero));
    size_t numeroDeMovimientos = 0;
    char Jugador = 'B';
    bool JuegoTerminado = false, turnoDeLosBlancos = true;
    char continuarLaPartida[2];
    char movimiento[4];
    char c;
    TableroImprimir(juego->tablero);

    while (!JuegoTerminado)
    {
        numeroDeMovimientos++;
        Jugador = (turnoDeLosBlancos)? 'B':'N';
        
        printf("%s%s\n", TURNO, (turnoDeLosBlancos)? "Blancos":"Negros");
        printf("%s", ELEGIR);
        fgets(movimiento, 4, stdin);
        while ((c = getchar()) != '\n' && c != EOF);

        TableroMoverPieza(&(juego->tablero), movimiento, Jugador);
        TableroImprimir(juego->tablero);

        if (numeroDeMovimientos % 2 == 0)
        {
            printf("%s", CONTINUAR);
            fgets(continuarLaPartida, 2, stdin);
            while ((c = getchar()) != '\n' && c != EOF);
            if (continuarLaPartida[0] == 'N' || continuarLaPartida[0] == 'n')
            {
                JuegoTerminado = true;
            }
        }
        
        turnoDeLosBlancos = !turnoDeLosBlancos;
    }

    TableroDestruir(&(juego->tablero));
}