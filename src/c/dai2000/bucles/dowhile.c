/* dowhile.c -- bucle con condición de salida */
#include <stdio.h>
main ()
{
    char ch;

    do {
        scanf ("%c", &ch);
        printf ("%c", ch);
    }
    while (ch != '#');
}
