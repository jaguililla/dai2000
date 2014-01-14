/*
 * DIASMES.C:  Días correspondientes a un mes de un año dado.
 * 
 * EJECUCIÓN
 * Introducir mes (##) y año (####): 2 1984
 *
 * El mes 2 del año 1984 tiene 29 días
 * Introducir mes (##) y año (####): 6 1997
 * 
 * El mes 6 del año 1997 tiene 30 días
 * Introducir mes (##) y año (####): 2 1900
 * 
 * El mes 2 del año 1900 tiene 28 días
 */

#include <stdio.h>

int main () {
    unsigned int dd, mm, aa;

    do {
        printf ("Introducir mes (##) y año (####): ");
        scanf ("%d %d", &mm, &aa);
        switch (mm) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                dd = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                dd = 30;
                break;
            case 2:
                if ((aa % 4 == 0) && (aa % 100 != 0) || (aa % 400 == 0))
                    dd = 29;
                else
                    dd = 28;
                break;
            default:
                printf ("El mes no es válido\n");
                break;
        }
        if (mm >= 1 && mm <= 12) {
            printf ("\nEl mes %d del año %d tiene %d días\n", mm, aa, dd);
        }
    }
    while (aa);
    return 0;
}
