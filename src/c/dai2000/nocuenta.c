/* nocuenta.c -- número erróneo de argumentos */
#include <stdio.h>
main ()
{
    int f = 4;
    int g = 5;

    printf ("%d\n", f, g);      /* demasiados argumentos */
    printf ("%d %d\n", f);      /* demasiado pocos ahora */
}
