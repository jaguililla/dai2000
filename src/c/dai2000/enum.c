/* enum.c -- valores enumerados */

#include <stdio.h>
#include "bool.h"

#define LONG 30

char *colores[] =
    { "rojo", "naranja", "amarillo", "verde", "azul", "violeta" };
enum espectro { rojo, naranja, amarillo, verde, azul, violeta };

int main (void)
{
    char elige[LONG];
    enum espectro color;
    BOOL hecho = FALSO;

    puts ("Introduzca un color:");
    gets (elige);

    for (color = rojo; color <= violeta; color++) {
        if (strcmp (elige, colores[color]) == 0) {
            hecho = CIERTO;
            break;
        }
    }

    if (hecho == CIERTO) {
        printf ("%s está en mi lista de colores.\n", elige);
    }
    else {
        printf ("No conozco el color %s.\n", elige);
    }

    return 0;
}
