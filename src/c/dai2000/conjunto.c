#include<stdlib.h>

#define N 10

void union_ (int tabla1[], int tabla2[], int tabla3[]);
void inter (int tabla1[], int tabla2[], int tabla3[]);
void difer (int tabla1[], int tabla2[], int tabla3[]);

void vaciar (int array[])
{
    array[0] = 0;
}

void vertabla (int array[])
{
    int indice;

    printf ("\n");

    for (indice = 0; indice < N; indice++)
        printf ("%3d\t", array[indice]);
}

void rellenar (int array[])
{
    int ind = 1;

    array[0] = 0;
    //randomize();

    for (ind; ind < N; ind++) {
        array[ind] = rand ()%50;
        array[0]++;
    }
}

void inter (int tabla1[], int tabla2[], int tabla3[])
{
    int cont = 1, indice2 = 0, indice = 0;

    for (indice = 1; indice < N; indice++) {
        for (indice2 = 1; indice2 < N; indice2++) {
            if (tabla1[indice] == tabla2[indice2]) {
                tabla3[cont] = tabla1[indice];
                tabla3[0]++;    // Incrementar el valor de la ultima posición (campo almacenado en la posición 0 del array)
                cont++;         // Incrementar la posición de la tabla 3 (solución)
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
void main (void)
{
    int tabla1[N], tabla2[N], tabla3[N * 2], oper, indice, cont, resp;

    clrscr ();
    randomize ();
    printf ("\nSeleccione la opción de relleno de la tabla:");
    printf ("\n\t1.- Relleno manual.");
    printf ("\n\t2.- Relleno automático.");
    printf ("\nSu elección es: ");

    do {
        scanf ("%d", &oper);

        if ((oper != 1) && (oper != 2))
            printf ("Introduzca un valor correcto: ");
    }
    while ((oper != 1) && (oper != 2));

    do {
        switch (oper) {

            case 1:

                for (indice = 1; indice <= 2; indice++) {
                    printf ("Introduzca %d valores para la tabla %d: ", N,
                            indice);

                    for (cont = 0; cont < N; cont++)
                        if (indice == 1)
                            scanf ("%d", &tabla1[cont]);
                        else
                            scanf ("%d", &tabla2[cont]);
                };

                break;

            case 2:
                rellenar (tabla1);

                rellenar (tabla2);

                break;
        }

        vertabla (tabla1);
        vertabla (tabla2);
        printf ("\n¿Está de acuerdo con los valores de las tablas?(s/n): ");
        resp = getch ();
    }
    while (resp == 'n');

    vaciar (tabla3);

    printf ("\nIndique la operación a realizar:");

    printf ("\n\t1.- Unión.");

    printf ("\n\t2.- Intersección.");

    printf ("\n\t3.- Diferencia.");

    do {
        oper = getch ();

        if ((oper < '1') || (oper > '3'))
            printf ("Introduzca un valor correcto: ");
    }
    while ((oper < '1') || (oper > '3'));

    switch (oper) {

        case '1':
            union_ (tabla1, tabla2, tabla3);
            break;

        case '2':
            inter (tabla1, tabla2, tabla3);
            break;

        case '3':
            difer (tabla1, tabla2, tabla3);
            break;
    }

}
