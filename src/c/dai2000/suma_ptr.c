/* suma_ptr.c -- adición de punteros */
#include <stdio.h>
#define TAM 4
int main (void)
{
    int fechas[TAM], *pent, indice;
    float facturas[TAM], *pflot;

    pent = fechas;              /* asigna la dirección del array al puntero */
    pflot = facturas;

    for (indice = 0; indice < TAM; indice++)
        printf ("punteros + %d: %10u %10u\n",
                indice, pent + indice, pflot + indice);

    return 0;
}
