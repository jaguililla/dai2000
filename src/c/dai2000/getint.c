/* getint.c */
#include <stdio.h>
#include "getint.h"
int getint (ptint)
     int *ptint;                /* puntero a salida entera */
{
    int quees;

    quees = scanf ("%d", ptint);

    if (quees == NONUM)
        scanf ("%*s");

    return quees;
}
