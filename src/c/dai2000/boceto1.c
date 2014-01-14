/* boceto1.c -- primer esquema del esqueleto del programa */
#include <stdio.h>
#define MAX 25
void lee_array (double ar[]);
void saca_array (double ar[]);
double media (double ar[]);
int main (void)
{
    double datos[MAX];

    lee_array (datos);
    saca_array (datos);
    printf ("El promedio es %.2lf.\n", media (datos));
    return 0;
}
