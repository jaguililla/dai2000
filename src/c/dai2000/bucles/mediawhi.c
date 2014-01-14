// Cálculo de la media aritmética de N valores con while-do
//mediawhi.c
#include <stdio.h>
void main (void)
{
    int n, cont;
    float valor, suma;

    clrscr ();
    printf ("Introduzca número de valores para calcular la media: ");
    scanf ("%d", &n);
    cont = 0;
    suma = 0;
    while (cont < n) {
        cont = cont + 1;
        printf ("Introduzca valor: ");
        scanf ("%f", &valor);
        suma = suma + valor;
    }
    printf ("La media es: %f", suma / n);
    getch ();
}
