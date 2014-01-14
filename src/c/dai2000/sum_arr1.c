/* sum_arr1.c -- suma los elementos de un array */
#include <stdio.h>
#define TAM 10
long suma (int ar[], int n);
int main (void)
{
    static int bolas[TAM] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
    long resp;

    resp = suma (bolas, TAM);
    printf ("El número total de bolas es %ld.\n", resp);
    printf ("El tamaño de bolas es %d bytes.\n", sizeof bolas);
    return 0;
}

long suma (int ar[], int n)
{                               /* ¿cómo es de grande un array? */
    int i;
    long total = 0;

    for (i = 0; i < n; i++)
        total += ar[i];

    printf ("El tamaño de ar es %d bytes.\n", sizeof ar);

    return total;
}
