/* cier_fal.c -- valores verdaderos y falsos en C */
#include <stdio.h>
main ()
{
    int cierto, falso;

    cierto = (10 > 2);          /* valor de una relación cierta */
    falso = (10 == 2);          /* valor de una relación falsa  */
    printf ("cierto = %d; falso = %d \n", cierto, falso);
}
