/* qsortrec */
#include <stdio.h>
#include <stdlib.h>

#define n 15
#define r 10
int datos[n], conta[r];

void quicksort (int a[], int ei, int ed)
{
    int i, d, pivote, aux;

    i = ei;
    d = ed;
    pivote = a[(ei + ed) / 2];

    do {
        while (a[i] < pivote)
            i++;

        while (pivote < a[d])
            d--;

        if (i <= d) {
            aux = a[i];
            a[i] = a[d];
            a[d] = aux;
            i++;
            d--;
        }
    }
    while (i <= d);

    if (ei < d)
        quicksort (a, ei, d);

    if (i < ed)
        quicksort (a, i, ed);
}

int ordenada (int a[], int Total)
{
    int i;

    for (i = 0; i < Total - 1; ++i)
        if (a[i] > a[i + 1])
            return 0;

    return -1;
}

void main (void)
{
    int i, generados = 0;

    clrscr ();
    randomize ();

    for (i = 0; i < r; i++)
        conta[i] = 0;           /* inicializa conta a 0 */

    for (i = 0; i < n; i++) {
        datos[i] = rand ()%r;
        conta[datos[i]]++;
    }

    for (i = 0; i < r; i++)
        generados += conta[i];

    printf ("números generados %d\n", generados);

    printf ("rango= ");

    for (i = 0; i < r; i++)
        printf ("%4d", i);

    printf ("\n");

    printf ("datos= ");

    for (i = 0; i < n; i++)
        printf ("%4d", datos[i]);

    printf ("\n");

    printf ("conta= ");

    for (i = 0; i < r; i++)
        printf ("%4d", conta[i]);

    printf ("\n");

    quicksort (datos, 0, n - 1);

    if (ordenada (datos, n))
        printf ("datos ordenados \n");
    else
        printf ("datos no ordenados \n");

    for (i = 0; i < n; i++)
        conta[datos[i]]--;      /*deben salir contadores a 0 */

    i = 0;

    while ((i < r - 1) && (conta[i] == 0))
        i++;

    if (conta[i])
        printf ("Algo anda mal en conta[%d]=%d\n", i, conta[i]);
    else
        printf ("no se han perdido datos\n");

    printf ("rango= ");

    for (i = 0; i < r; i++)
        printf ("%4d", i);

    printf ("\n");

    printf ("datos= ");

    for (i = 0; i < n; i++)
        printf ("%4d", datos[i]);

    printf ("\n");

    printf ("conta= ");

    for (i = 0; i < r; i++)
        printf ("%4d", conta[i]);

    printf ("\n");

    getch ();
}                               /* Ejecución

                                   números generados 15
                                   rango=    0   1   2   3   4   5   6   7   8   9
                                   datos=    1   3   4   0   6   8   9   8   8   7   4   8   1   4   4
                                   conta=    1   2   0   1   4   0   1   1   4   1
                                   datos ordenados
                                   no se han perdido datos
                                   rango=    0   1   2   3   4   5   6   7   8   9
                                   datos=    0   1   1   3   4   4   4   4   6   7   8   8   8   8   9
                                   conta=    0   0   0   0   0   0   0   0   0   0
                                 */
