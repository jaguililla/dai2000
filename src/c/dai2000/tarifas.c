/* tarifas.c -- cálculo de tarifas postales */
#include <stdio.h>
#define UNO 20
#define OTRO 12
main ()
{
    int gramos, coste;

    print (" gramos  coste\n");

    for (gramos = 5, coste = UNO; gramos <= 50; gramos += 5, coste += OTRO)
        printf ("%5d %7d\n", gramos, coste);
}
