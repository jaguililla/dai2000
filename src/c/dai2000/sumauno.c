/* sumauno.c -- incremento: prefijo y sufijo */
#include <stdio.h>
main ()
{
    int ultra = 0, super = 0;

    while (super < 5) {
        super++;
        ++ultra;
        printf ("super = %d, ultra = %d \n", super, ultra);
    }
}
