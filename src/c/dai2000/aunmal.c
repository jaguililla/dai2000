/* aunmal.c -- programa con los errores sintácticos corregidos */
#include <stdio.h>
main ()
{
    int n, n2, n3;

    /* este programa tiene un error semántico */

    n = 5;
    n2 = n * n;
    n3 = n2 * n2;
    printf ("n = %d, n al cuadrado = %d, n al cubo = %d\n", n, n2, n3);
}
