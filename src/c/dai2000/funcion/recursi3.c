#include <stdio.h>

void rec (int *, int, int);

void main (void)
{
    int a = 20, b = 2;

    clrscr ();
    rec (&a, b, 5);
    printf ("%4d,%4d\n", a, b);
    getch ();
}

void rec (int *x, int y, int z)
{
    printf ("%4d,%4d,%4d\n", *x, y, z);
    switch (y) {
        case 0:
            printf ("%4d,%4d,%4d\n", *x, y, z);
            break;
        case 1:
        case 3:
            *x = y - z;
            y--;
            rec (x, y - 1, z - 2);
            break;
        case 2:
        case 4:
            printf ("%4d,%4d\n", *x, y);
            rec (x, y - 1, z);
            break;
    }
    printf ("%4d,%4d,%4d\n", *x, y, z);
}                               /* recursi */

/* ejecución

  20,   2,   5
  20,   2
  20,   1,   5
  -4,  -1,   3
  -4,  -1,   3
  -4,   0,   5
  -4,   2,   5
  -4,   2

  */
