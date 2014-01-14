// ALGORITMO SCROLL

// INCLUDES
#include <stdlib.h>
#include <stdio.h>


// PROTOTIPOS
void scroll (char *cad, int limite);

// FUNCIONES
void scroll_der (char *cad, int limite, int y, int color_t, int color_f)
{
    int cont = 0;

    cont = 80 - strlen (cad);

    while (cont > limite) {
        printf ("%s", cad);
        delay (50);
        cont--;
    }
}

void scroll_izq (char *cad, int limite, int y, int color_t, int color_f)
{
    int cont = 0;

    cont = 80 - strlen (cad);

    while (cont > limite) {
        printf ("%s", cad);
        delay (50);
        cont--;
    }
}

void scroll_ar (char *cad, int limite, int y, int color_t, int color_f)
{
    int cont = 0;

    cont = 25;

    while (cont > limite) {
        printf ("%s", cad);
        delay (50);
        cont--;
    }
}

void scroll_ab (char *cad, int limite, int y, int color_t, int color_f)
{
    int cont = 0;

    cont = 80 - strlen (cad);

    while (cont > limite) {
        printf ("%s", cad);
        delay (50);
        cont--;
    }
}

void aleatorio (const char *cad, int retraso)
{
    int condi = 1;

    while (condi) {
        printf ("%s", cad);
        delay (retraso);
    }
}

// MAIN
void main (void)
{
    aleatorio ("Esto es una prueba \x01", 50);
}
