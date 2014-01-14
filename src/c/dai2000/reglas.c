/* reglas.c -- test de precedencia */
#include <stdio.h>
main ()
{
    int max, tanteo;

    max = tanteo = -(2 + 5) * 6 + (4 + 3 * (2 + 3));
    printf ("max = %d \n", max);
}
