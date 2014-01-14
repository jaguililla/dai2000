#include<stdio.h>

void intercambio (int *a, int *b);
void main (void)
{
    int n1, n2;

    clrscr ();
    printf ("Introduzca dos números: ");
    scanf ("%d%d", &n1, &n2);
    printf ("n1= %d\tn2= %d\n", n1, n2);
    intercambio (&n1, &n2);
    printf ("n1= %d\tn2= %d", n1, n2);
    getch ();
}

void intercambio (int *a, int *b)
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}
