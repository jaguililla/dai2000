/* diagramas.c -- produce un patrón simétrico de caracteres */
#include <stdio.h>
int main (void)
{
    int ch;                     /* lee carácter */
    int indice;
    int numch;

    while ((ch = getchar ()) != '\n') {
        numch = ch % 26;        /* genera un número entre 0 y 25 */
        indice = 0;

        while (indice++ < (30 - numch))
            putchar (' ');      /* espacios para centrar */

        indice = 0;

        while (indice++ < (2 * numch + 1))
            putchar (ch);       /* imprime ch varias veces */

        putchar ('\n');
    }

    return 0;
}
