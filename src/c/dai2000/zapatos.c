/* zapatos2.c -- calcula cm de pie de varios números de zapato */

#include <stdio.h>
#define TOPE 0.933
#define ESCALA 0.6167

main ()
{
    float zapato, pie;

    printf ("número zapato       centímetros pie\n");
    zapato = 30.0;

    while (zapato < 48.5) {     /* empieza bucle while */
        pie = ESCALA * zapato + TOPE;
        printf ("%10.1f %16.2f cm.\n", zapato, pie);
        zapato = zapato + 1.0;
    }
    printf ("Usted sabe dónde le aprieta el zapato.\n");
}
