/* maluso.c -- uso incorrecto de una función */
#include <stdio.h>
int imax ();                    /* declaración al viejo estilo */
int main (void)
{
    printf ("El máximo entre %d y %d es %d.\n", 3, 5, imax (3));
    printf ("El máximo entre %d y %d es %d.\n", 3, 5, imax (3.0, 5.0));
    return 0;
}

int imax (n, m)
     int n, m;
{
    int max;

    if (n > m)
        max = n;
    else
        max = m;

    return max;
}
