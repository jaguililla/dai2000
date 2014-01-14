//multiplicar
#include<stdlib.h>

#define M 11
void main (void)
{
    int tabla[M][M], indice, cont, pos1, pos2;

    clrscr ();
    randomize ();

    for (indice = 0; indice < M; indice++) {
        pos1 = indice - 1;

        for (cont = 0; cont < M; cont++) {
            pos2 = cont - 1;

            if ((pos1 == -1) && (pos2 == -1))
                printf ("*  ");
            else
                printf ("%d  ", abs (pos1 * pos2));
        };

        printf ("\n");
    };

    getch ();
}
