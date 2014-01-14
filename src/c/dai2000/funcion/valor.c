/* valor.c - Paso de parámetros por valor */
#include <stdio.h>

void intercambio (int, int);    /* prototipo de la función */

void main (void)
{
    int a = 20, b = 30;

    clrscr ();
    printf ("Valores antes de la llamada: ");
    printf ("a es %d y b es %d\n\n\n\n", a, b);
    // llamada a la función 'intercambio'
    intercambio (a, b);         /* a y b son pasados por valor */
    printf ("Valores después de la llamada: ");
    printf ("a es %d y b es %d\n", a, b);
    getch ();
}

void intercambio (int x, int y)
{
// En esta declaración de parámetros, el paso es por valor
    int z;

    printf ("\n\n\n Antes de la ejecución de la función");
    printf (" x es %d e y es %d\n", x, y);
    z = x;
    x = y;
    y = z;
    printf (" Después de su ejecución y antes de volver a 'main'");
    printf (" x es %d e y es %d\n\n\n\n", x, y);
}
