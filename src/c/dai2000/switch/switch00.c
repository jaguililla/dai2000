/*
 * Ejemplo sentencia 'switch'.
 */

#include <stdio.h>

int main (void) {
    char v;

    printf ("Introduzca un carácter alfabético: 0-SALIR ");
    v = getchar ();
    printf ("%c \n", v);
    v = toupper (v); /* pone un carácter en mayúscula */
    printf ("\n en mayúscula %c \n", v);
    switch (v) {
        case 'A':
            printf ("tecleó una 'a'\n");
            break;
        case 'E':
            printf ("tecleó una 'e'\n");
            break;
        case 'I':
            printf ("tecleó una 'i'\n");
            break;
        case 'O':
            printf ("tecleó una 'o'\n");
            break;
        case 'U':
            printf ("tecleó una 'u'\n");
            break;
        default:
            printf ("no tecleó ninguna vocal \n");
            break;
    }
    printf ("\npulse una tecla ");
}
