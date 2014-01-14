// ALGORITMO PILA

// INCLUDES
#include<stdlib.h>


#include"basico.h"

// DEFINES
#define N 5

// PROTOTIPOS
void init_array (int array[]);  // Inicializa el array a 0
void alta (int array[], int valor, int c_c, int f_c);
int baja (int array[], int c_c);

// FUNCIONES
void init_array (int array[])
{
    int cont = 0;

    for (cont = 0; cont < N; cont++)
        array[cont] = 0;
}

//////////////////////////////////////////////////////////////////////////////
void alta (int array[], int valor, int c_c, int f_c)
{
    int llena;

    llena = completa ();

    if (llena)
        printf
            ("\n\t\x07No se puede dar de alta ningún valor, la cola está llena");
    else {
        f_c++;
        array[f_c] = valor;
        printf ("El valor ha sido dado de alta.");
    }
}

//////////////////////////////////////////////////////////////////////////////
int baja (int array[], int c_c)
{
    if (c_c >= 1) {
        c_c--;
        return (array[c_c + 1]);
    }
    else {
        printf ("No se puede dar de baja, la cola está vacia");
    }
}

//////////////////////////////////////////////////////////////////////////////
void listado (int array[], int c_c, int f_c)
{
    int indice = 0;

    printf ("\n");

    for (indice = c_c; indice <= f_c; indice++)
        printf ("%d\t", array[indice]);
}

//////////////////////////////////////////////////////////////////////////////

// MAIN
void main (void)
{
    int cola[N], control = 0, salir = NO, valor = 0, cc = 0, fc = 0;

    init_array (cola);

    do {
        clrscr ();
        printf ("\n\n\tSeleccione la operación a realizar:\n");
        printf ("\n\t\t1.- Introducir un valor (alta).");
        printf ("\n\t\t2.- Borrar un valor (baja).");
        printf ("\n\t\t3.- Listado de la cola.");
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
                alta (cola, valor, cc, fc);
                break;

            case 2:
                valor = baja (cola, cc);
                printf ("\n\tEl valor dado de baja es: %d", valor);
                break;

            case 3:
                listado (cola, cc, fc);
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
