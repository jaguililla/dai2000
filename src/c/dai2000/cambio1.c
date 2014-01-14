/* cambio1.c -- primer intento de una función de intercambio */
#include <stdio.h>
void intercambia (int u, int v);    /* declara función */
int main (void)
{
    int x = 5, y = 10;

    printf ("En principio x = %d e y = %d.\n", x, y);
    intercambia (x, y);
    printf ("Ahora x = %d e y = %d.\n", x, y);
    return 0;
}

void intercambia (int u, int v)
{                               /* define función  */
    int temp;

    temp = u;
    u = v;
    v = temp;
}
