/* botellas.c -- cuenta atrás */
#include <stdio.h>
#define MAX 100
main ()
{
    int cont = MAX + 1;

    while (--cont > 0) {
        printf ("¡%d botellas de vino en el estante, %d botellas!\n",
                cont, cont);
        printf ("Alguien pasó por delante y ¿qué fue de ellas?\n");
        printf ("¡Sólo quedan %d botellas!\n\n", cont - 1);
    }
}
