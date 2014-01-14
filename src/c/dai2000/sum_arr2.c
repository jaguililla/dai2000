/* sum_arr2.c -- suma los elementos de un array */
#include <stdio.h>
#define TAM 10
long sumap (int *ar, int n);
int main (void)
{
    static int bolas[TAM] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
    long resp;

    resp = sumap (bolas, TAM);
    printf ("El número total de bolas es %ld.\n", resp);
    return 0;
}

long sumap (int *ar, int n)
{                               /* usa aritmética de punteros     */
    int i;
    long total = 0;

    for (i = 0; i < n; i++) {
        total += *ar;           /* suma valor al total            */
        ar++;                   /* avanza puntero a otro elemento */
    }

    return total;
}
