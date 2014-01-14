// Algoritmo triangulo
#include <stdio.h>

#include <math.h>
// Prototipos
void leer_vertice (int *x, int *y);
double longitud (int x1, int y1, int x2, int y2);
double area (double l1, double l2, double l3);

// main()
void main (void)
{
    int x1, y1, x2, y2, x3, y3;
    double l1, l2, l3;

    clrscr ();
    leer_vertice (&x1, &y1);
    leer_vertice (&x2, &y2);
    leer_vertice (&x3, &y3);
    l1 = longitud (x1, y1, x2, y2);
    l2 = longitud (x1, y1, x3, y3);
    l3 = longitud (x2, y2, x3, y3);
    printf ("Area del triangulo A(%d,%d), B(%d,%d), C(%d,%d): %lf\n",
            x1, y1, x2, y2, x3, y3, area (l1, l2, l3));
    getch ();
}

// Funciones

void leer_vertice (int *x, int *y)
{
    int px, py;

    printf ("Introduce el valor de un vertice (x,y)");
    scanf ("%d %d", &px, &py);
    *x = px;
    *y = py;
}

double longitud (int x1, int y1, int x2, int y2)
{
    double l = 0;

    l = sqrt (pow ((double) x1 - x2, 2) + pow ((double) y1 - y2, 2));
    return (l);
}

double area (double l1, double l2, double l3)
{
    double a = 0, p = 0;

    p = (l1 + l2 + l3) / 2;
    a = sqrt (p * (p - l1) * (p - l2) * (p - l3));
    return (a);
}
