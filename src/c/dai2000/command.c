/* command.c -- genera una tira de órdenes */
#include <stdio.h>
#include <stdlib.h>             /* ANSI C: declara la función system() */
#define MAX 20
int main (void)
{
    char origen[MAX];
    char destino[MAX];
    char orden[2 * MAX + 5];

    puts ("Introduzca nombre del fichero a copiar:");
    gets (origen);
    puts ("Introduzca nombre elegido como destino:");
    gets (destino);
    sprintf (orden, "copy %s %s", origen, destino);
    printf ("Ejecuto la siguiente orden: %s\n", orden);
    system (orden);
    return 0;
}
