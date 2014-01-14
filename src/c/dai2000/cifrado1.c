/* cifrado1.c -- modifica la entrada conservando los espacios */
#include <stdio.h>
#define ESPACIO ' '             /* apóstrofo espacio apóstrofo */
int main (void)
{
    char ch;

    ch = getchar ();            /* lee un carácter             */

    while (ch != '\n') {        /* while no sea fin de línea   */

        if (ch == ESPACIO)      /* deja carácter espacio       */
            putchar (ch);       /* sin modificar               */
        else
            putchar (ch + 1);   /* cambia los demás caracteres */

        ch = getchar ();        /* toma siguiente carácter     */
    }

    return 0;
}
