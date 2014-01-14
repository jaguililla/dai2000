/* imprime.c -- ejemplo de especificadores de conversión */
#include <stdio.h>
#define PI 3.141593
main ()
{
    int numero = 5;
    float ron = 13.5;
    int coste = 3100;

    printf ("Las %d mujeres se bebieron %f vasos de ron.\n", numero, ron);
    printf ("El valor de pi es %f.\n", PI);
    printf ("Fazer non quiso que tal malandrín fablara.\n");
    printf ("%c%d\n", '$', 2 * coste);
}
