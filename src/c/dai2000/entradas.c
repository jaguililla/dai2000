/* entradas.c -- cuándo se debe usar & */
#include <stdio.h>
main ()
{
    int edad;                   /* variable */
    float sueldo;               /* variable */
    char cachorro[30];          /* tira de caracteres */

    printf ("Confiese su edad, sueldo y mascota favorita.\n");
    scanf ("%d %f", &edad, &sueldo);    /* use & aquí */
    scanf ("%s", cachorro);     /* en array de char no se usa & */
    printf ("%d %.0f * %s\n ", edad, sueldo, cachorro);
}
