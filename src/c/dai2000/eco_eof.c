/* eco_eof.c -- repite entrada hasta fin de fichero */
#include <stdio.h>
int main (void)
{
    char ch;

    while ((ch = getchar ()) != EOF)
        putchar (ch);

    return 0;
}
