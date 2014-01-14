/* zenon.c -- suma de una serie */

#include <stdio.h>
#define LIMITE 15

main ()
{
    int cont;
    float suma, x;

    for (suma = 0.0, x = 1.0, cont = 1; cont <= LIMITE; cont++, x *= 2.0) {
        suma += 1.0 / x;
        printf ("suma = %f en la etapa %d.\n", suma, cont);
    }
}
