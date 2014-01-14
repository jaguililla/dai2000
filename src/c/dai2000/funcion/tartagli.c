// Pirámide de números
#include<stdlib.h>


// Prototipos
void blancos (int num);
void numeros (int num);         // Recursiva

// Global
int cont = 1;

// Funciones
void blancos (int num)          // Recibe el número de blancos a imprimir
{
    int indice = 1;

    for (indice; indice <= num; indice++) {
        printf (" ");
    }
}                               // Fin  blancos()

void numeros (int blan)
{
    int indice = 1;

    blancos (blan);
    for (indice; indice <= cont; indice++) {
        printf ("%d", indice % 10); // Para que en vez de 10 escriba 0
    }
    for (indice = cont - 1; indice >= 1; indice--) {
        printf ("%d", indice % 10);
    }
    printf ("\n");
    cont++;
    if (blan == 0)
        return;
    else {
        blan--;
        numeros (blan);
    }
}                               // Fin  numeros()

void main (void)
{
    int blan = 9;

    clrscr ();
    numeros (blan);
    getch ();
}
