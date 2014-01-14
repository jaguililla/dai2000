#include <stdio.h>              /* cromos.c */

#include <stdlib.h>
#define cc 10                   /* cromos colección */
#define cs 3                    /* cromos sobre */
void inicializar (int a[], int k)
{
    /* inicia colección a 0. Si un cromo no está almacena 0. Si está un 1 */
    int i;

    for (i = 0; i < k; i++)
        a[i] = 0;
}

void mostrar (int a[], int k)
{
    /* muestra la colección o el sobre */
    int i;

    for (i = 0; i < k; i++)
        printf ("%3d", a[i]);
}

void comprar (int a[], int k)
{                               /* compra de un sobre */
    int i;

    for (i = 0; i < k; i++)
        a[i] = (rand ()%cc) + 1;
}

int completa (int col[], int k)
{                               /* mira si colección completa. Todo a 1 */
    int i = -1;

    do
        i++;
    while (col[i] && i < k - 1);

    return (col[i]);            /* devuelve 0=falso si no está, 1=cierto, si está */
}                               /* completa */

void actualiza (int coleccion[], int sobre[], int css)
{
    /*actualiza la colección con los cromos de cada sobre */
    int i;

    for (i = 0; i < css; i++)
        coleccion[sobre[i] - 1] = 1;

    /* se resta 1 al número del cromo porque la colección se indexa desde 0 */
}

void main (void)
{
    int coleccion[cc], sobre[cs], sobres = 0, ptas, i;

    clrscr ();
    randomize ();
    printf ("ptas sobre: ");
    scanf ("%d", &ptas);
    inicializar (coleccion, cc);    /* no hay ningún cromo */
    printf ("%34s", " ");

    for (i = 0; i < cc; i++)
        printf ("%3d", i + 1);

    printf ("\n");

    printf ("%34s", "colección:");

    mostrar (coleccion, cc);

    printf ("\n");

    do {
        sobres++;
        comprar (sobre, cs);    /* se compra un sobre */
        actualiza (coleccion, sobre, cs);   /* se actualiza la colección */
        printf ("sobre (%2d):", sobres);
        mostrar (sobre, cs);    /*muestra evolución */
        printf ("\tcolección:");
        mostrar (coleccion, cc);
        printf ("  pulse tecla\n");
        getch ();
    }
    while (!completa (coleccion, cc));  /* mientras no está completa */

    printf ("sobres=%d  precio=%d\n", sobres, sobres * ptas);

    getch ();
}
