/* mete_pal.c -- usa fprintf(), fscanf() y rewind() */
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int main (void)
{
    FILE *fi;
    char palabras[MAX];
    int aux;

    if ((fi = fopen ("palabras", "a+")) == NULL) {
        fprintf (stdin, "No puedo abrir el fichero \"palabras\".\n");
        exit (1);
    }

    puts ("Introduzca texto a añadir al fichero; pulse la tecla");
    puts ("Intro al comienzo de una línea para terminar.");

    while (gets (palabras) != NULL && palabras[0] != '\0')
        fprintf (fi, "%s ", palabras);

    puts ("Contenido del fichero:");

    rewind (fi);                /* retrocede al comienzo del fichero */

    while (fscanf (fi, "%s", palabras) == 1)
        puts (palabras);

    if ((aux = fclose (fi)) != 0)
        fprintf (stderr, "Error al cerrar fichero\n");

    return 0;
}
