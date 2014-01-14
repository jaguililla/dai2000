/* mac_arg.c -- macros con argumentos */
#include <stdio.h>
#define CUADRADO(x) x*x
#define PR(x) printf("El resultado es %d.\n", x)
int main (void)
{
    int x = 4;
    int z;

    z = CUADRADO (x);
    PR (z);
    z = CUADRADO (2);
    PR (z);
    PR (CUADRADO (x + 2));
    PR (100 / CUADRADO (2));
    PR (CUADRADO (++x));
    return 0;
}
