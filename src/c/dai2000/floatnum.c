/* floatnum.c -- presenta valores float con dos formatos */
#include <stdio.h>
main ()
{
    float valor = 32000.0;

    printf ("%f puede representarse como %e\n", valor, valor);
}
