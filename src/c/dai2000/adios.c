/*
 * adios.c - ejemplo de atexit()
 */

/* I N C L U D E **************************************************************/
#include <stdio.h>

/* D E F I N E ****************************************************************/
#define ANSI                    /* omítase en implementaciones no ANSI */

#if defined (ANSI)              /* o bien use __STDC__ (véase texto) */
#    include <stdlib.h>
#    define ATEXIT(X) atexit(X)
#    define VOID void
#else
#    define ATEXIT(X)
#    define VOID int
#endif

#ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
#    define EXIT_FAILURE 1
#endif

/* P R O T O T Y P E **********************************************************/
void apaga (VOID);

/* P R O C E D U R E **********************************************************/
void apaga (VOID)
{
    puts ("Así termina otro maravilloso programa de");
    puts ("Octeto Logical");
}

/* M A I N ********************************************************************/
int main (void)
{
    int n;

    ATEXIT (apaga);
    puts ("Introduzca un entero:");

    if (scanf ("%d", &n) != 1) {
        puts ("¡Eso no es un entero!");
        exit (EXIT_FAILURE);
    }

    printf ("%d es %s.\n", n, (n % 2 == 0) ? "par" : "impar");
    exit (EXIT_SUCCESS);
    return 0;
}

/* E O F **********************************************************************/
