/* binario.c -- presenta binarios con operaciones binarias */
#include <stdio.h>
int main (void)
{
    char bin_str[8 * sizeof (int) + 1];
    char *itobs (int, char *);
    int numero;

    puts ("Introduzca enteros; los pasará a binario.");
    puts ("Para terminar envíe un carácter no numérico.");

    while (scanf ("%d", &numero) == 1)
        printf ("%d es %s\n", numero, itobs (numero, bin_str));

    return 0;
}

char *itobs (int n, char *ps)
{
    int i;
    static int tam = 8 * sizeof (int);

    for (i = tam - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';

    ps[tam] = '\0';

    return ps;
}

void a_binario (int n)
{                               /* función recursiva */
    int r;

    r = n % 2;

    if (n >= 2)
        a_binario (n / 2);

    putchar ('0' + r);

    return;
}
