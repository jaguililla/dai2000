/* boceto2.c -- segundo esquema a alto nivel */
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
