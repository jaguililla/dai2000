//clase
#include<stdlib.h>

void main (void)
{
    int clase[30][20], falta[30], dia[20], indice, cont, mayor, alumno, menor,
        fecha;
    clrscr ();
    randomize ();

    for (indice = 0; indice < 30; indice++) {
        falta[indice] = 0;      //voy vaciando falta

        for (cont = 0; cont < 20; cont++) {
            clase[indice][cont] = rand ()%2;

            if (clase[indice][cont] == 0)   //  0 es falta
                falta[indice]++;    //cuento las faltas de cada alumno en los 20 dias
        };
    }

    ;                           //que alumno tiene más faltas
    mayor = falta[0];

    for (indice = 0; indice < 30; indice++) {
        if (falta[indice] > mayor) {
            mayor = falta[indice];
            alumno = indice;
        }
    };

    //dia con menos gente
    for (indice = 0; indice < 20; indice++) {
        dia[indice] = 0;

        for (cont = 0; cont < 30; cont++) {
            if (clase[cont][indice] == 0)
                dia[indice]++;
        };
    };

    menor = dia[0];

    for (indice = 0; indice < 20; indice++) {
        if (dia[indice] < menor)
            fecha = indice;
    }

    printf ("El alumno que más faltas tiene es el %d con %d faltas",
            alumno + 1, mayor);
    printf ("\nEl día con menos gente fue el día %d", fecha + 1);
    getch ();
}
