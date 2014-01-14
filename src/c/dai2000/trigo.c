/* trigo.c -- crecimiento exponencial */
#include <stdio.h>
#define CUADRADOS 64            /* cuadros de un tablero de ajedrez   */
#define COSECHA 4E15            /* cosecha mundial de trigo en granos */
main ()
{
    double actual, total;
    int cont = 1;

    printf ("cuadro  granos sumados  granos totales  ");
    printf ("fracción de\n");
    printf ("                                        ");
    printf (" cosecha\n");
    total = actual = 1.0;       /* comenzamos con un grano */
    printf ("%4d %15.2e %16.2e %12.2e\n", cont, actual,
            total, total / COSECHA);

    while (cont < CUADRADOS) {
        cont = cont + 1;
        actual = 2.0 * actual;  /* duplica granos en cada cuadro */
        total = total + actual; /* actualiza total */
        printf ("%4d %15.2e %15.2e %12.2e\n", cont, actual,
                total, total / COSECHA);
    }
}
