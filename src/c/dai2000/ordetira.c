/* ordetira.c -- lectura y clasificación de tiras */
#include <stdio.h>
#include <string.h>
#define TAM 81                  /* límite longitud tira contando \0 */
#define LIM 20                  /* número máximo de tiras a leer */
#define PARA ""                 /* tira nula para detener entrada */
void ordenatira (char *tiras[], int num);

/* función de ordenación de tiras */
int main (void)
{
    static char entra[LIM][TAM];    /* array para entrada */
    char *ptira[LIM];           /* array de variables puntero */
    int ct = 0;                 /* contador de entrada */
    int k;                      /* contador de salida */

    printf ("Introduzca hasta %d líneas y las ordenará.\n", LIM);
    printf ("Para acabar, pulse [Intro] al comienzo de línea.\n");

    while (ct < LIM && gets (entra[ct]) != NULL &&
           strcmp (entra[ct], PARA) != 0) {
        ptira[ct] = entra[ct];  /* asigna punteros a las tiras */
        ct++;
    }

    ordenatira (ptira, ct);     /* clasificador de tiras */
    puts ("\nAhí va la lista ordenada:\n");

    for (k = 0; k < ct; k++)
        puts (ptira[k]);        /* tiras ordenadas */

    return 0;
}

/* clasificador de tiras por punteros */
void ordenatira (char *tiras[], int num) {
    char *temp;
    int tope, busca;

    for (tope = 0; tope < num - 1; tope++)
        for (busca = tope + 1; busca < num; busca++)
            if (strcmp (tiras[tope], tiras[busca]) > 0) {
                temp = tiras[tope];
                tiras[tope] = tiras[busca];
                tiras[busca] = temp;
            }
}
