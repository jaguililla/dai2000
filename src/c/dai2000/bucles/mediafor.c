// Cálculo de la media aritmética de N valores con for
// mediafor.c
#include <stdio.h>
void main (void)
{
    int n, cont;
    float valor, suma;

    clrscr ();
    printf ("Introduzca número de valores para calcular la media: ");
    scanf ("%d", &n);
    suma = 0.0;
    for (cont = 1; cont <= n; cont++) {
        printf ("Introduzca valor: ");
        scanf ("%f", &valor);
        suma = suma + valor;
    }
    printf ("La media es: %f\n", suma / n);
    getch ();
}
