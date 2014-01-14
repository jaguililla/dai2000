//inverso
#include<stdlib.h>

#define N 6
void main (void)
{
    int tabla[N], indice, cont, aux;

    clrscr ();
    printf ("Introduce los valores de la tabla(6): ");

    for (indice = 0; indice < N; indice++)
        scanf ("%d", &tabla[indice]);

    for (indice = 0, cont = N - 1; indice < cont; indice++, cont--) {
        aux = tabla[indice];
        tabla[indice] = tabla[cont];
        tabla[cont] = aux;
    }

    for (indice = 0; indice < N; indice++)
        printf ("%d ", tabla[indice]);

    getch ();
}
