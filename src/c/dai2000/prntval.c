/* prntval.c -- valor de retorno de printf() */
#include <stdio.h>
main ()
{
    int n = 100;
    int rv;

    rv = printf ("El punto de ebullición del agua es %d grados.\n", n);
    printf ("La función printf() ha impreso %d caracteres.\n", rv);
}
