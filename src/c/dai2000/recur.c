/* recur.c -- ejemplo de recursividad */
#include <stdio.h>
void sube_baja (int);
int main (void)
{
    sube_baja (1);
    return 0;
}

void sube_baja (int n)
{
    printf ("Nivel %d\n", n);   /* impresión 1 */

    if (n < 4)
        sube_baja (n + 1);

    printf ("NIVEL %d\n", n);   /* impresión 2 */
}
