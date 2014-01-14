/* cuentach.c -- cuenta caracteres no blancos */
#include <stdio.h>
#define PUNTO '.'
int main (void)
{
    int ch;
    int numcar = 0;

    while ((ch = getchar ()) != PUNTO) {
        if (ch != ' ' && ch != '\n' && ch != '\t')
            numcar++;
    }

    printf ("He contado %d caracteres no blancos.\n", numcar);

    return 0;
}
