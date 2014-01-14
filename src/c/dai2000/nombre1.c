/* nombre1.c -- lee un nombre */
#include <stdio.h>
#define MAX 80
int main (void)
{
    char nombre[81];            /* reserva espacio */

    printf ("Hola, ¿cómo te llamas?\n");
    gets (nombre);              /* introduce entrada en tira "nombre" */
    printf ("Bonito nombre, %s.\n", nombre);
    return 0;
}
