#include <stdio.h>

void pintar (int);
void recursi (int);

void main (void)
{
    int a;

    clrscr ();
    printf ("Introduzca entero: ");
    scanf ("%d", &a);
    recursi (a);
    getch ();
}

void pintar (int x)
{
    int i;

    for (i = 0; i < x; i++)
        putchar ('*');
    printf ("\n");
}

void recursi (int k)
{
    pintar (k);
    if (k > 2) {
        recursi (k - 1);
        pintar (k);
        recursi (k - 2);
        pintar (k);
    }
}

  /* Ejecución

     Introduzca entero: 5
     *****
     ****
     ***
     **
     ***
     *
     ***
     ****
     **
     ****
     *****
     ***
     **
     ***
     *
     ***
     *****

   */
