#include "stdio.h"
main ()
{
    int num, i;
    int resp = 's';

    clrscr ();
    while (resp == 's') {
        printf ("Introduce un número:  ");
        scanf ("%d", &num);

        if (num == 1)
            printf ("El primo de 1 es 1");
        else
            calculo (num);

        printf ("¿Desea continuar (s/n)? ");
        scanf ("%d", &resp);
    }

}

calculo (numf)
     int numf;

{
    int j;

    for (j = numf - 1; j > 1; --j) {
        if (numf % j == 0) {
            printf ("El número %d no es primo ", numf);
            break;
        }

    }
    if (j == 1)
        printf ("El número %d es primo ", numf);

}
