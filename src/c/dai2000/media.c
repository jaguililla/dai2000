/* media.c -- calcula la media de una serie de números */
#include <stdio.h>
#define MAX 25
int lee_array (double ar[], int limite);
void saca_array (double ar[], int n);
double media (double ar[], int n);
int main (void)
{
    double datos[MAX];
    int leidos;
    double promedio;

    leidos = lee_array (datos, MAX);

    if (leidos == 0)
        printf ("No hay datos. Adiós.\n");
    else {
        printf ("Se han leído los números siguientes:\n\n");
        saca_array (datos, leidos);
        printf ("\nEl promedio de estos datos es %.2f.\n",
                media (datos, leidos));
    }

    return 0;
}

int lee_array (double ar[], int limite)
{
    int i = 0;

    printf ("Introduzca hasta %d números. Para terminar\n", limite);
    printf ("antes, pulse una letra o EOF.\n");

    while (i < limite && scanf ("%lf", &ar[i]) == 1)
        i++;

    return i;
}

void saca_array (double ar[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf ("%10.2f ", ar[i]);

        if (i % 6 == 5)
            putchar ('\n');
    }

    if (i % 6 != 0)
        putchar ('\n');
}

double media (double ar[], int n)
{
    int i;
    double total = 0;

    for (i = 0; i < n; i++)
        total += ar[i];

    return (total / n);
}
