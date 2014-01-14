/* blancos.c -- contador de espacios en blanco */

#include <stdio.h>
#include "bool.h"

int main (void)
{
    int ch;
    int contador = 0;
    BOOL espacio (char);

    while ((ch = getchar ()) != EOF) {
        if (espacio (ch) == CIERTO) {
            contador++;
        }
    }

    printf ("He contado %d espacios en blanco.\n", contador);

    return 0;
}

BOOL espacio (char c)
{
    if (c == ' ' || c == '\n' || c == '\t') {
        return (CIERTO);
    }
    else {
        return (FALSO);
    }
}
