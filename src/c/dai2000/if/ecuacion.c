/*
 * ecuacion.c - Resolución de ecuaciones de 2_ grado.
 */

#include <stdio.h>
#include <math.h> /* necesaria para 'sqrt' */

int main (void) {
    double a, b, c, d, x1, x2;

    /* Entrada de datos */
    printf ("Introducir coeficientes a b c: ");
    scanf ("%lf %lf %lf", &a, &b, &c);  /* lectura en doble precisión 'lf' */

    /* Comprobar si las raíces son reales */
    d = b * b - 4 * a * c;

    if (d < 0) {
        printf ("Las raíces son complejas\n");
    }
    else {
        printf ("Las raíces reales son:\n");
        /* Calculo de las soluciones */
        d = sqrt (d);
        x1 = (-b + d) / (2 * a);
        x2 = (-b - d) / (2 * a);
        /* Escribir resultados */
        printf ("x1 = %g\nx2 = %g\n", x1, x2);
    }
    getch ();
}
