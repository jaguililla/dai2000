/* salta.c -- usa continue para saltar parte del bucle */
#include <stdio.h>
#define MIN 0.0
#define MAX 100.0
int main (void)
{
    float puntos;
    float total = 0.0;
    int n = 0;
    float min = MAX;
    float max = MIN;

    printf ("Introduzca puntuaciones:\n");

    while (scanf ("%f", &puntos) == 1) {
        if (puntos < MIN || puntos > MAX) {
            printf ("%0.1f es una puntuación no válida.\n", puntos);
            continue;
        }

        printf ("Se acepta %0.1f:\n", puntos);
        min = (puntos < min) ? puntos : min;
        max = (puntos > max) ? puntos : max;
        total += puntos;
        n++;
    }

    if (n > 0) {
        printf ("El promedio de %d puntuaciones es %0.1f.\n", n, total / n);
        printf ("Mínima = %0.1f, máxima = %0.1f\n", min, max);
    }
    else
        printf ("No se han indicado puntuaciones válidas.\n");

    return 0;
}
