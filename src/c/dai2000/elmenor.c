/* elmenor.c -- decide el menor entre dos males */
#include <stdio.h>
int main (void)
{
    int mal1, mal2;
    int imin (int, int);

    while (scanf ("%d %d", &mal1, &mal2) == 2)
        printf ("El menor entre %d y %d es %d.\n", mal1, mal2,
                imin (mal1, mal2));

    return 0;
}

int imin (int n, int m)
{
    int min;

    if (n < m)
        min = n;
    else
        min = m;

    return min;
}
