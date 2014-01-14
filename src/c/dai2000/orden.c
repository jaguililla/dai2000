/* orden.c -- precedencia en operaciones con punteros */
#include <stdio.h>
int datos[2] = { 100, 300 };
int masdatos[2] = { 100, 300 };
int main (void)
{
    int *p1, *p2, *p3;

    p1 = p2 = datos;
    p3 = masdatos;
    printf ("%d %d %d\n", *p1++, *++p2, (*p3)++);
    printf ("%d %d %d\n", *p1, *p2, *p3);
    return 0;
}
