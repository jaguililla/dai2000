/* entrada.c -- bucle con condición de entrada */
#include <stdio.h>
main ()
{
    char ch;

    scanf ("%c", &ch);

    while (ch != '#') {
        printf ("%c", ch);
        scanf ("%c", &ch);
    }
}
