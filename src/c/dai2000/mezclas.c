//mezcla
#include <stdlib.h>

#include <ctype.h>

#include "ordena.c"

#define N 5
#define M 7

void mezclar (int a[], int b[], int c[])
{
    int cont1 = 0, cont2 = 0, cont3 = 0, indice;

    while ((cont1 < N) && (cont2 < M)) {
        if (a[cont1] <= b[cont2]) {
            c[cont3] = a[cont1];
            cont1++;
        }
        else {
            c[cont3] = b[cont2];
            cont2++;
        }

        cont3++;
    }

    if (cont2 > cont1)
        for (indice = cont1; indice < N; indice++) {
            c[cont3] = a[indice];
            cont3++;
        }
    else
        for (indice = cont2; indice < M; indice++) {
            c[cont3] = b[indice];
            cont3++;
        }
}

void main (void)
{
    int a[N], b[M], c[N + M], oper, indice;
    char resp;

    clrscr ();
    randomize ();
    printf ("\nSeleccione el modo de rellenar las tablas:");
    printf ("\n\t1.- Manualmente.");
    printf ("\n\t2.- Automáticamente.");
    printf ("\nSu selección es: ");

    do {
        scanf ("%d", &oper);

        if ((oper != 1) && (oper != 2))
            printf ("\nIntroduzca un valor correcto.");
    }
    while ((oper != 1) && (oper != 2));

    do {
        switch (oper) {

            case 1:
                printf ("\nIntroduzca los valores de la 1ª tabla: ");

                for (indice = 1; indice <= N; indice++)
                    scanf ("%d", &a[indice]);

                printf ("\nIntroduzca los valores de la 2ª tabla: ");

                for (indice = 1; indice <= M; indice++)
                    scanf ("%d", &b[indice]);

                break;

            case 2:
                for (indice = 0; indice < N; indice++)
                    a[indice] = rand ()%50;

                for (indice = 0; indice < M; indice++)
                    b[indice] = rand ()%50;

                break;
        }

        printf ("Tabla 1:\n");
        ordena_inter (a);
        printf ("\nTabla 2:\n");
        ordena_inter (b);
        printf ("\n");

        for (indice = 0; indice < N; indice++)
            printf ("%d ", a[indice]);

        printf ("\n");

        for (indice = 0; indice < M; indice++)
            printf ("%d ", b[indice]);

        printf ("\n¿Está de acuerdo con los valores de las tablas?(s/n): ");

        resp = getch ();

        resp = tolower (resp);
    }
    while (resp == 'n');

    mezclar (a, b, c);

    printf ("\nEl array resultante es:\n");

    for (indice = 0; indice < (N + M); indice++)
        printf ("%d ", c[indice]);

    getch ();
}
