/* str_cat.c -- uniendo dos tiras */
#include <stdio.h>
#include <string.h>             /* declara la función strcat() */
#define TAM 80
int main (void)
{
    static char flor[TAM];
    static char apendice[] = " huelen a zapato usado.";

    puts ("¿Cuáles son sus flores favoritas?");
    gets (flor);
    strcat (flor, apendice);
    puts (flor);
    puts (apendice);
    return 0;
}
