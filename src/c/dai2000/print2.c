/* print2.c -- más posibilidades de printf() */
#include <stdio.h>
main ()
{
    unsigned un = 40000;
    long ln = 2000000000;
    unsigned long uln = 2 * 2000000000; /* o 4000000000 */
    short sn = 200;

    printf ("un = %u y no %d\n", un, un);
    printf ("ln = %ld y no %d\n", ln, ln);
    printf ("uln = %lu y no %u\n", uln, uln);
    printf ("sn = %hd y, en este sistema, %d\n", sn, sn);
}
