/* codigoch.c -- halla el número de código de un carácter */
#include <stdio.h>
main ()
{
    char ch;

    printf ("Introduzca un carácter.\n");
    scanf ("%c", &ch);          /* el usuario introduce un carácter */
    printf ("El código de %c es %d.\n", ch, ch);
}
