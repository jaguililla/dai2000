// ALGORITMO PILA

// INCLUDES
#include<stdlib.h>


#include"basico.h"

// DEFINES
#define N 5

// PROTOTIPOS
void init_array (int array[]);  // Inicializa el array a 0
int completa (int array[]);
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
int completa (int array[])
{
    int n_datos;

    if (array[0] > array[N - 1]) {
        n_datos = N - 2 - (array[N - 1] - array[0]);    //N-2-array[N-1]+array[0];
    }
    else {
        n_datos = array[N - 1] - array[0];
    }

    /*if (n_datos==N-2)
       return (YES);
       else if(n_datos==0)
       return(NO);
       else */
    return (n_datos);
}

//////////////////////////////////////////////////////////////////////////////
void alta (int array[], int valor)
{

    if (((array[0] == 0) && (array[N - 1] == N - 2))
        || (array[N - 1] == array[0] - 1))
        printf
            ("\n\t\007No se puede dar de alta ningún valor, la cola está llena");
    else {
        printf ("\n\tIntroduzca el valor a dar de alta: ");
        scanf ("%d", &valor);

        if (array[0] == 0)
            array[0]++;

        array[N - 1]++;

        array[array[N - 1]] = valor;

        printf ("El valor ha sido de alta.");

        if (array[N - 1] == N - 2)
            array[N - 1] = 0;
    }
}

//////////////////////////////////////////////////////////////////////////////

int baja (int array[])
{
    int resp;

    resp = completa (array);

    if (resp) {
        array[0]++;
        printf ("\n\tEl valor dado de baja es: %d", array[array[0] - 1]);
        return (array[array[0] - 1]);
    }
    else {
        printf ("No se puede dar de baja, la cola está vacia.");
    }
}

//////////////////////////////////////////////////////////////////////////////
void listado (int array[])
{
    int indice = 0;

    printf ("\n");
    /*if(array[0]<array[N-1])
       for (indice=array[0]; indice<array[N-1]; indice++)
       printf("%d\t",array[indice]);
       else{
       for(indice=array[0]+1;indice<N-1;indice++)
       printf("%d\t",array[indice]);
       for(indice=1;indice<=array[N-1];indice++)
       printf("%d\t",array[indice]);
       } */

    for (indice = array[0]; indice != array[N - 1]; indice++) {
        if (indice == N - 1) {
            indice = 1;
        }

        printf ("%d\t", array[indice]);
    }

    printf ("\n\t");
}

//////////////////////////////////////////////////////////////////////////////

// MAIN
void main (void)
{
    int cola[N], control = 0, salir = NO, valor = 0, resp;

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
                printf ("\n\tIntroduzca un valor entre 1 y 4: ");
        }                       // Fin do-while
        while ((control < 1) || (control > 4));

        switch (control) {

            case 1:

                alta (cola, valor);
                //if(cola[N-1]==N-2)
                // cola[N-1]=0;//le pongo cero porque antes de dar de alta
                //le sumo uno al elemento
                break;

            case 2:
                valor = baja (cola);

                if (cola[0] == N - 2)
                    cola[0] = 0;    //ey,tú, igual que arriba

                break;

            case 3:
                listado (cola);

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
