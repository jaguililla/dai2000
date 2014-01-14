/* getarray.c -- lee un array */
#include <stdio.h>
#include "getint.h"             /* declara getint(), constantes */
int getarray (int array[], int limite)
{
    int num, quees;
    int indice = 0;             /* índice del array */

    printf ("Este programa deja de leer a los %d números\n", limite);
    printf ("o si se pulsa EOF.\n");

    while (indice < limite && (quees = getint (&num)) != EOF) {
        if (quees == SINUM) {
            array[indice++] = num;
            printf ("El número %d ha sido aceptado.\n", num);
        }
        else if (quees == NONUM)
            printf ("¡¡Eso no es un entero!! Pruebe otra vez.\n");
        else
            printf ("Esto no debería suceder. Algo va muy mal.\n");
    }

    if (indice == limite)       /* avisa si se ha llenado el array */
        printf ("Tengo completos los %d elementos del array.\n", limite);

    return (indice);
}
