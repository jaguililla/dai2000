// A L G O R I T M O   E D I F I C I O ///////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>

#include <stdio.h>

// D E F I N E S
#define PLANTAS 5
#define PISOS 3

// P R O T O T I P O S ///////////////////////////////////////////////////////
void init_edificio (int array[][PISOS]);
void imp_edificio (int array[][PISOS]);

// F U N C I O N E S /////////////////////////////////////////////////////////
void init_edificio (int array[][PISOS])
{
    int cont = 0, cont2 = 0;

    randomize ();

    for (cont = 0; cont < PLANTAS; cont++) {
        for (cont2 = 0; cont2 < PISOS; cont2++) {
            array[cont][cont2] = rand ()%10;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////

void imp_edificio (int array[][PISOS])
{
    int cont = 0, cont2 = 0;

    printf ("\n\n\tPISOS\t\tA\t B\t  C");
    printf ("\n\t-----------------------------------");

    for (cont = PLANTAS - 1; cont >= 0; cont--) {
        printf ("\n\t");
        printf ("PLANTA %d -->", cont + 1);

        for (cont2 = 0; cont2 < PISOS; cont2++) {
            printf ("\t");
            cprintf ("%d", array[cont][cont2]);
        }
    }
}

//////////////////////////////////////////////////////////////////////////////

void casa_mayor_menor (int array[][PISOS])
{
    int planta = 0, piso = 0;
    int planta_mayor = 0, piso_mayor = 0, planta_menor = 0, piso_menor = 0;

    for (planta = 0; planta < PLANTAS; planta++) {
        for (piso = 0; piso < PISOS; piso++) {
            if (array[planta][piso] > array[planta_mayor][piso_mayor]) {
                planta_mayor = planta;
                piso_mayor = piso;
            }
            else if (array[planta][piso] < array[planta_menor][piso_menor]) {
                planta_menor = planta;
                piso_menor = piso;
            }
        }                       // Pisos mayor y menor de cada planta
    }

    gotoxy (9, 12);
    printf ("La casa más habitada es: PLANTA: %d  PISO: %c",
            planta_mayor + 1, 64 + piso_mayor + 1);
    gotoxy (9, 13);
    printf ("La casa menos habitada es: PLANTA: %d  PISO: %c",
            planta_menor + 1, 64 + piso_menor + 1);
}

//////////////////////////////////////////////////////////////////////////////

void planta_mayor (int array[][PISOS])
{
    int planta = 0, piso = 0, cont = 0, planta_m = 0;
    int p_planta[PLANTAS] = { 0, 0, 0, 0, 0 };

    for (planta = 0; planta < PLANTAS; planta++) {
        for (piso = 0; piso < PISOS; piso++) {
            p_planta[planta] += array[planta][piso];

        }

        cprintf ("%d ", p_planta[planta]);
    }

    for (cont = 0; cont < PLANTAS; cont++) {
        if (p_planta[cont] > p_planta[planta_m]) {
            planta_m = cont;
        }
    }

    printf ("La planta más habitada es: %d", planta_m + 1);
}

// M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
    int edificio[PLANTAS][PISOS];

    init_edificio (edificio);
    imp_edificio (edificio);
    casa_mayor_menor (edificio);
    planta_mayor (edificio);
}
