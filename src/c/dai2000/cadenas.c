#include <string.h>
#include <stdio.h>
#define LONGCAD 255
#define MAXCAD 10
void main (void)
{
    char cad[MAXCAD][LONGCAD], aux[LONGCAD];
    int i, j, numcad;

    clrscr ();

    do {
        printf ("¿Cuántas cadenas de caracteres(<=%d): ", MAXCAD);

        do
            scanf ("%d%c", &numcad);
        while (numcad > MAXCAD);

        for (i = 0; i < numcad; i++) {
            printf ("Introduzca cadena %d: ", i + 1);
            gets (cad[i]);
        }

        printf ("%50s\n", "Escritura de las cadenas generadas");

        for (i = 0; i < numcad; i++)
            puts (cad[i]);

        printf ("%50s\n", "ORDENACIÓN DE LAS CADENAS");

        for (i = 0; i < numcad - 1; i++)
            for (j = i + 1; j < numcad; j++)
                if (strcmp (cad[i], cad[j]) > 0) {
                    strcpy (aux, cad[i]);
                    strcpy (cad[i], cad[j]);
                    strcpy (cad[j], aux);
                }

        printf ("%50s\n", "Escritura de las cadenas ordenadas");

        for (i = 0; i < numcad; i++)
            puts (cad[i]);

        printf ("pulse tecla \n");

        getch ();
    }
    while (numcad);
}
