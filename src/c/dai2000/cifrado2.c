/* cifrado2.c -- modifica la entrada conservado los espacios */
#include <stdio.h>
#define ESPACIO ' '             /* apóstrofo espacio apóstrofo */
int main (void)
{
    char ch;

    while ((ch = getchar ()) != '\n') {
        if (ch == ESPACIO)      /* deja carácter espacio       */
            putchar (ch);       /* sin modificar               */
        else
            putchar (ch + 1);   /* cambia los demás caracteres */
    }

    return 0;
}
