// Algoritmo: Dorsal

#include <stdio.h>


void main (void)
{
    int Num;

    clrscr ();
    printf ("Introduzca un número: ");
    scanf ("%d", &Num);

    switch (Num) {

        case 1:
            printf ("Portero\n");
            break;

        case 2:

        case 3:

        case 5:
            printf ("Defensa\n");
            break;

        case 4:

        case 6:
            printf ("medio\n");
            break;

        case 7:

        case 8:

        case 9:

        case 10:

        case 11:
            printf ("delantero\n");
            break;

        default:
            printf ("Suplente\n");
            break;
    };

    getch ();
}
