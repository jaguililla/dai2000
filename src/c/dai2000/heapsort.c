//heapsor0.
#include <stdio.h>

#include <stdlib.h>
#define n 10
/* con la indexación del array empezando en 0, el hijo izquierdo de 'i'
   cae en 2*i+1 y el derecho en 2*i+2.
   El primer nodo no hoja cae en (n-1)/2  */

void mostrar (int a[]);
void cambiar (int *a, int *b);
void construirmonticulo (int a[], int sraiz, int ne);
int ordenado (int a[]);

void main (void)
{
    int i, a[n];
    char op;

    clrscr ();
    randomize ();

    do {
        for (i = 0; i < n; i++)
            a[i] = rand ()%10;

        mostrar (a);

        for (i = (n - 1) / 2; i >= 0; i--)
            construirmonticulo (a, i, n - 1);

        for (i = n - 1; i > 0; i--) {
            cambiar (&a[0], &a[i]);
            construirmonticulo (a, 0, i - 1);
        }

        mostrar (a);

        if (ordenado (a))
            printf ("Datos ordenados");
        else
            printf ("\a\aDatos NO ORDENADOS");

        printf ("  Parar pulse barra...\n");

        op = getch ();
    }
    while (op != ' ');
}

void mostrar (int a[])
{
    int x;

    for (x = 0; x < n; x++)
        printf ("%2d", a[x]);

    printf ("\n");
}

void cambiar (int *a, int *b)
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

void construirmonticulo (int a[], int sraiz, int ne)
{
    int poshijomenor, esmonticulo = 0;

    while ((!esmonticulo) && (2 * sraiz + 1 <= ne)) {
        if (2 * sraiz + 1 == ne)
            poshijomenor = ne;
        else if (a[2 * sraiz + 1] < a[2 * sraiz + 2])
            poshijomenor = 2 * sraiz + 1;
        else
            poshijomenor = 2 * sraiz + 2;

        if (a[poshijomenor] > a[sraiz])
            esmonticulo = 1;
        else {
            cambiar (&a[sraiz], &a[poshijomenor]);
            sraiz = poshijomenor;
        }
    }
}

int ordenado (int a[])
{
    int i;

    for (i = 0; i < n - 1; i++)
        if (a[i] < a[i + 1])
            return (0);

    return (1);
}
