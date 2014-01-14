#include <stdio.h>
#define N 5

void main (void)
{
    int i, k, total, a[N];

    clrscr ();
    printf ("Introduzca el array: ");
    for (i = 0; i < N; i++)
        scanf ("%d", &a[i]);

    printf ("array= ");
    for (i = 0; i < N; i++)
        printf ("%3d", a[i]);
    printf ("\n");

    for (i = 0; i < N - 1; i++)
        if (a[i] == a[i + 1])
            break;
    if (a[i] == a[i + 1])
        printf ("\ntiene claves repetidas\n");
    else
        printf ("\nno tiene claves repetidas\n");

    total = N - 1;
    for (i = 0; i < total; i++)
        if (a[i] == a[i + 1]) {
            for (k = i + 1; k < total; k++)
                a[k] = a[k + 1];
            total--;
            i--;
        }

    printf ("array= ");
    if (total)
        for (i = 0; i <= total; i++)
            printf ("%3d", a[i]);
    else
        printf ("no hay datos");
    printf ("\n");

    getch ();
}
