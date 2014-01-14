// A L G O R I T M O   C O L E C C I O N /////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>

#include "../basico.h"

// D E F I N E S /////////////////////////////////////////////////////////////
#define CROMOS_COL  100
#define CROMOS_SOB  5
#define PTS_SOB     25

// P R O T O T I P O S ///////////////////////////////////////////////////////
void comprar (int sob[]);
void init_album (bool col[]);
void init_sobre (int sob[]);
byte pegar (int sob[], bool col[]);
bool comprueba_album (bool col[]);

// F U N C I O N E S /////////////////////////////////////////////////////////
void comprar (int sob[])
{
    int cont = 0, cont2 = 0;
    bool repe = NO;

    for (cont = 0; cont < CROMOS_SOB; cont++) {
        sob[cont] = rand ()%CROMOS_COL;

        while (repe == NO || cont2 <= cont) {
            for (cont2 = 0; cont2 <= cont; cont2++) {
                if (sob[cont] == sob[cont2]) {
                    repe = YES;
                    sob[cont] = rand ()%CROMOS_COL;
                }               // Fin if
            }                   // Fin for
        }                       // Fin while
    }                           // Fin for
}

//////////////////////////////////////////////////////////////////////////////

void init_album (bool col[])
{
    int cont = 0;

    for (cont = 0; cont < CROMOS_COL; cont++) {
        col[cont] = NO;
    }
}

//////////////////////////////////////////////////////////////////////////////

void init_sobre (int sob[])
{
    int cont = 0;

    for (cont = 0; cont < CROMOS_SOB; cont++) {
        sob[cont] = 0;
    }

}

//////////////////////////////////////////////////////////////////////////////

byte pegar (int sob[], bool col[])
{
    int cont = 0;
    byte repetidos = 0;

    for (cont = 0; cont < CROMOS_SOB; cont++) {
        if (col[sob[cont]] == YES) {
            repetidos++;
        }

        col[sob[cont]] = YES;
    }

    return (repetidos);
}

//////////////////////////////////////////////////////////////////////////////

bool comprueba_album (bool col[])
{
    int cont = 0;
    bool completa = YES;

    for (cont = 0; cont < CROMOS_COL || completa == YES; cont++) {
        completa = (col[cont] == NO) ? NO : YES;
    }

    return (completa);
}

// M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
    int sobre[CROMOS_SOB], repes = 0, cont = 0, precio = 0;
    bool album[CROMOS_COL];

    clrscr ();
    init_album (album);

    while (comprueba_album == NO) {
        init_sobre (sobre);
        comprar (sobre);
        repes += (int) pegar (sobre, album);
        cont++;
    }

    precio = cont * PTS_SOB;
    printf ("\n\n\n");
    printf ("La colección se completa con %d sobres: %d Pts.", cont, precio);
    getch ();
}
