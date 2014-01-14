/* filas1.c -- uso de bucles anidados */
#include <stdio.h>
#define FILAS  6
#define CARS 6
main ()
{
    int fila;
    char ch;

    for (fila = 0; fila < FILAS; fila++) {  /* línea 10 */

        for (ch = 'A'; ch < ('A' + CARS); ch++) /* línea 12 */
            printf ("%c", ch);

        printf ("\n");
    }
}
