/* verdad.c -- ¿qué valores son ciertos? */

#include <stdio.h>

main ()
{
    int n = 3;

    while (n)
        printf ("%d\n", n--);
    n = -3;
    while (n)
        printf ("%2d\n", n++);
}
