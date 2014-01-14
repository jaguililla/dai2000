/* parametr */
#include <stdio.h>
#include <stdlib.h>
#define nf 3
#define nc 5
void leer (int num[][nc], int k1, int k2);
void escribir (int num[][nc], int k1, int k2);
void modificar (int num[][nc], int k1, int k2);

void main (void)
{
    int datos[nf][nc];

    leer (datos, nf, nc);
    escribir (datos, nf, nc);
    modificar (datos, nf, nc);
    printf ("\n");
    escribir (datos, nf, nc);
    getch ();
}

void leer (int num[][nc], int a, int b)
{
    int i, j;

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            printf ("Introduzca fila %d columna %d", i + 1, j + 1);
            scanf ("%d", &num[i][j]);
        }
    }
}

void escribir (int num[][nc], int a, int b)
{
    int i, j;

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            printf ("%4d", num[i][j]);
        }
        printf ("\n");
    }
}

void modificar (int num[][nc], int a, int b)
{
    int i, j;

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            num[i][j] *= 2;
        }
    }
}

/* ejecución

   1   2   3   4   5
   6   7   8   9   0
  11  22  33  44  55

   2   4   6   8  10
  12  14  16  18   0
  22  44  66  88 110

*/
