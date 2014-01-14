/* Muestra todos los primos menores que un número dado */
#include <stdio.h>

void main (void)
{
    long int valor, n;

    clrscr ();
    printf ("Introduzca un valor: ");
    scanf ("%ld", &valor);
    printf ("primos menores que %ld\n", valor);
    for (n = 1; n < valor; n++)
        if (primo (n))
            printf ("%4ld", n);
    getch ();
}

int primo (long int i)
{
    long int divisor;

    if (i < 4)
        return (1);
    else {
        divisor = i / 2;
        while (i % divisor)
            divisor--;
        if (divisor == 1)
            return (1);
        else
            return (0);
    }
}
