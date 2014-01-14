/* elogio2.c */
#include <stdio.h>
#define ELOGIO "¡Por Júpiter, qué gran nombre!"
main ()
{
    char nombre[50];

    printf ("¿Cómo te llamas?\n");
    scanf ("%s", nombre);
    printf ("Hola, %s. %s\n", nombre, ELOGIO);
    printf ("Tu nombre de %d letras ocupa %d celdas de memoria.\n",
            strlen (nombre), sizeof nombre);
    printf ("La frase de elogio tiene %d letras ", strlen (ELOGIO));
    printf ("y ocupa %d celdas de memoria.\n", sizeof ELOGIO);
}
