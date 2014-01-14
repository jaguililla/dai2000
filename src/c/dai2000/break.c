/* break.c -- usa break para salir del bucle */
#include <stdio.h>
int main (void)
{
    float largo, ancho;

    printf ("Longitud del rectángulo:\n");

    while (scanf ("%f", &largo) == 1) {
        printf ("Longitud = %0.2f:\n", largo);
        printf ("Anchura del rectángulo\n");

        if (scanf ("%f", &ancho) != 1)
            break;

        printf ("Anchura = %0.2f:\n", ancho);

        printf ("Area = %0.2f:\n", largo * ancho);

        printf ("Longitud del rectángulo:\n");
    }

    return 0;
}
