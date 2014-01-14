// A L G O R I T M O   O R D E N A ///////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>

#include <time.h>

#include "../basico.h"

// D E F I N E S /////////////////////////////////////////////////////////////
#define MAX 5

// P R O T O T I P O S ///////////////////////////////////////////////////////
void cambiar (int *n1, int *n2);
void init_array (int array[]);
void random_array (int array[], int num);
void lee_array (int array[]);
void ordena_sel (int array[]);
void ordena_sel_m (int array[]);
void imp_array (int array[]);

// F U N C I O N E S /////////////////////////////////////////////////////////
void cambiar (int *n1, int *n2)
{
    int aux = 0;

    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

//////////////////////////////////////////////////////////////////////////////

void init_array (int array[])
{
    int cont = 0;

    for (cont = 0; cont < MAX; cont++) {
        array[cont] = 0;
    }
}

//////////////////////////////////////////////////////////////////////////////

void random_array (int array[], int num)
{
    int cont = 0;

    randomize ();

    for (cont = 0; cont < MAX; cont++) {
        array[cont] = rand ()%num + 1;
    }
}

//////////////////////////////////////////////////////////////////////////////

void lee_array (int array[])
{
    int cont = 0;

    for (cont = 0; cont < MAX; cont++) {
        scanf ("%d", &array[cont]);
    }
}

//////////////////////////////////////////////////////////////////////////////

void ordena_sel (int array[])
{
    int cont = 0, cont2 = 0, menor = 0, pos_menor = 0;
    bool cambio;

    for (cont = 0; cont < MAX - 1 && cambio == TRUE; cont++) {
        menor = array[cont];
        pos_menor = cont;

        for (cont2 = cont + 1; cont2 < MAX; cont2++) {
            if (array[cont2] < menor) {
                menor = array[cont2];
                pos_menor = cont2;
            }
        }

        cambiar (&array[pos_menor], &array[cont]);
        printf ("Iteración %d: ", cont + 1);    // Esta línea no es necesaria
        imp_array (array);      // Esta línea no es necesaria
        printf ("\n");          // Esta línea no es necesaria

        if (pos_menor == cont)  // Si no ha habido cambios
        {                       // salir del bucle
            cambio = FALSE;     // && cambio == TRUE
        }
    }
}

//////////////////////////////////////////////////////////////////////////////

void ordena_sel_m (int array[])
{
    int cont_i = 0, cont_f = 0, cont = 0;
    int menor = 0, pos_menor = 0, mayor = 0, pos_mayor = 0;
    bool cambio;

    for (cont_i = 0, cont_f = MAX - 1; cont_i <= cont_f && cambio == TRUE;
         cont_i++, cont_f--) {
        menor = array[cont_i];
        pos_menor = cont_i;
        mayor = array[cont_f];
        pos_mayor = cont_f;

        for (cont = cont_i + 1; cont <= cont_f; cont++) {
            if (array[cont] < menor) {
                menor = array[cont];
                pos_menor = cont;
            }
            else if (array[cont] > mayor) {
                mayor = array[cont];
                pos_mayor = cont;
            }
        }

        cambiar (&array[pos_menor], &array[cont_i]);
        cambiar (&array[pos_mayor], &array[cont_f]);
        printf ("Iteración %d: ", cont_i + 1);  // Esta línea no es necesaria
        imp_array (array);      // Esta línea no es necesaria
        printf ("\n");          // Esta línea no es necesaria

        if ((pos_menor == cont_i) || (pos_mayor == cont_f)) {   // Si no ha habido cambios
            cambio = FALSE;     // salir del bucle
        }                       // && cambio == TRUE
    }
}

//////////////////////////////////////////////////////////////////////////////

void imp_array (int array[])
{
    int cont = 0;

    for (cont = 0; cont < MAX; cont++) {
        printf ("%d ", array[cont]);
    }
}

//////////////////////////////////////////////////////////////////////////////

// M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
    int vector[MAX];

    clrscr ();
    init_array (vector);
    printf ("\nIntroduzca los valores del array: ");
    lee_array (vector);
    printf ("\nValor inicial del array: ");
    imp_array (vector);
    printf ("\n------------------------------------------\n");
    ordena_sel_m (vector);
    printf ("------------------------------------------");
    printf ("\nValor final del array: ");
    imp_array (vector);
    getch ();
}
