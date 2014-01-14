// ALGORITMO ALTIBAJO

// INCLUDES
#include <stdlib.h>
#include <stdio.h>

#include "../basico.h"


// DEFINES
#define LONG 10                 // Longitud del array a explorar
#define P_V  LONG-2/2           // número máximo de picos y valles

// PROTOTIPOS
void init_array (int array[]);  // Inicializa el array a 0
bool pic_val (int array[], int indice); // Dice si el la posición del array (indice) es un pico o valle
void lee_array (int array[]);   // Da valores al array (manual o aleatorio)
void imp_array (int array[]);   // Imprime el array

// FUNCIONES
void init_array (int array[])
{
    int cont = 0;

    for (cont = 0; cont < LONG; cont++)
        array[cont] = 0;
}

/////////////////////////////////////////////////////////////////////////////
void lee_array (int array[])
{
    int cont = 0, init = 0, n = 0;

    clrscr ();
    gotoxy (1, 4);
    printf ("Seleccione una opción:");
    gotoxy (3, 8);
    printf ("1.- Inicialización manual\n");
    printf ("2.- Inicialización aleatoria");

    do {
        init = getch ();

        if (init != 1 || init != 2) {
            gotoxy (7, 10);
            printf ("\sValor no valido, introduzca 1 ó 2)");
        }
    }
    while (init != 1 || init != 2);

    printf ("                                  ");  // Borra mensaje error

    switch (init) {

        case 1:

            for (cont = 0; cont < LONG; cont++) {
                scanf ("%d", &n);
                array[cont] = n;
            }

            break;

        case 2:
            randomize ();
            gotoxy (7, 10);
            printf ("Introduzca el limite de números aleatorios: ");
            scanf ("%d", &n);

            for (cont = 0; cont < LONG; cont++)
                array[cont] = rand ()%n;

            break;
    }
}

/////////////////////////////////////////////////////////////////////////////
bool pic_val (int array[], int indice)
{
    int cont;
    for (cont = 1; cont < LONG - 1; cont++) // cont=1 xq la pos 0 no se puede calcular
    {

        if (array[cont - 1] < array[cont] && array[cont + 1] < array[cont]) {
        }
    }

}

// MAIN
void main (void)
{
}
