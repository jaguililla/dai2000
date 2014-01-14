#include<stdlib.h>


#define N 15

int main (void) {
    struct goles {
        int gc, gv;
    };
    int indice, cont, lider[N], mayor;
    char letra;
    struct goles marca[N][N];

    randomize ();
    for (indice = 0; indice < N; indice++)
        lider[indice] = 0;
    printf ("   ");
    for (letra = 65; letra <= 65 + N - 1; letra++)
        printf ("%c    ", letra);
    for (indice = 0, letra = 65; indice < N; indice++, letra++) {
        printf ("\n%c  ", letra);
        for (cont = 0; cont < N; cont++) {
            if (indice != cont) {
                marca[indice][cont].gc = rand ()%5;
                marca[indice][cont].gv = rand ()%rand ()%7;
                printf ("%d-%d  ", marca[indice][cont].gc,
                        marca[indice][cont].gv);
                if (marca[indice][cont].gc == marca[indice][cont].gv) {
                    lider[indice]++;
                    lider[cont]++;
                }
                else {          //casa es indice
                    if (marca[indice][cont].gc > marca[indice][cont].gv)
                        lider[indice] += 3;
                    else
                        lider[cont] += 3;
                }
            }
            else
                printf (">>>");

        }
    }
    mayor = 0;
    for (cont = 1; cont < N; cont++)
        if (lider[mayor] < lider[cont])
            mayor = cont;
    printf ("\n\nEl lider es el equipo %c con %d puntos", mayor + 65, lider[mayor]);
    getch ();
}
