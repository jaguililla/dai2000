#include<stdlib.h>

#define N 5
void main (void)
{
    int suma1[N], suma2[N], total[N], indice, cont, aux;

    clrscr ();

    for (indice = 1; indice <= 2; indice++) {
        printf ("Introduce las cifras del %dº número de 5 cifras: ", indice);

        for (cont = 0; cont < N; cont++) {
            if (indice == 1)
                scanf ("%d", &suma1[cont]);
            else
                scanf ("%d", &suma2[cont]);
        }
    }

    printf ("La suma es: ");

    for (indice = N - 1; indice >= 0; indice--) {
        aux = (suma1[indice] + suma2[indice]);

        if (indice > 0) {
            total[indice] = aux % 10;
            suma1[indice - 1] += (suma1[indice] + suma2[indice]) / 10;
        }
        else
            total[indice] = aux;
    }

    for (indice = 0; indice < N; indice++)
        printf ("%d", total[indice]);

    getch ();
}
