// ALGORITMO BINGO

// INCLUDES
#include <stdlib.h>


// DEFINES
#define SI  1
#define NO  0

#define NJUG 3                  // Nº de jugadores
#define NFIL 5                  // Nº de filas del cartón
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
int mira_linea (int cartones[][NFIL][NCOL]);
int mira_bingo (int cartones[][NFIL][NCOL]);
void imp_cartones (int cartones[][NFIL][NCOL]);
void imp_tablero (int tablero[]);

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
int mira_linea (int cartones[][NFIL][NCOL])
{
    int cont = 0, cont1 = 0, cont2 = 0, ln = NO;

    for (cont = 0; (cont < NJUG) && (ln); cont++) {
        for (cont1 = 0; (cont1 < NFIL) && (ln); cont1++)    // No sale hasta recorrer todas las filas
        {

            for (cont2 = 0; (cont2 < NCOL) && (ln); cont2++) {
                if (cartones[cont][cont1][cont2] == NOBOLA)
                    ln = cont;
                else
                    ln = NO;
            }

        }
    }

    return (ln);
}

//////////////////////////////////////////////////////////////////////////////
int mira_bingo (int cartones[][NFIL][NCOL])
{
    int cont = 0, cont1 = 0, cont2 = 0, bin = NO;

    for (cont = 0; (cont < NJUG) && (bin); cont++) {
        for (cont1 = 0; (cont1 < NFIL) && (bin); cont1++)   // No sale hasta recorrer todas las filas
        {

            for (cont2 = 0; (cont2 < NCOL) && (bin); cont2++) {
                if (cartones[cont][cont1][cont2] == NOBOLA)
                    bin = cont;
                else
                    bin = NO;
            }

        }
    }

    return (bin);
}

//////////////////////////////////////////////////////////////////////////////
void imp_cartones (int cartones[][NFIL][NCOL])
{
    int cont1 = 0, cont2 = 0, cont3 = 0, x = 0, y = 0;

    y = 1;
    gotoxy (x, y);

    for (cont1 = 0; cont1 < NJUG; cont1++) {
        gotoxy (5, y++);
        cprintf ("JUGADOR %d\n", cont1);

        for (cont2 = 0; cont2 < NFIL; cont2++) {
            for (cont3 = 0; cont3 < NCOL; cont3++) {
                if (cartones[cont1][cont2][cont3] == NOBOLA)
                    cprintf ("%2c ", 'X');
                else
                    cprintf ("%2d ", cartones[cont1][cont2][cont3]);
            }

            gotoxy (5, y++);
        }

        y += 2;
        gotoxy (5, y);
    }
}

//////////////////////////////////////////////////////////////////////////////
void imp_tablero (int tablero[])
{
    int cont1 = 0, cont2 = 0, x = 0, y = 0;

    x = 40;
    y = 18;
    gotoxy (x, y);

    for (cont1 = 0; cont1 < 9; cont1++) {
        for (cont2 = 0; cont2 < 9; cont2++) {
            if (tablero[cont2 + (cont1 * 10)] == NOBOLA)
                cprintf ("%2c  ", '*');
            else
                cprintf ("%2d  ", tablero[cont2 + (cont1 * 10)]);
        }

        gotoxy (x, y++);
    }
}

//////////////////////////////////////////////////////////////////////////////
/*
// MAIN
void main (void)
{
 int carton[NJUG][NFIL][NCOL], sacadas[NBOLAS], linea=NO, bingo=NO;
 int cantada=NO;
 
 clrscr();
 _setcursortype(_NOCURSOR);
 init_array(sacadas);
 init_array_3d(carton);
 genera_cartones(carton);
 do
 {
  tacha_carton(carton, saca_bola(sacadas));
  imp_cartones(carton);
  imp_tablero(sacadas);
  if (!linea)
   linea=mira_linea(carton);
  else if (!cantada)
  {
   cprintf ("Ha cantado línea el jugador %d",linea);
   getch();
  }
  bingo=mira_bingo(carton);
 }
 while(!bingo);
 cprintf("El ganador es el jugador %",bingo);
 getch();
}
//////////////////////////////////////////////////////////////////////////////
*/
// PRUEBAS
void main (void)
{
}

//////////////////////////////////////////////////////////////////////////////
