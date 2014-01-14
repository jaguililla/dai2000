/* flotante.c -- combinaciones de punto flotante */
#include <stdio.h>
#define RENTA 1234.56
main ()
{
    printf ("/%f/\n", RENTA);
    printf ("/%e/\n", RENTA);
    printf ("/%4.2f/\n", RENTA);
    printf ("/%3.1f/\n", RENTA);
    printf ("/%10.3f/\n", RENTA);
    printf ("/%10.3e/\n", RENTA);
    printf ("/%+4.2f/\n", RENTA);
    printf ("/%010.2f/\n", RENTA);
}
