/*
 * adivina.c - Adivina un número aleatorio generado por el ordenador en varios
 *             intentos.
 */

/* I N C L U D E **************************************************************/
#include<stdlib.h>

/* M A I N ********************************************************************/
int main (void)
{
    int num, valor;

    randomize ();
    num = rand () % 100 + 1 + 1;
    printf ("Introduzca un número(1-100): ");
    do {
        scanf ("%d", &valor);
        if (valor > num) {
            printf ("\nEl número pensado es menor.Introduzca otro número: ");
        }
        else if (valor < num) {
            printf ("\nEl número pensado es mayor.Introduzca otro número: ");
        }
    }
    while (valor != num);
    printf ("Ha acertado el número.");
    getch ();
}

/* E O F **********************************************************************/
