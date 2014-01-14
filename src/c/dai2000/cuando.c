/* cuando.c -- cuándo se termina un bucle */
#include <stdio.h>
main ()
{
    int n = 5;

    while (n < 7) {             /* línea 7 */
        printf ("n = %d\n", n);
        n++;                    /* línea 10 */
        printf ("Ahora n = %d\n", n);   /* línea 11 */
    }
}
