/* Indica si un número entero positivo es capicúa */
// capicua.c
#include <stdio.h>
void main (void)
{
    unsigned long numero, copia, alreves;

    clrscr ();
    printf ("Introduzca un entero positivo ");
    scanf ("%ld", &numero);
    copia = numero;
    alreves = 0;
    while (numero) {            /* while numero > 0 */
        alreves = alreves * 10 + numero % 10;
        numero = numero / 10;
    }
    if (copia == alreves)
        printf ("%ld es capicúa\n", copia);
    else
        printf ("%uld no es capicúa\n", copia);
    printf ("PULSE TECLA PARA TERMINAR\n");
    getch ();
}
