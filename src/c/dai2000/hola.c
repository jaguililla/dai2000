/* hola.c -- convierte argumento de línea de órdenes en número */
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
    int i, veces;

    if (argc < 2 || (veces = atoi (argv[1])) < 1)
        printf ("Uso: %s número positivo\n", argv[0]);
    else
        for (i = 0; i < veces; i++)
            puts ("¡Hola, preciosa!");

    return 0;
}
