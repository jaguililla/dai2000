/* copia1.c -- strcpy() en acción */
#include <stdio.h>
#include <string.h>             /* declara strcpy() */
#define FRASE "Reconsidere su última entrada, por favor."
#define TAM 40
int main (void)
{
    static char *orig = FRASE;
    static char copia[TAM] = "espacio reservado";

    puts (orig);
    puts (copia);
    strcpy (copia, orig);
    puts (orig);
    puts (copia);
    return 0;
}
