 /* CABARECT.C solución recursiva salto caballo. tODAS LAS solucionES */

#include <stdio.h>
#define  MaxNumCasillas 8
#define true 1
#define false 0

int IncX[9], IncY[9];           /* Incrementos de coordenadas indexamos de 1 a 8 */
int Tablero[MaxNumCasillas + 1][MaxNumCasillas + 1], solu = 0;

void ensayar (int NumMov, int x, int y, int nl, int *Fin)
{
    int salto, NuevoX, NuevoY, Acierto, Fila, Columna;

    for (salto = 1; salto <= 8; salto++) {
        *Fin = false;           //Acierto=false;
        NuevoX = x + IncX[salto];
        NuevoY = y + IncY[salto];
        /* si casilla dentro del tablero */
        if ((1 <= NuevoX) && (NuevoX <= nl))
            if ((1 <= NuevoY) && (NuevoY <= nl))
                /* si tablero desocupado */
                if (Tablero[NuevoX][NuevoY] == 0) {
                    Tablero[NuevoX][NuevoY] = NumMov;
                    if (NumMov < nl * nl) {
                        ensayar (NumMov + 1, NuevoX, NuevoY, nl,
                                 Fin /*&Acierto */ );
                        if ( /*!Acierto */ !*Fin)
                            Tablero[NuevoX][NuevoY] = 0;
                    }
                    else {
                        solu++; /* mostrar solución */
                        printf ("\t\t\tSolución %d\n", solu);
                        for (Columna = nl; Columna >= 1; Columna--) {
                            for (Fila = 1; Fila <= nl; Fila++)
                                printf ("%5d", Tablero[Columna][Fila]);
                            printf ("\n");
                        }
                        getch ();
                        Tablero[NuevoX][NuevoY] = 0;    //Acierto=false;
                    }
                }               //casilla desocupada
    }                           //for
}                               //ensayar

void main (void)
{
    int x1, y1, NumLineas, Fila, Columna, Exito;

    clrscr ();
    printf ("filas: ");
    scanf ("%d%*c", &NumLineas);
    /* Incrementos coordenadas movimientos según ejes cartesianos */
    IncX[1] = 2;
    IncY[1] = 1;
    IncX[2] = 1;
    IncY[2] = 2;
    IncX[3] = -1;
    IncY[3] = 2;
    IncX[4] = -2;
    IncY[4] = 1;
    IncX[5] = -2;
    IncY[5] = -1;
    IncX[6] = -1;
    IncY[6] = -2;
    IncX[7] = 1;
    IncY[7] = -2;
    IncX[8] = 2;
    IncY[8] = -1;
    do {
        for (Fila = 1; Fila <= NumLineas; Fila++)
            for (Columna = 1; Columna <= NumLineas; Columna++)
                Tablero[Fila][Columna] = 0;
        printf ("casilla inicial (0-fin): ");
        scanf ("%d %d%*c", &x1, &y1);
        if (x1 && y1) {
            Tablero[x1][y1] = 1;
            ensayar (2, x1, y1, NumLineas, &Exito);
            printf ("Soluciones %d\n", solu);
            getch ();
        }
    } while (x1 && y1);
    getch ();
}
