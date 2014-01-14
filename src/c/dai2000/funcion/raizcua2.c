/* Programa que calcula las raices de una ecuacion de segundo grado */

#include <math.h>
#include <stdio.h>
long raiz (int a, int b, int c);
long raiz2 (int a, int b, int c);
void main ()
{
    int d, e, f;
    long resultado, resultado2;

    clrscr ();
    printf ("\n Teclee el coeficiente de segundo grado: ");
    scanf ("%d", &d);
    printf ("\n Teclee el coeficiente de primer grado: ");
    scanf ("%d", &e);
    printf ("\n Teclee el termino independiente: ");
    scanf ("%d", &f);
    resultado = raiz (d, e, f);
    resultado2 = raiz2 (d, e, f);
    printf ("\n La ecuacion de segundo grado %d x2+ %d x+ %d es %ld ", d, e,
            f, resultado);
    printf ("\n El segundo resultado es %ld", resultado2);
    delay (5000);

}
long raiz (int a, int b, int c)
{
    long rtdo;

    if (b * b - (4 * a * c) == 0)
        return (-b / (2 * a));
    else if (b * b - (4 * a * c) > 0) {

        rtdo = ((-b + sqrt (b * b - (4 * a * c))) / (2 * a));
        return (rtdo);
    }
    else {
        printf ("\n La raiz es compleja");
        return 0;
    }
}

long raiz2 (int a, int b, int c)
{
    long rtdo2;

    if (b * b - (4 * a * c) == 0)
        return (-b / (2 * a));
    else if (b * b - (4 * a * c) > 0) {

        rtdo2 = ((-b - sqrt (b * b - (4 * a * c))) / (2 * a));
        return (rtdo2);
    }
    else {
        printf ("\n La raiz es compleja");
        return 0;
    }
}
