/* no_va.c -- ¿funciona esto? */
#include <stdio.h>
#define RESP "Blanco"
int main (void)
{
    char prueba[40];

    puts ("¿De qué color es el caballo blanco de Santiago?");
    gets (prueba);

    while (prueba != RESP) {
        puts ("Ni idea. Prueba otra vez.");
        gets (prueba);
    }

    puts ("¡Correcto!");
    return 0;
}
