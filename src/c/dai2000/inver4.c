/* inver4.c -- invierte los cuatro últimos bits de un entero */
#include <stdio.h>
int main (void)
{
    char bin_str[8 * sizeof (int) + 1];
    char *itobs (int n, char *ps);
    int fin_inver (int num, int bits);
    int numero;

    puts ("Introduzca enteros; los pasará a binario.");
    puts ("Para terminar envíe un carácter no numérico.");

    while (scanf ("%d", &numero) == 1) {
        printf ("%d es %s\n", numero, itobs (numero, bin_str));
        printf ("Al invertir los 4 bits finales queda %s\n",
                itobs (fin_inver (numero, 4), bin_str));
    }

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

int fin_inver (int num, int bits)
{
    int mascara = 0;
    int bitval = 1;

    while (bits-- > 0) {
        mascara |= bitval;
        bitval <<= 1;
    }

    return num ^ mascara;
}
