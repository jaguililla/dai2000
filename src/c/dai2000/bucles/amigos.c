/* amigos.c   981012
  Este programa comprueba si dos números son amigos.
  Dos números son amigos si la suma de los divisores de uno de ellos,
 es igual al valor del otro número, excluyéndose ambos números como
 divisores de sí mismos
*/
#include <stdio.h>

void prueba (int s1, int s2, int n1, int n2)
{
    if (s1 == s2)
        printf ("%d y %d son amigos\n", n1, n2);
    else
        printf ("%d y %d no son amigos\n", n1, n2);
    getch ();
}

void sumafor (int n, int *s)
{
    /* calcula la suma de todos los divisores de n con 'for' */
    int d = 0;

    *s = 0;
    for (d = 1; d < n / 2; d++)
        if (!(n % d)) {
            *s += d;
            printf ("%d+", d);
        }
    /* probar el último divisor posible : n/2 */
    if (!(n / 2 % d)) {
        *s += d;
        printf ("%d", d);
    }
    printf ("=%d   HECHO CON FOR \n", *s);
}

void sumado (int n, int *s)
{
    /* calcula la suma de todos los divisores de n con 'do' */
    int d = 0;

    *s = 0;
    do {
        d++;
        if (!(n % d)) {
            *s += d;
            printf ("%d+", d);
        }
    } while (d < n / 2 - 1);    /* d sale con el valor n/2 - 1 */
    d++;
    if (!(n % d)) {
        *s += d;
        printf ("%d", d);
    }
    printf ("=%d  HECHO CON DO \n", *s);
}

void sumawhile (int n, int *s)
{
    /* calcula la suma de todos los divisores de n con 'while' */
    int d = 0;

    *s = 0;
    while (d < n / 2 - 1) {
        d++;
        if (!(n % d)) {
            *s += d;
            printf ("%d+", d);
        }
    }
    d++;
    if (!(n % d)) {
        *s += d;
        printf ("%d", d);
    }
    printf ("=  %d  HECHO CON while \n", *s);
}

void main (void)
{
    int n1, n2, s1, s2, d;

    clrscr ();
    printf ("Introduzca dos enteros: ");
    scanf ("%d %d", &n1, &n2);

    sumafor (n1, &s1);
    sumafor (n2, &s2);
    prueba (s1, s2, n1, n2);

    sumado (n1, &s1);
    sumado (n2, &s2);
    prueba (s1, s2, n1, n2);

    sumawhile (n1, &s1);
    sumawhile (n2, &s2);
    prueba (s1, s2, n1, n2);
    printf ("FIN DE PROGRAMA \n");
    getch ();
}
