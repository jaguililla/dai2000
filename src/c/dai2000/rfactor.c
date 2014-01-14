/* rfactor.c -- cálculo de factoriales con recursividad */
#include <stdio.h>
int main (void)
{
    int num;
    long rfact (int n);

    while (scanf ("%d", &num) == 1) {
        if (num < 0)
            printf ("Me horrorizan los números negativos.\n");
        else if (num > 15)
            printf ("Sólo puedo llegar hasta 15.\n");
        else
            printf ("%d factorial = %ld\n", num, rfact (num));
    }

    return 0;
}

long rfact (int n)
{                               /* función recursiva */
    long ans;

    if (n > 0)
        ans = n * rfact (n - 1);
    else
        ans = 1;

    return ans;
}
