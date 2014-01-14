/* yoliga.c */

#include <stdio.h>
#include <stdlib.h>

#define ne 6

struct partido {
    int gc, gv;
};

struct equipo {
    int goles, ptos;
};

void jugar (struct partido p[][ne]);
void iniciar (struct equipo e[]);
void computo (struct partido p[][ne], struct equipo e[]);
void mostrar (struct equipo e[]);

void main (void)
{
    struct partido liga[ne][ne];
    struct equipo equipos[ne];

    randomize ();
    iniciar (equipos);
    jugar (liga);
    computo (liga, equipos);
    mostrar (equipos);
}

void jugar (struct partido p[ne][ne])
{
    int i, j;

    for (i = 0; i < ne; i++) {
        for (j = 0; j < ne; j++) {
            if (i != j) {
                p[i][j].gc = rand ()%5;
                p[i][j].gv = rand ()%5;
                printf ("%d-%d   ", p[i][j].gc, p[i][j].gv);
            }
            else {
                printf ("%c-%c   ", '*', '*');
            }
        }
        printf ("\n");
    }
}                               /* fin generación resultados */

void iniciar (struct equipo e[])
{
    int i;

    for (i = 0; i < ne; i++)
        e[i].goles = e[i].ptos = 0;
}

void computo (struct partido p[][ne], struct equipo e[])
{
    int i, j;

    for (i = 0; i < ne; i++)
        for (j = 0; j < ne; j++)
            if (i != j) {
                e[i].goles = e[i].goles + p[i][j].gc;
                e[j].goles = e[j].goles + p[i][j].gv;
                if (p[i][j].gc > p[i][j].gv)
                    e[i].ptos += 3;
                else if (p[i][j].gc == p[i][j].gv) {
                    e[i].ptos++;
                    e[j].ptos++;
                }
                else
                    e[j].ptos += 3;
            }
}

void mostrar (struct equipo e[])
{
    int maxg, maxp, eqmg, eqmp, i;

    maxg = maxp = 0;
    printf ("equipo     goles     puntos\n");
    for (i = 0; i < ne; i++) {
        if (e[i].goles > maxg) {
            eqmg = i;
            maxg = e[i].goles;
        }
        if (e[i].ptos > maxp) {
            eqmp = i;
            maxp = e[i].ptos;
        }
        printf ("  %d           %d        %d \n", i, e[i].goles, e[i].ptos);
    }
    printf ("equipo con más goles %d.    Goles %d \n", eqmg, maxg);
    printf ("equipo con más puntos %d.   Puntos %d \n", eqmp, maxp);
    getch ();
}

/*Ejecución
   *-*   0-0   1-0   1-1   2-0   3-4
   1-2   *-*   0-3   2-0   0-4   3-3
   4-4   1-2   *-*   4-4   4-4   2-3
   3-2   2-3   0-2   *-*   0-3   2-2
   2-1   4-1   0-2   3-0   *-*   2-3
   3-0   3-1   2-1   1-2   3-1   *-*
   equipo     goles     puntos
     0           16        12
     1           13        11
     2           23        12
     3           14        9
     4           23        16
     5           27        23
     equipo con más goles 5.    Goles 27
     equipo con más puntos 5.   Puntos 23
*/
