/* salta2.c -- salta los dos primeros enteros de la entrada */
#include <stdio.h>
main ()
{
    int n;

    printf ("Introduzca tres enteros:\n");
    scanf ("%*d %*d %d", &n);
    printf ("El último entero leído es %d\n", n);
}
