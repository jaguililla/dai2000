#include "stdio.h"
main ()
{
    int positivos = 0, negativos = 0, ceros = 0, numero;

    clrscr ();
    printf ("Introduce un número (999 para terminar) :  ");
    scanf ("%d", &numero);

    while (numero != 999) {
        if (numero < 0)
            ++negativos;

        else if (numero > 0)
            ++positivos;

        else
            ++ceros;

        printf ("Introduce un número (999 para terminar) :  ");
        scanf ("%d", &numero);

    }

    printf ("\n El total de números positivos es: %d", positivos);
    printf ("\n El total de números negativos es: %d", negativos);
    printf ("\n El total de ceros es: %d", ceros);
    printf ("\n\n Pulse una tecla para continuar");
    getch ();
}
