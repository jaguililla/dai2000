/* elogio1.c -- combina tiras de caracteres */
#include <stdio.h>
#define ELOGIO "¡Por Júpiter, qué gran nombre!"
main ()
{
    char nombre[50];

    printf ("¿Cómo te llamas?\n");
    scanf ("%s", nombre);
    printf ("Hola, %s. %s\n", nombre, ELOGIO);
}
