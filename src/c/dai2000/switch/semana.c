/*
 * SEMANA.C   ESCRIBE EL DÍA DE LA SEMANA.
 *
 * EJECUCIÓN
 * Introduzca ordinal de la semana: 4
 * jueves
 * Introduzca ordinal de la semana: 7
 * FESTIVO
 * Introduzca ordinal de la semana: 6
 * FESTIVO
 * Introduzca ordinal de la semana: 0
 * No es un día correcto
 */

#include <stdio.h>

int main (void) {
    short int dia;

    do {
        printf ("Introduzca ordinal de la semana: ");
        scanf ("%d", &dia);
        switch (dia) {
            case 1:
                printf ("lunes\n");
                break;
            case 2:
                printf ("martes\n");
                break;
            case 3:
                printf ("miercoles\n");
                break;
            case 4:
                printf ("jueves\n");
                break;
            case 5:
                printf ("viernes\n");
                break;
            case 6:
            case 7:
                printf ("FESTIVO\n");
                break;
            default:
                printf ("No es un día correcto\n");
                break;
        }
    } while (dia);
}
