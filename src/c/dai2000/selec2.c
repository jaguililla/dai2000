#include<stdlib.h>

#define N 5
void main (void)
{
    int valor[N], indice = N, contador, cont2, menor, cont, pos, aux;

    clrscr ();
    randomize ();
    //printf ("Introduce los datos: ");

    for (contador = 0; contador < indice; contador++) {
        valor[contador] = rand()%30;
        // scanf ("%d",&valor[contador]);
    }

    for (contador = 0; contador < indice - 1; contador++) {
        menor = valor[contador];
        pos = contador;

        for (cont2 = (contador + 1); cont2 < indice; cont2++) {
            if (valor[cont2] > menor) {
                menor = valor[cont2];
                pos = cont2;
            }
        };

        aux = valor[contador];

        valor[contador] = menor;

        valor[pos] = aux;

        for (cont = 0; cont < N; cont++)
            printf ("%d\t", valor[cont]);

        printf ("\n");
    }

    printf ("La tabla ordenada es:\n");

    for (cont = 0; cont < indice; cont++)
        printf ("%d ", valor[cont]);

    getch ();
}
