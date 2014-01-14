// Algoritmo Escalon

// includes
#include <stdio.h>

#include <math.h>

// defines
#define LONGITUD 5
#define ALTURA  3

// globales
int espacios = 0;

// prototipos
void escribe (int num, char ch);
void escalon (int n);

// funciones
void escribe (int num, char ch) // Caracter a imprimir y el número de veces
{
    int indice = 1;

    for (indice; indice <= num; indice++) {
        printf ("%c", ch);
    }
}                               // Fin  blancos()

void escalon (int n)
{
    int cont = 0;
    espacios = n * LONGITUD - 1;
    escribe (LONGITUD, '*');
    printf ("\n");              // Escribe la línea horizontal del escalon

    for (cont = 1; cont <= ALTURA - 1; cont++) {
        escribe (espacios, ' ');
        escribe (LONGITUD - 1, ' ');
        printf ("*\n");         // Escribe la línea vertical del escalón
        espacios += LONGITUD - 1;
    }

    if (espacios <= 80)
        escalon (n + 1);
}                               // Fin  escalon()

               void main (void) {
               }
