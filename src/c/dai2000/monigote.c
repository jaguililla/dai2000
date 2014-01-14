/* monigote.c -- dibuja figuras rellenas de caracteres */
#include <stdio.h>
#define CIERTO 1
#define FALSO 0
#define LONGMAX 80
int maloslimites (int princ, int final, int limite);
void pantalla (char c, int primera, int ultima);
int main (void)
{
    int ch;                     /* carácter a imprimir                    */
    int princ, final;           /* puntos de comienzo y final             */
    int maloslimites ();        /* devuelve CIERTO en límites incorrectos */

    while ((ch = getchar ()) != EOF) {  /* lee un carácter */

        if (ch == '\n' || ch == ' ' || ch == '\t')
            continue;           /* salta caracteres nueva línea y espacio */

        if (scanf ("%d %d", &princ, &final) != 2)   /* lee límites */
            break;

        if (maloslimites (princ, final, LONGMAX) == CIERTO)
            printf ("límites no válidos.\n");
        else
            pantalla (ch, princ, final);
    }

    return 0;
}

int maloslimites (int princ, int final, int limite)
{
    if (princ > final || princ < 1 || final > limite)
        return CIERTO;
    else
        return FALSO;
}

void pantalla (char c, int primera, int ultima)
{
    int columna;

    for (columna = 1; columna < primera; columna++)
        putchar (' ');          /* imprime blancos hasta comienzo */

    for (columna = primera; columna <= ultima; columna++)
        putchar (c);            /* imprime caracteres hasta final */

    putchar ('\n');             /* termina línea y comienza otra  */
}
