#include<stdio.h>
#include<math.h>
double eleva (double base, int exp)
{
    if (exp == 0)
        return (1);
    else
        return (base * eleva (base, exp - 1));
}
void main (void)
{
    int exp;
    double base, total;

    clrscr ();
    printf ("Introduzca la base y el exponente: ");
    scanf ("%lf%d", &base, &exp);
    total = eleva (base, exp);
    printf ("La potencia es: %lf", total);
    getch ();
}
