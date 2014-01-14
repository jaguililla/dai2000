/* secretos.c -- programa informativo totalmente inútil */
#include <stdio.h>
#define DENSIDAD 0.97           /* densidad del hombre en kg por litro */
main ()
{
    float peso, volumen;
    int sitio, letras;
    char nombre[40];

    printf ("¡Hola! ¿Cómo te llamas?\n");
    scanf ("%s", nombre);
    printf ("%s, ¿cuál es tu peso en kg?\n", nombre);
    scanf ("%f", &peso);
    sitio = sizeof nombre;
    letras = strlen (nombre);
    volumen = peso / DENSIDAD;
    printf ("Bien, %s, tu volumen es %2.2f litros.\n", nombre, volumen);
    printf ("Además, tu nombre tiene %d letras,\n", letras);
    printf ("y disponemos de %d bytes para guardarlo.\n", sitio);
}
