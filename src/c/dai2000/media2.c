#include<stdio.h>

void main (void)
{
    int num1, num2, decide, indice, cont = 1, suma = 1;
    int div1, div2;

    clrscr ();
    printf ("Introduzca dos números: ");
    scanf ("%d%d", &num1, &num2);
    //decidimos cual es mayor

    if (num2 > num1) {
        decide = num2;
        num2 = num1;
        num1 = decide;
    }                           //guardaremos en num1 el nº mayor

    for (indice = 2; indice <= num2 / 2; indice++) {
        div1 = num1 % indice;
        div2 = num2 % indice;   //comprobamos si indice es divisor de los dos nº

        if ((div1 == 0) && (div2 == 0)) {
            suma += indice;     //acumula la suma de los divisores de los dos nº
            cont++;             //indica cuantos nº son divisores comunes
        }
    }

    printf ("La media de sus divisores es: %f", (float) suma / cont);
    getch ();
}
