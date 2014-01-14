/* nonono.c -- ¡¡¡¡¡ Noooooo !!!!! */
#include <stdio.h>
int main (void)
{
    static c1 = 'A';
    static char asino[] = { 'H', 'O', 'L', 'A' };
    static c2 = 'B';

    puts (asino);               /* no es una tira de caracteres */
    return 0;
}
