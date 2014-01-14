/* Ciudades temperaturas mínimas, máximas y medias */
#include <stdio.h>
#include <stdlib.h>

#define N 3
void listar (float t[][4], int nc);
void ordenar (float t[][4], int nc, int opcion);
void cargar (float t[][4], int nc);

void main (void)
{
    float t[N][4];
    int c, op;

    clrscr ();
    cargar (t, N);
    listar (t, N);

    do {
        printf ("0.-fin 1.-minima  2.-máxima 3.-media  4.-dif opcion: ");
        scanf ("%d", &op);
        ordenar (t, N, op - 1);
        listar (t, N);
    }
    while (op);

    getch ();
}

void cargar (float t[][4], int nc)
{
    int c, op;

    for (c = 0; c < nc; c++) {
        for (op = 0; op < 2; op++) {
            if (op == 0)
                printf ("mínima: ");
            else
                printf ("máxima: ");

            scanf ("%f", &t[c][op]);
        }

        t[c][2] = (t[c][0] + t[c][1]) / 2;  /* Se calcula la media */
        t[c][3] = t[c][1] - t[c][0];    /* Calcula la oscilación */
    }
}                               /* cargar */

void listar (float t[][4], int nc)
{
    int c, op;

    printf ("mínima máxima media oscilación\n");

    for (c = 0; c < nc; c++) {
        for (op = 0; op < 4; op++)
            printf ("%6.1f", t[c][op]);

        printf ("\n");
    }
}                               /* listar */

void ordenar (float t[][4], int nc, int op)
{
    int i, j, k;
    float aux;

    for (i = 0; i < nc - 1; i++)
        for (j = i + 1; j < nc; j++)
            if (t[i][op] > t[j][op])
                for (k = 0; k < 4; k++) {   /* se intercambian todas las temperaturas */
                    aux = t[i][k];
                    t[i][k] = t[j][k];
                    t[j][k] = aux;
                }
}                               /* ordenar */
