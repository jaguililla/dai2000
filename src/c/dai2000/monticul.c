// ALGORITMO MONTICULO

// INCLUDES
#include <stdlib.h>
#include <stdio.h>


#include "../basico.h"

#include "ordena.c"

#define max 5

// PROTOTIPOS
bool EsMonticulo (int Array[]);
void CreaMonticulo (int Array[]);
void OrdenaMonticulo (int array[], int sraiz, int ind);

// FUNCIONES
bool EsMonticulo (int Array[])
{
    int Nodo = 0;
    bool Monticulo = SI;

    for (Nodo = 1; Nodo <= max / 2 && Monticulo; Nodo++) {
        if (Array[Nodo] > Array[2 * Nodo]
            || Array[Nodo] > Array[2 * Nodo + 1])
            Monticulo = NO;
    }

    return (Monticulo);
}

//////////////////////////////////////////////////////////////////////////////
void CreaMonticulo (int Array[])
{
    int Nodo = 0, Mayor = 0;

    for (Nodo = max / 2; Nodo > 0; Nodo--) {
        if (Array[Nodo] > Array[2 * Nodo]
            || Array[Nodo] > Array[2 * Nodo + 1]) {
            if (Array[2 * Nodo] < Array[2 * Nodo + 1])
                Mayor = 2 * Nodo;
            else
                Mayor = 2 * Nodo + 1;

            cambiar (&Array[Mayor], &Array[Nodo]);
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
void OrdenaMonticulo (int array[], int sraiz, int ind)
{
    int esmon;
    int pos;                    //hijo menor

    esmon = NO;

    while ((esmon == NO) && (2 * sraiz <= ind)) {
        if (2 * sraiz == ind)
            pos = 2 * sraiz;
        else {
            if (array[2 * sraiz] < array[(2 * sraiz) + 1])
                pos = 2 * sraiz;
            else
                pos = (2 * sraiz) + 1;
        }

        if (array[pos] >= array[sraiz])
            esmon = SI;
        else {
            cambiar (&array[pos], &array[sraiz]);
            sraiz = pos;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////void monty(int array[],int num1,int num2)
void monty (int array[])
{
    int indice = 0, num1, num2, cont, kk;

    kk = max;

    for (indice = max / 2; indice >= 1; indice--) {
        num1 = array[1];
        num2 = array[indice];
        cambiar (&num1, &num2);
        OrdenaMonticulo (array, indice, kk);
        kk--;
        printf ("\n");

        for (cont = 1; cont <= max; cont++)
            printf ("%2d  ", array[cont]);
    }
}

//////////////////////////////////////////////////////////////////////////////

// MAIN
void main (void)
{
    int vector[MAX], cont;
    bool valor;

    clrscr ();
    init_array (vector);
    random_array (vector, 10);

    for (cont = 1; cont < MAX; cont++)
        printf ("%2d  ", vector[cont]);

    valor = EsMonticulo (vector);

    if (valor == NO)
        CreaMonticulo (vector);

    monty (vector);

    printf ("\n\n");

    for (cont = 1; cont <= max; cont++)
        printf ("%2d  ", vector[cont]);

    getch ();
}
