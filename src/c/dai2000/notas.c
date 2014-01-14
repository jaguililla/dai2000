#include <stdlib.h>

#define N 10
void main (void)
{
    float notas[N], suma = 0;
    int indice, aprob = 0;

    clrscr ();
    printf ("Introduzca notas de alumnos: ");

    for (indice = 0; indice < N; indice++) {
        scanf ("%f", &notas[indice]);
    };

    for (indice = 0; indice < N; indice++) {
        suma += notas[indice];

        if (notas[indice] >= 5.0)
            aprob++;
    }

    printf ("Hay %d aprobados y la media de clase es %f", aprob,
            (float) suma / N);
    getch ();
}                               //a[i]=random(20);->almacena entre 0 y 19
