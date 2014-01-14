#include <stdio.h>

unsigned int factorial (unsigned int);
unsigned int suma (unsigned int);
unsigned int fibo (unsigned int);
unsigned int potencia (unsigned int, unsigned int);
unsigned int mcd (unsigned int, unsigned int);
void main (void)
{
    unsigned int b, e;

    clrscr ();
    printf ("Introduzca dos enteros: ");
    scanf ("%d %d", &b, &e);

    printf ("%d!=%d\n", b, factorial (b));
    printf ("Sumatorio %d=%d\n", b, suma (b));
    printf ("Fibonacci(%d)=%d\n", b, fibo (b));
    printf ("%d^%d=%d\n", b, e, potencia (b, e));
    printf ("mcd(%d,%d)=", b, e);
    if (b >= e)
        printf ("%d", mcd (b, e));
    else
        printf ("%d", mcd (e, b));
    printf ("\n");

    getch ();
}
unsigned int factorial (unsigned int n)
{
    if (n == 0)
        return 1;
    else
        return (n * factorial (n - 1));
}

unsigned int suma (unsigned int n)
{
    if (n == 0)
        return 0;
    else
        return (n + suma (n - 1));
}

unsigned int fibo (unsigned int n)
{
    if (n < 3)
        return n - 1;
    else
        return (fibo (n - 1) + fibo (n - 2));
}

unsigned int potencia (unsigned int b, unsigned int e)
{
    if (e == 0)
        return 1;
    else
        return (b * potencia (b, e - 1));
}

unsigned int mcd (unsigned int a, unsigned int b)
{
    if (a % b == 0)
        return b;
    else
        return (mcd (b, a % b));
}

     /* Ejecución

        Introduzca dos enteros: 6 4
        6!=720
        Sumatorio 6=21
        Fibonacci(6)=5
        6^4=1296
        mcd(6,4)=2

      */
