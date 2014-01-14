/* midetipo.c -- imprime tamaños de tipos */
#include <stdio.h>
main ()
{
    printf ("El tipo int ocupa %d bytes.\n", sizeof (int));
    printf ("El tipo char ocupa %d bytes.\n", sizeof (char));
    printf ("El tipo long ocupa %d bytes.\n", sizeof (long));
    printf ("El tipo double ocupa %d bytes.\n", sizeof (double));
}
