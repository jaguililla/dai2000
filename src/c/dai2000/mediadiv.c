#include<stdlib.h>

void main (void)
{
    int contador = 2, indice, num, suma = 1;
    float total;

    clrscr ();
    printf ("Introduzca un número entero: ");
    scanf ("%d", &num);
    suma += num;

    for (indice = 2; indice <= (num / 2); indice++) {
        if (num % indice == 0) {
            contador++;
            suma += indice;
        }
    }

    total = (float) suma / contador;
    printf ("La media es: %f", total);
    getch ();
}
