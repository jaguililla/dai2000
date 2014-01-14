/* arf.c -- funciones de arrays */
#include <stdio.h>
#define TAM 5
void saca_array (double ar[], int n);
void mult_array (double mult, double ar[], int n);
int main (void)
{
    static double dip[TAM] = { 20.0, 17.66, 8.2, 15.3, 22.22 };

    saca_array (dip, TAM);
    mult_array (2.5, dip, TAM);
    saca_array (dip, TAM);
    return 0;
}

void saca_array (double ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf ("%8.3f ", ar[i]);

    putchar ('\n');
}

/* multiplica cada miembro del array por una cantidad constante */
void mult_array (double mult, double ar[], int cuantos)
{
    int i;

    for (i = 0; i < cuantos; i++)
        *(ar++) *= mult;
}
