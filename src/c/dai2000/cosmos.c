#include <stdio.h>
#include <stdlib.h>
#define nf 10                   /* número de filas */
#define nc 10                   /* número de columnas */

int estrella (int d[][nc], int fila, int col, int i0)
{
    int suma = 0, f, c;
    float media;

    for (f = fila - 1; f <= fila + 1; f++)
        for (c = col - 1; c <= col + 1; c++)
            suma = suma + d[f][c];

    suma = suma - d[fila][col];

    media = (float) suma / 8;

    if (media + d[fila][col] > i0)
        return (1);
    else
        return (0);
}

void cargar (int d[][nc], int filas, int columnas)
{
    int f, c;

    for (f = 0; f < filas - 1; f++) {
        for (c = 0; c < columnas; c++) {
            d[f][c] = rand ()%50;
            printf ("%3d", d[f][c]);
        }

        printf ("\n");
    }
}

void procesar (int d[][nc], char e[][nc], int k0, int filas, int cols)
{
    int f, c;

    for (f = 1; f < filas - 1; f++)
        for (c = 1; c < cols; c++)
            if (estrella (d, f, c, k0))
                e[f][c] = '*';
            else
                e[f][c] = ' ';
}

void mostrar (char d[][nc], int filas, int cols)
{
    int f, c;

    for (f = 0; f < filas; f++) {
        for (c = 0; c < cols; c++)
            if (f == 0 || f == nf - 1)
                if (c == 0)
                    printf ("%3c", '_');
                else
                    printf ("___");
            else if ((c == 0) || (c == nc - 1))
                printf ("%3c", '_');
            else
                printf ("%3c", d[f][c]);

        printf ("\n");
    }
}

void main (void)
{
    int umbral;
    int datos[nf][nc];          /* datos de la región del cielo */
    char dibujo[nf][nc];        /* dibujo de la región del cielo */

    clrscr ();
    randomize ();
    printf ("Introduzca intensidad umbral: ");
    scanf ("%d", &umbral);
    cargar (datos, nf, nc);
    procesar (datos, dibujo, umbral, nf, nc);
    mostrar (dibujo, nf, nc);
    getch ();
}
