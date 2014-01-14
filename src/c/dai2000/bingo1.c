// ALGORITMO BINGO

// INCLUDES
#include <stdlib.h>


// DEFINES
#define SI  1
#define NO  0

#define NJUG 3                  // Nº de jugadores
#define NFIL 4                  // Nº de filas del cartón
#define NCOL 9                  // Nº de columnas del cartón (1 por decena)
#define NBOLAS 90               // Nº de la matriz de los nº sacados (0-89)
#define NOBOLA -1               // Valor para saber si la casilla está tachada

// PROTOTIPOS
void init_array (int array[]);
void init_array_3d (int array[][NFIL][NCOL]);
void genera_cartones (int cartones[][NFIL][NCOL]);
int carton_repetido (int cartones[][NFIL][NCOL], int carton);
int saca_bola (int tablero[]);
void tacha_carton (int cartones[][NFIL][NCOL], int bola);
int mira_cartones (int cartones[][NFIL][NCOL]);
int mira_linea (int cartones[][NFIL][NCOL], int carton);
int mira_bingo (int cartones[][NFIL][NCOL], int carton);
void imp_cartones (int cartones[][NFIL][NCOL]);

// carton_ln es el número del jugador que hace línea (1º indice de cartones)
// carton_bin es el número del jugador que hace bingo (1º indice de cartones)

// FUNCIONES
void init_array (int array[])
{
    int cont = 0;

    for (cont = 0; cont < NBOLAS; cont++)
        array[cont] = NOBOLA;
}

//////////////////////////////////////////////////////////////////////////////
void init_array_3d (int array[][NFIL][NCOL])
{
    int cont1 = 0, cont2 = 0, cont3 = 0;

    for (cont1 = 0; cont1 < NJUG; cont1++) {
        for (cont2 = 0; cont2 < NFIL; cont2++) {
            for (cont3 = 0; cont3 < NCOL; cont3++) {
                array[cont1][cont2][cont3] = 0;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
void genera_cartones (int cartones[][NFIL][NCOL])   // Comprobar si están repetidos al generarlos
{                               // y generar otro si lo están
    int cont1 = 0, cont2 = 0, cont3 = 0;

    randomize ();

    for (cont1 = 0; cont1 < NJUG; cont1++) {
        for (cont2 = 0; cont2 < NFIL; cont2++) {
            for (cont3 = 0; cont3 < NCOL; cont3++) {
                cartones[cont1][cont2][cont3] = (rand ()%10) + (cont3 * 10); // Genera nº de las decenas correspondientes
            }
        }                       // Genera un cartón

        cont1 = (carton_repetido (cartones, cont1)) ? cont1 - 1 : cont1;    // Si están repetidos retrocede el índice para volver a generarlo
    }                           // Genera todos los cartones
}

//////////////////////////////////////////////////////////////////////////////
int carton_repetido (int cart[][NFIL][NCOL], int carton)    // carton es el número de jugador (1º indice) del carton generado en la función llamante (el que se comprueba)
{
    int cont1 = 0, cont2 = 0, cont3 = 0, repe = NO;

    for (cont2 = 0; cont2 < NFIL; cont2++) {
        for (cont3 = 0; cont3 < NCOL; cont3++) {
            for (cont1 = 0; (cont1 < NJUG) && (repe); cont1++) {
                if (cart[carton][cont2][cont3] == cart[cont1][cont2][cont3])
                    repe = SI;
                else
                    repe = NO;
            }
        }
    }

    return (repe);
}

//////////////////////////////////////////////////////////////////////////////
int saca_bola (int tablero[])
{
    int bola = 0;

    randomize ();
    bola = rand ()%NBOLAS;
    tablero[bola] = bola;
    return (bola);
}

//////////////////////////////////////////////////////////////////////////////
void tacha_carton (int cartones[][NFIL][NCOL], int bola)
{
    int cont1 = 0, cont2 = 0, cont3 = 0;

    for (cont1 = 0; cont1 < NJUG; cont1++) {
        for (cont2 = 0; cont2 < NFIL; cont2++) {
            for (cont3 = 0; cont3 < NCOL; cont3++) {
                if (cartones[cont1][cont2][cont3] == bola)
                    cartones[cont1][cont2][cont3] = NOBOLA;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
int mira_cartones (int cartones[][NFIL][NCOL])  // Variables en main booleanas que almacenan si hay ln o bingo (condición de salida)
{
    int cont = 0;
    static linea = NO;
    int bingo = NO;

    for (cont = 0; cont < NJUG && !(bingo || linea); cont++) {
        if (linea == NO)
            linea = mira_linea (cartones, cont);

        bingo = mira_bingo (cartones, cont);
    }

    return (bingo);
}

//////////////////////////////////////////////////////////////////////////////
int mira_linea (int cartones[][NFIL][NCOL], int carton)
{
    int cont1 = 0, cont2 = 0, ln = NO;

    for (cont1 = 0; (cont1 < NFIL) && (ln); cont1++)    // No sale hasta recorrer todas las filas
    {

        for (cont2 = 0; (cont2 < NCOL) && (ln); cont2++) {
            if (cartones[carton][cont1][cont2] == NOBOLA)
                ln = SI;
            else
                ln = NO;
        }

    }
    return (ln);
}

//////////////////////////////////////////////////////////////////////////////
int mira_bingo (int cartones[][NFIL][NCOL], int carton)
{
    int cont1 = 0, cont2 = 0, bin = NO;

    for (cont1 = 0; (cont1 < NFIL) && (bin); cont1++)   // No sale hasta recorrer todas las filas
    {

        for (cont2 = 0; (cont2 < NCOL) && (bin); cont2++) {
            if (cartones[carton][cont1][cont2] == NOBOLA)
                bin = SI;
            else
                bin = NO;
        }

    }
    return (bin);
}

//////////////////////////////////////////////////////////////////////////////
void imp_cartones (int cartones[][NFIL][NCOL])
{
    int cont1 = 0, cont2 = 0, cont3 = 0, y = 0;

    y = 1;

    for (cont1 = 0; cont1 < NJUG; cont1++) {
        for (cont2 = 0; cont2 < NFIL; cont2++) {
            for (cont3 = 0; cont3 < NCOL; cont3++) {
                cprintf ("%2d  ", cartones[cont1][cont2][cont3]);
            }

            gotoxy (5, y++);
        }

        y += 2;
        gotoxy (5, y);
    }
}

//////////////////////////////////////////////////////////////////////////////

// MAIN
void main (void)
{
    int carton[NJUG][NFIL][NCOL], sacadas[NBOLAS], bingo_ = NO;

    init_array (sacadas);
    init_array_3d (carton);
    genera_cartones (carton);

    do {
        tacha_carton (carton, saca_bolas (sacadas));
        mira_cartones (carton);
    }
    while (bingo_);
}

//////////////////////////////////////////////////////////////////////////////
