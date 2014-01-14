/* cubo_for.c -- usa bucle for para hacer una tabla de cubos */
#include <stdio.h>
main ()
{
    int num;

    printf ("    n   n al cubo\n");

    for (num = 1; num <= 6; num++)
        printf ("%5d %5d\n", num, num * num * num);
}
