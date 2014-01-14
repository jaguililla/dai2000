/* sizeof.c -- aplicaciones del operador sizeof */
#include <stdio.h>
main ()
{
    int n;

    printf ("n tiene %d bytes; todos los enteros tienen %d bytes.\n",
            sizeof n, sizeof (int));
}
