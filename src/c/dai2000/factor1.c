/* factor.c -- cálculo de factoriales con bucles */
#include <stdio.h>
int main (void)
{
    int num;
    long fact (int n);

    while (scanf ("%d", &num) == 1) {
        if (num < 0)
            printf ("Me horrorizan los números negativos.\n");
        else if (num > 15)
            printf ("Sólo puedo llegar hasta 15.\n");
        else
            printf ("%d factorial = %ld\n", num, fact (num));
    }

    return 0;
}

long fact (int n)
{                               /* bucle para cálculo de factorial */
    long ans;

    for (ans = 1; n > 1; n--)
        ans *= n;

    return ans;
}
