#include <stdio.h>

#include <stdlib.h>

#define   N  400

int Datos[N], Valor, Posicion;

void Cargar (int *Datos, int Total)
{
    int i, Rango;

    printf ("Introduzca valor máximo datos a generar: ");
    scanf ("%d", &Rango);
    randomize ();

    for (i = 0; i < Total; i++)
        Datos[i] = rand()%Rango /*(0xFFFF) */ ;
}

void Presentar (int *Datos, int Total)
{
    int i;

    for (i = 0; i < Total; i++)
        printf ("%4d", Datos[i]);

    printf ("\n");
}

void Shell (int *Datos, int Total)
{                               /* Ordenación por método Shell */
    register int j, Salto;
    int aux, k, hallado;

    Salto = Total / 2;

    while (Salto > 0) {
        for (j = Salto; j < Total; ++j) {
            /* Ordenación por inserción */
            aux = Datos[j];
            k = j - Salto;
            hallado = 0;

            while (k >= 0 && hallado == 0)
                if (aux < Datos[k]) {
                    Datos[k + Salto] = Datos[k];
                    k = k - Salto;
                }
                else
                    hallado = -1;

            Datos[k + Salto] = aux;
        }

        Salto = Salto / 2;
    }
}

int Ordenada (int *Datos, int Total)
{
    int i;

    for (i = 0; i < Total - 1; ++i)
        if (Datos[i] > Datos[i + 1])
            return 0;

    return -1;
}

void main (void)
{
    clrscr ();
    Cargar (Datos, N);
    /*Presentar (Datos,N); */
    Shell (Datos, N);
    Presentar (Datos, N);

    if (Ordenada (Datos, N) != 0)
        printf ("\nDatos ordenados \n");
    else
        printf ("\nDatos desordenados \n");

    getch ();
}
