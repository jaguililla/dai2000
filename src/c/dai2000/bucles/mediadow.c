// Cálculo de la media aritmética de N valores con do-while
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
    do {
        cont = cont + 1;
        printf ("Introduzca valor: ");
        scanf ("%f", &valor);
        suma = suma + valor;
    } while (cont < n);
    printf ("La media es: %f", suma / n);
    getch ();
}
