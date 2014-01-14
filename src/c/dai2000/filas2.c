/* filas2.c -- bucles anidados interdependientes */
#include <stdio.h>
#define FILAS  6
#define CARS 6
main ()
{
    int fila;
    char ch;

    for (fila = 0; fila < FILAS; fila++) {
        for (ch = ('A' + fila); ch < ('A' + CARS); ch++)
            printf ("%c", ch);

        printf ("\n");
    }
}
