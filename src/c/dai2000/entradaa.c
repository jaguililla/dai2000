/* entrada.c -- comienzo de un programa */
#include <stdio.h>
#include <string.h>
#define TAM 81
#define LIM 100
#define STOP ""                 /* una tira nula */
int main (void)
{
    static char entra[LIM][TAM];
    int ct = 0;

    while (ct < LIM && gets (entra[ct]) != NULL &&
           strcmp (entra[ct], STOP) != 0) {
        ct++;
    }

    return 0;
}
