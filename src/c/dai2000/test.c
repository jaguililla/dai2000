/* test.c -- prueba de la función recortadora de tiras */
#include <stdio.h>
#include <string.h>             /* contiene declaraciones de funciones de tiras */
void corta (char *, int);
int main (void) {
    static char mens[] = "Agárreseme que vienen curvas.";

    puts (mens);
    corta (mens, 10);
    puts (mens);
    return 0;
}

void corta (char *tira, int largo) {
    if (strlen (tira) > largo)
        *(tira + largo) = '\0';
}
