/* eco.c -- repite entrada */
#include <stdio.h>
int main (void)
{
    char ch;

    while ((ch = getchar ()) != '#')
        putchar (ch);

    return 0;
}
