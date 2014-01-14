#include <stdio.h>


long fac_for (long num)
{
    long factor = 1, indice = 1;

    for (indice = 1; indice <= num; indice++) {
        factor *= indice;
    }

    return (factor);
}

long fac_do (long num)
{
    long factor = 1, indice = 1;

    do {
        factor *= indice;
        indice++;
    }
    while (indice <= num);

    return (factor);
}

long fac_while (long num)
{
    long indice = 1, factor = 1;

    while (indice <= num) {
        factor *= indice;
        indice++;
    }

    return (factor);
}

void main (void)
{
    long numero;

    clrscr ();
    printf ("Introduce un número: ");
    scanf ("%ld", &numero);
    printf ("El factorial (fac_for) es: %ld\n", fac_for (numero));
    printf ("El factorial (fac_do) es: %ld\n", fac_do (numero));
    printf ("El factorial (fac_while) es: %ld", fac_while (numero));
    getch ();
}
