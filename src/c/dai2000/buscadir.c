/* buscadir.c -- averigua dónde se almacenan las variables */
#include <stdio.h>
void mikado (int);              /* declara función */
int main (void)
{
    int puf = 2, bah = 5;

    printf ("En main(), puf = %d y &puf = %p\n", puf, &puf);
    printf ("En main(), bah = %d y &bah = %p\n", bah, &bah);
    mikado (puf);
    return 0;
}

void mikado (int bah)
{                               /* define función  */
    int puf = 10;

    printf ("En mikado(), puf = %d y &puf = %p\n", puf, &puf);
    printf ("En mikado(), bah = %d y &bah = %p\n", bah, &bah);
}
