// ALGORITMO EDIFICIO

// INCLUDES
#include <stdlib.h>

#include <stdio.h>

// DEFINES
#define PLANTAS 5
#define PISOS 3

// PROTOTIPOS

// FUNCIONES
void init_edificio (int array[PLANTAS][PISOS])
{
    int cont = 0, cont2 = 0;

    randomize ();

    for (cont = 0; cont < PLANTAS; cont++) {
        for (cont2 = 0; cont2 < PISOS; cont2++) {
            array[cont][cont2] = rand ()%10;
            printf ("%d\t", array[cont][cont2]);
        }

        printf ("\n");
    }
}

//////////////////////////////////////////////////////////////////////////////

void imp_edificio (int array[PLANTAS][PISOS])
{
    int cont = 0, cont2 = 0;

    printf ("\n");

    for (cont = PLANTAS; cont > 0; cont--) {
        for (cont2 = 0; cont2 < PISOS; cont2++) {
            printf ("\t%d ", array[cont][cont2]);
        }

        printf ("\n");
    }
}

//////////////////////////////////////////////////////////////////////////////

void resultados (int array[PLANTAS][PISOS])
{
    int cont = 0, cont2 = 0, total = 0, cont3;
    int mayor_edificio, inicial, total_planta, mayor_planta;
    int planta_mayor, piso_mayor, planta[PLANTAS];
    int planta_mayor_ed, piso_mayor_ed, valor, mayor;

    mayor_edificio = array[cont][0];

    for (cont = 0; cont < PLANTAS; cont++) {
        inicial = array[cont][0];
        total_planta = 0;

        for (cont2 = 0; cont2 < PISOS; cont2++) {
            if (array[cont][cont2] > inicial) {
                mayor_planta = array[cont][cont2];
                planta_mayor = cont;
                piso_mayor = cont2;
            }

            total_planta += array[cont][cont2];
        }

        planta[cont] = total_planta;

        if (mayor_planta > mayor_edificio) {
            mayor_edificio = mayor_planta;
            planta_mayor_ed = planta_mayor;
            piso_mayor_ed = piso_mayor;
        }
    }

    mayor = planta[0];

    for (cont3 = 0; cont3 < PLANTAS; cont3++) {
        if (planta[cont3] > mayor)
            valor = cont3;

    }

    printf ("Casa con más gente: Planta: %d. Piso: %d.", planta_mayor + 1,
            piso_mayor + 1);
    printf ("\nPlanta con más gente: %d.", valor + 1);
}

//////////////////////////////////////////////////////////////////////////////

// MAIN
void main (void)
{
    int edificio[PLANTAS][PISOS];
    int planta[PLANTAS];

    clrscr ();
    init_edificio (edificio);
    //imp_edificio(edificio);
    resultados (edificio);
    getch ();
}
