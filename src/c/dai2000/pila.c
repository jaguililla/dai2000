// ALGORITMO PILA

// INCLUDES
#include<stdlib.h>


#include"basico.h"

// DEFINES
#define N 5

// PROTOTIPOS
void init_array (int array[]);  // Inicializa el array a 0
void alta (int array[], int valor);
int baja (int array[]);

// FUNCIONES
void init_array (int array[])
{
    int cont = 0;

    for (cont = 0; cont < N; cont++)
        array[cont] = 0;
}

//////////////////////////////////////////////////////////////////////////////
void alta (int array[], int valor)
{
    if (array[0] >= N - 1)
        printf
            ("\n\t\x07No se puede dar de alta ningún valor, la pila está llena");
    else {
        array[0]++;
        array[array[0]] = valor;
        printf ("El valor ha sido dado de alta.");
    }
}

//////////////////////////////////////////////////////////////////////////////
int baja (int array[])
{
    if (array[0] >= 1) {
        array[0]--;
        return (array[array[0] + 1]);
    }
    else {
        printf ("No se puede dar de baja, la pila está vacia");
    }
}

//////////////////////////////////////////////////////////////////////////////
void listado (int array[])
{
    int indice = 0;

    printf ("\n");

    for (indice = 1; indice <= array[0]; indice++)
        printf ("%d\t", array[indice]);
}

//////////////////////////////////////////////////////////////////////////////

// MAIN
void main (void)
{
    int pila[N], control = 0, salir = NO, valor = 0;

    init_array (pila);
    pila[0] = 0;

    do {
        clrscr ();
        printf ("\n\n\tSeleccione la operación a realizar:\n");
        printf ("\n\t\t1.- Introducir un valor (alta).");
        printf ("\n\t\t2.- Borrar un valor (baja).");
        printf ("\n\t\t3.- Listado de la pila.");
        printf ("\n\t\t4.- Salir de la aplicación.");
        printf ("\n\n\tSu selección es: ");

        do {
            scanf ("%d", &control);

            if ((control < 1) || (control > 4))
                printf ("\n\t\x07Introduzca un valor entre 1 y 4: ");
        }                       // Fin do-while
        while ((control < 1) || (control > 4));

        switch (control) {

            case 1:
                printf ("\n\tIntroduzca el valor a dar de alta: ");
                scanf ("%d", &valor);
                alta (pila, valor);
                break;

            case 2:
                valor = baja (pila);
                printf ("\n\tEl valor dado de baja es: %d", valor);
                break;

            case 3:
                listado (pila);
                break;

            case 4:
                salir = YES;
                break;
        }

        if (!salir)
            getch ();
    }
    while (salir != YES);
}
