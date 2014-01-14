/* ifdef.c -- compilación condicional */
#include <stdio.h>
#define PRUEBAS
#define LIMITE 4
int main (void)
{
    int i;
    int total = 0;

    for (i = 1; i <= LIMITE; i++) {
        total += 2 * i * i + 1;
#ifdef PRUEBAS

        printf ("i=%d, Subtotal = %d\n", i, total);
#endif

    }

    printf ("Total = %d\n", total);
    return 0;
}
