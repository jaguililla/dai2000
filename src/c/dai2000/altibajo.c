// ALGORITMO ALTIBAJO

// INCLUDES
#include <stdlib.h>


#include "../basico.h"

// DEFINES
#define N 5

// PROTOTIPOS
void alta (int array[], int valor, int ulti);   // Programa para dar de alta un valor
void init_array (int array[]);  // Inicializa el array a 0
bool existe (int array[], int valor);   // Comprueba si el valor ya existe en el array
void ordenado (int array[], int ulti);  // Comprueba si el array está ordenado
void baja (int array[], int valor, int ulti);   // Programa para dar de baja un valor
void imp_array (int array[]);
int busca (int array[], int valor, int ulti);

// FUNCIONES
void init_array (int array[])
{
    int cont = 0;

    for (cont = 0; cont < N; cont++)
        array[cont] = 0;
}

//////////////////////////////////////////////////////////////////////////////

void imp_array (int array[])
{
    int cont = 0;

    for (cont = 0; cont < N; cont++)
        if (array[cont] > 0)
            printf ("%d ", array[cont]);
}

//////////////////////////////////////////////////////////////////////////////

bool existe (int array[], int val)
{
    int cont = 0;
    bool esta = NO;

    for (cont = 0; cont < N; cont++) {
        if (array[cont] == val) {
            esta = YES;
            break;
        }
    }

    return (esta);
}

//////////////////////////////////////////////////////////////////////////////
void alta (int array[], int valor, int ulti)
{
    int pos, indice;

    pos = busca (array, valor, ulti);   // Busca la posición donde insertar

    for (indice = ulti + 1; indice > pos; indice--) {
        array[indice] = array[indice - 1];
    }

    array[pos] = valor;
    printf ("\n\tEl valor ha sido dado de alta.\n\t");
}

//////////////////////////////////////////////////////////////////////////////

void ordenado (int array[], int ulti)
{
    int cont, orden = YES;

    for (cont = 1; cont <= ulti; cont++) {
        if (array[cont] <= array[cont - 1]) // Cambio <= por >=
            orden = NO;
    }

    imp_array (array);

    if (orden)
        printf ("\n\tLa tabla está ordenada.");
    else
        printf ("\n\tOOOOOOhhhhhhh");
}

//////////////////////////////////////////////////////////////////////////////

int busca (int array[], int valor, int ulti)
{
    int central, EI = 0, ES = ulti, indice;

    while (EI <= ES) {
        central = (EI + ES) / 2;

        if (valor > array[central]) // Cambio de < por >
            EI = central + 1;
        else
            ES = central - 1;
    }

    // printf ("EI= %d",EI);
    return (EI);
}

//////////////////////////////////////////////////////////////////////////////
void baja (int array[], int valor, int ulti)
{
    int pos, indice;

    pos = busca (array, valor, ulti);

    for (indice = pos; indice < ulti; indice++)
        array[indice] = array[indice + 1];

    array[indice] = 0;

    printf ("El valor ha sido dado de baja.\n\t");
}

//////////////////////////////////////////////////////////////////////////////
// MAIN
void main (void)
{
    int valores[N], val = 0, control = 0, u_pos = -1;

    init_array (valores);

    do {
        clrscr ();
        printf ("\n\n\tSeleccione la operación a realizar:\n");
        printf ("\n\t\t1.- Introducir un valor (alta).");
        printf ("\n\t\t2.- Borrar un valor (baja).");
        printf ("\n\t\t3.- Salir de la aplicación.");
        printf ("\n\n\tSu selección es: ");

        do {
            scanf ("%d", &control);

            if ((control < 1) || (control > 3))
                printf ("\n\tIntroduzca un valor entre 1 y 3: ");
        }                       // Fin do-while
        while ((control < 1) || (control > 3));

        switch (control) {

            case 1:

                if (u_pos == N) // (array[N-1]==0)
                {
                    printf
                        ("\n\tLa tabla está completa. No se puede insertar más valores.");
                    imp_array (valores);
                }
                else {
                    printf ("\tIntroduzca el valor a insertar: ");

                    do {
                        scanf ("%d", &val);

                        if (existe (valores, val) == YES)
                            printf
                                ("El valor introducido ya existe. Introduzca otro valor: ");
                    }
                    while (existe (valores, val) == YES);   // Se puede evitar la condición con un break

                    alta (valores, val, u_pos);

                    u_pos++;

                    ordenado (valores, u_pos);
                }

                break;

            case 2:

                if (u_pos == -1) {
                    printf
                        ("No se puede dar de baja ningún número ya que la tabla está vacía.");
                }
                else {
                    printf ("Introduzca el valor a dar de baja: ");

                    do {
                        scanf ("%d", &val);

                        if (existe (valores, val) == NO)
                            printf
                                ("El valor indicado no existe.Introduzca un valor que está en la tabla.");
                    }
                    while (existe (valores, val) == NO);

                    baja (valores, val, u_pos);

                    u_pos--;

                    ordenado (valores, u_pos);

                    imp_array (valores);
                }

                break;

            case 3:
                exit (0);
                break;
        }                       // Fin switch

        printf ("\n¿Desea realizar otra operación?(s/n): ");
    }
    while (getch () != 'n');
}
