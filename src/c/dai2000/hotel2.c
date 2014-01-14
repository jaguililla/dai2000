/* hotel2.c -- resto del programa de hoteles */
#include <stdio.h>
#include "hoteles.h"
int menu (void)
{
    int codigo, estado;

    printf ("\n%s%s\n", ASTER, ASTER);
    printf ("Indique el número del hotel deseado:\n");
    printf ("1) Aldorf Wastoria2) Hotel Blitz\n");
    printf ("3) Celiá Pastilla        4) Cauliflower Plaza\n");
    printf ("5) salir\n");
    printf ("%s%s\n", ASTER, ASTER);

    while ((estado = scanf ("%d", &codigo)) != 1 ||
           (codigo < 1 || codigo > 5)) {
        if (estado != 1)
            scanf ("%*s");

        printf ("Introduzca un entero de 1 a 5.\n");
    }

    return codigo;
}

int tomanoches (void)
{
    int noches;

    printf ("¿Cuántas noches se reservan? ");

    while (scanf ("%d", &noches) != 1) {
        scanf ("%*s");
        printf ("Necesito un entero, como 2.\n");
    }

    return noches;
}

void sacaprecio (double hotel, int noches)
{
    int n;
    double total = 0.0;
    double factor = 1.0;

    for (n = 1; n <= noches; n++, factor *= DESCUENTO)
        total += hotel * factor;

    printf ("El precio total asciende a %0.2f ptas.\n", total);
}
