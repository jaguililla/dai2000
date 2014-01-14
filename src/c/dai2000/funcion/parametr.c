/* parametr */
#include <stdio.h>
#include <stdlib.h>
#define n 5
void leer (int num[n], int k);
void escribir (int num[], int k);
void modificar (int *num, int k);

void main (void)
{
    int datos[n], i;

    leer (datos, n);
    escribir (datos, n);
    modificar (datos, n);
    escribir (datos, n);
    getch ();
}

void leer (int num[n], int k)
{
    int i;

    for (i = 0; i < k; i++)
        num[i] = rand () % 10;   /* requiere stdlib.h */
}

void escribir (int num[], int k)
{
    int i;

    for (i = 0; i < k; i++)
        printf ("%3d", num[i]);
    printf ("\n");
}

void modificar (int *num, int k)
{
    int i;

    for (i = 0; i < k; i++)
        num[i] += 3;
}
