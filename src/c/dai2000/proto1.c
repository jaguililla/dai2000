/* proto1.c -- usa un prototipo de función */
#include <stdio.h>
int imax (int, int);            /* prototipo */
int main (void)
{
    printf ("El máximo entre %d y %d es %d.\n", 3, 5, imax (3, 5));
    printf ("El máximo entre %d y %d es %d.\n", 3, 5, imax (3.0, 5.0));
    return 0;
}

int imax (int n, int m)
{
    int max;

    if (n > m)
        max = n;
    else
        max = m;

    return max;
}
