// Algoritmo triangulo
#include <stdio.h>
#include <math.h>
// Prototipos
void leer_vertice (double *x, double *y);
double longitud (double x1, double y1, double x2, double y2);
double area (double l1, double l2, double l3);

// main()
void main (void)
{
    double x1, y1, x2, y2, x3, y3, l1, l2, l3, p;

    clrscr ();
    leer_vertice (&x1, &y1);
    leer_vertice (&x2, &y2);
    leer_vertice (&x3, &y3);
    l1 = longitud (x1, y1, x2, y2);
    l2 = longitud (x1, y1, x3, y3);
    l3 = longitud (x2, y2, x3, y3);
    printf
        ("Area triangulo A(%3.1f,%3.1f),B(%3.1f,%3.1f),C(%3.1f,%3.1f): %lf\n",
         x1, y1, x2, y2, x3, y3, area (l1, l2, l3));

    getch ();
}

// Funciones

void leer_vertice (double *x, double *y)
{
    // double px=0,py=0;

    printf ("Introduce el valor de un vertice (x,y)");
    scanf ("%lf %lf", x, y);
    printf ("x=%3.1f  y=%3.1f\n", *x, *y);
    /* *x = px;
     *y = py;*/
}

double longitud (double x1, double y1, double x2, double y2)
{
    double l, sum1, sum2;

    sum1 = (x2 - x1) * (x2 - x1);
    printf ("dif en x2 %3.1f\n", sum1);
    sum2 = (y2 - y1) * (y2 - y1);
    printf ("dif en y2 %3.1f\n", sum2);
    l = sqrt (sum1 + sum2);
    printf ("longitud lado %3.1f\n", l);
    return (l);
}

double area (double l1, double l2, double l3)
{
    double a, p;

    p = (l1 + l2 + l3) / 2;
    a = sqrt (p * (p - l1) * (p - l2) * (p - l3));
    return (a);
}
