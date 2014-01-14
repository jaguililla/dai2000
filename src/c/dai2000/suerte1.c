/* suerte1.c -- bucle contador */
#include <stdio.h>
#define NUMERO 22
main ()
{
    int cont = 1;               /* inicialización  */

    while (cont <= NUMERO) {    /* test            */
        printf ("¡Buena suerte!\n");    /* acción          */
        cont++;                 /* incremento cont */
    }
}
