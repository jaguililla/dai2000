/* copia2.c -- strcpy() en acción */
#include <stdio.h>
#include <string.h>             /* declara strcpy() */
#define WORDS "burro"
#define TAM 40
int main (void)
{
    static char *orig = WORDS;
    static char copia[TAM] = "No sea blando con sus vicios";
    char *ps;

    puts (orig);
    puts (copia);
    ps = strcpy (copia + 7, orig);
    puts (copia);
    puts (ps);
    return 0;
}
