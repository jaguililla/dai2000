/* sacacar2.c -- imprime caracteres en filas y columnas */
#include <stdio.h>
void pantalla (char c, int lineas, int ancho);
int main (void)
{
    int ch;                     /* carácter a imprimir */
    int filas, cols;            /* número de filas y columnas */

    printf ("Introduzca un carácter y dos enteros:\n");

    while ((ch = getchar ()) != EOF) {
        if (ch != '\n' && ch != ' ' && ch != '\t') {
            if (scanf ("%d %d", &filas, &cols) != 2)
                break;

            pantalla (ch, filas, cols);

            printf ("Introduzca otro carácter y dos enteros;\n");

            printf ("Simule eof para salir.\n");
        }
    }

    return 0;
}

void pantalla (char c, int lineas, int ancho)
{
    int fila, col;

    for (fila = 1; fila <= lineas; fila++) {
        for (col = 1; col <= ancho; col++)
            putchar (c);

        putchar ('\n');         /* fin de línea y comienzo de una nueva */
    }
}
