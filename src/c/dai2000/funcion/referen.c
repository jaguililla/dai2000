/* referen.c - Paso de parámetros por referencia */
#include <stdio.h>
void intercambio (int *, int *);    /* prototipo de la función */

void main (void)
{
    int a = 20, b = 30;

    clrscr ();
    printf ("Antes de la llamada a es %d y b es %d\n", a, b);
    intercambio (&a, &b);       /* a y b son pasados por referencia */
    printf ("Después de la llamada a es %d y b es %d\n", a, b);
    getch ();
}

void intercambio (int *x, int *y)
{
    int z = *x;                 /* z = contenido de la dirección x */

    *x = *y;                    /* contenido de x = contenido de y */
    *y = z;                     /* contenido de y = z */
}
