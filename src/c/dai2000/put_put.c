/* put_put.c -- funciones anidadas */
#include <stdio.h>
void put1 (char *);
int put2 ();
int main (void)
{
    put1 ("Si tuviera dinero suficiente,\n");
    printf ("He contado %d caracteres.\n",
            put2 ("arreglaría de una vez esa gotera."));
    return 0;
}
