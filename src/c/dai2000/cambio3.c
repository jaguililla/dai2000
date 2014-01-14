/* cambio3.c -- intercambio realizado con punteros */
#include <stdio.h>
void intercambia (int *u, int *v);
int main (void)
{
    int x = 5, y = 10;

    printf ("En principio x = %d e y = %d.\n", x, y);
    intercambia (&x, &y);       /* envía las direcciones a la función */
    printf ("Ahora x = %d e y = %d.\n", x, y);
    return 0;
}

void intercambia (int *u, int *v)
{
    int temp;

    temp = *u;                  /* temp toma el valor al que apunta u */
    *u = *v;
    *v = temp;
}
