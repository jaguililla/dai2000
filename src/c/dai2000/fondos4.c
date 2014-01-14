/* fondos4.c -- paso de un array de estructuras a una función */
#include <stdio.h>
#define N 2

struct fondos {
    char *banco;
    float ccorri;
    char *ahorro;
    float cahorro;
} garcias[N] = {
    {
    "Banco Pacífico", 102343.25, "Banco de Poniente", 423987.21}, {
    "Banca La Honradez", 97656.50, "Banco Cantonal", 176013.04}
};

float suma (const struct fondos *, int);
int main (void)
{
    float total;

    printf ("Los García tienen un total de %.2f pts.\n", suma (garcias, N));
    return 0;
}

float suma (const struct fondos *dinero, int n)
{
    float total;
    int i;

    for (i = 0, total = 0; i < n; i++, dinero++)
        total += dinero->ccorri + dinero->cahorro;

    return (total);
}
