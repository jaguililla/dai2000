/* cambio2.c -- arreglos en cambio1.c */
#include <stdio.h>
void intercambia (int u, int v);
int main (void)
{
    int x = 5, y = 10;

    printf ("En principio x = %d e y = %d.\n", x, y);
    intercambia (x, y);
    printf ("Ahora x = %d e y = %d.\n", x, y);
    return 0;
}

void intercambia (int u, int v)
{
    int temp;

    printf ("En principio u = %d y v = %d.\n", u, v);
    temp = u;
    u = v;
    v = temp;
    printf ("Ahora u = %d y v = %d.\n", u, v);
}
