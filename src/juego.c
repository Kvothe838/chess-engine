#include <string.h>
#include <pieza.h>
#include <tablero.h>
#include <juego.h>

void JuegoInicializar(char tableroProvisorio[FILAS][COLUMNAS][3], Juego* juego)
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

void JuegoDestruir(Juego* juego)
{
    PiezaDestruirMultiples(&(juego->piezasBlancas), juego->cantidadDePiezasBlancas);
    PiezaDestruirMultiples(&(juego->piezasNegras), juego->cantidadDePiezasNegras);

    TableroDestruir(&(juego->tablero));
}