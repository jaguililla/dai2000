/* une_mira.c -- unión de dos tiras comprobando si caben */
#include <stdio.h>
#include <string.h>
#define MAX 80
int main (void)
{
    static char flor[MAX];
    static char apendice[] = " huelen a zapato usado.";

    puts ("¿Cuáles son sus flores favoritas?");
    gets (flor);

    if ((strlen (apendice) + strlen (flor) + 1) <= MAX)
        strcat (flor, apendice);

    puts (flor);

    return 0;
}
