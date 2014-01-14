#include <stdio.h>
float potencia (float, int);

void main (void)
{
    float base;
    int exponente;

    clrscr ();
    printf ("Introduzca base y exponente: ");
    scanf ("%f %d", &base, &exponente);
    printf ("%f ^ %d = %f\n", base, exponente, potencia (base, exponente));
    getch ();
}

float potencia (float b, int e)
{
    int i;
    float p;

    p = 1;
    for (i = 1; i <= e; i++)
        p = p * b;
    return (p);
}
