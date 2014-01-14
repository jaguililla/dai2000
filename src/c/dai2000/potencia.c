/* potencia.c -- eleva números a potencias enteras */
#include <stdio.h>
double potencia (double, int);  /* prototipo ANSI */

main ()
{
    double x, xpot;
    int n;

    printf ("Introduzca un número y un exponente entero positivo");
    printf (" al cual\nse elevará el número. Pulse s");
    printf (" para salir.\n");

    while (scanf ("%lf%d", &x, &n) == 2) {
        xpot = potencia (x, n); /* llamada a la función     */
        printf ("%.3e a la  potencia %d es %.3e\n", x, n, xpot);
    }
}

double potencia (double a, int b)
{                               /* definición de la función */
    double pot = 1;
    int i;

    for (i = 1; i <= b; i++)
        pot *= a;

    return pot;                 /* devuelve el valor de pot */
}
