/* intconv.c -- algunas conversiones de enteros disparatadas */
#include <stdio.h>
#define PAGINAS 336
#define PALABRAS 65616
main ()
{
    int num = PAGINAS;
    int mnum = -PAGINAS;

    printf ("%d %u %d %u\n", num, num, mnum, mnum);
    printf ("%d %c\n", num, num);
    printf ("%ld %d\n", PALABRAS, PALABRAS);
}
