/************* Cálculo del factorial de un número *************/
/* facto.c
 */
#include <stdio.h>

unsigned long factorial (int n);

void main ()
{
    int numero;
    unsigned long fac;

    do {
        printf ("¿número?  ");
        scanf ("%d", &numero);
    }
    while (numero < 0 || numero > 12);
    fac = factorial (numero);
    printf ("\nEl factorial de %d es %ld\n", numero, fac);
}

unsigned long factorial (int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial (n - 1);
}
