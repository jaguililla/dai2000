/* cálculo del número de cifras de un número */
//numcifr1.c
#include <stdio.h>
void main (void)
{
    unsigned long numero;
    unsigned int cifras;

    clrscr ();
    printf ("d:\\tc\\bin\\fp\\yo\\numcifr1\n");
    printf ("Introduzca un número entero positivo: ");
    scanf ("%ld", &numero);
    cifras = 1;
    while (numero > 9) {
        numero = numero / 10;
        cifras = cifras + 1;
    }
    printf ("El número de cifras del número es %d\n", cifras);
    getch ();
}
