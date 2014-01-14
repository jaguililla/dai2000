#include<stdio.h>

float media (int num);
void main (void)
{
    int numero;
    float total;

    clrscr ();
    printf ("Introduzca un número: ");
    scanf ("%d", &numero);
    total = media (numero);
    printf ("La media es: %1.0f", total);
    getch ();
}
float media (int num)
{
    if (num == 1)
        return (1);
    else
        return ((media (num - 1) * (num - 1) + num) / num);
}
