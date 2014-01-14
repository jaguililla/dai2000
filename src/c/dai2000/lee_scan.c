/* lee_scan.c -- uso de scanf() */
#include <stdio.h>
int main (void)
{
    static char nombre1[11], nombre2[11];
    int cont;

    printf ("Introduzca dos nombres.\n");
    cont = scanf ("%5s %10s", nombre1, nombre2);
    printf ("He leído los %d nombres %s y %s.\n", cont, nombre1, nombre2);
    return 0;
}
