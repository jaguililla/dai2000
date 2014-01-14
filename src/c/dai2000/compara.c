/* compara.c -- este sí funciona */
#include <stdio.h>
#include <string.h>             /* declara strcmp() */
#define RESP "Blanco"
#define MAX 40
int main (void)
{
    char prueba[MAX];

    puts ("¿De qué color es el caballo blanco de Santiago?");
    gets (prueba);

    while (strcmp (prueba, RESP) != 0) {
        puts ("Ni idea. Prueba otra vez.");
        gets (prueba);
    }

    puts ("¡Correcto!");
    return 0;
}
