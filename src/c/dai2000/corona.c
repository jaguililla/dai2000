/* Algoritmo Corona */

#include <stdio.h>

#include<math.h>
#define PI 3.14

/* función circulo */
double circulo (float rad)
{
    double area = 0.0;

    area = PI * (rad * rad);
    return (area);
}

/* main */
void main (void)
{
    float r1, r2;

    clrscr ();
    printf ("Introduzca el valor de los dos radios: ");
    scanf ("%f %f", &r1, &r2);

    if (r1 < r2) {
        printf ("El resultado es: %f", circulo (r2) - circulo (r1));
    }
    else {
        printf ("El resultado es: %f", circulo (r1) - circulo (r2));
    }

    getch ();
}
