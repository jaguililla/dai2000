// ALGORITMO CADENAS

// INCLUDES
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// DEFINES
#define N 10

// PROTOTIPOS
int strcmp_ (char *cad1, char *cad2);
int cuenta (char *cad1);
void escribe (char *cad1);

// FUNCIONES
int strcmp_ (char *cad1, char *cad2)
{
    while (*cad1 || *cad2) {
        if (*cad1 < *cad2)
            return (-1);
        else if (*cad1 > *cad2)
            return (1);

        cad1++;

        cad2++;
    }

    return (0);
}

int strcmp__ (char cad1[], char cad2[])
{
    int cont = 0;

    while (cad1[cont] != 0 || cad2[cont] != 0) {
        if (cad1[cont] < cad2[cont])
            return (-1);
        else if (cad1[cont] > cad2[cont])
            return (1);

        cont++;
    }

    return (0);
}

int cuenta (char *cad1)
{
    int indice, palabras = 1;

    //for(indice=0;indice<N;cad1++,indice++)

    while (*cad1) {
        if (*cad1 == ' ')
            palabras++;

        cad1++;
    }

    return (palabras);
}

void escribe (char *cad1)
{
    int indice;

    //for(indice=0;indice<N;indice++,cad1++)

    while (*cad1) {
        if (*cad1 == ' ')
            printf ("\n");
        else
            printf ("%c", *cad1);

        cad1++;
    }
}

void larga (char *cad1)
{
    int lp = 0, lpmayor = 0, npmayor = 0, np = 0;

    while (*cad1) {
        lp++;

        if (*cad1 == ' ') {
            lp--;
            np++;

            if (lpmayor < lp) {
                lpmayor = lp;
                npmayor = np;
            }

            lp = 0;
        }

        cad1++;
    }

    printf ("La palabra mas larga es la %dª con %d letras", npmayor, lpmayor);
}

// MAIN
void main (void)
{
    char cadena1[10];

    clrscr ();
    printf ("Introduzca la cadena: ");
    gets (cadena1);
    printf ("El número de palabras es %d\n", cuenta (cadena1));
    escribe (cadena1);
    larga (cadena1);
    getch ();
}
