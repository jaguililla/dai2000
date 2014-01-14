/* bajalta0.c */
#include <stdio.h>

#define N 5

void listar (int v[], int t)
{
    int i;

    for (i = 0; i < t; i++)
        printf ("%4d", v[i]);

    printf ("\n");
}

void altas (int v[], int *t, int valta)
{
    int i, j;

    if (*t == N)
        printf ("\no hay espacio disponible\n");
    else {
        for (i = *t - 1; i >= 0; i--)
            if (v[i] > valta)
                v[i + 1] = v[i];
            else
                break;

        v[i + 1] = valta;

        (*t)++;
    }

    listar (v, *t);
}

void bajas (int v[], int *t, int vbaja)
{
    int i, j;

    if (*t == 0)
        printf ("no hay datos\n");
    else {
        for (i = 0; i < *t; i++)
            if (v[i] >= vbaja)
                break;

        if (v[i] == vbaja) {
            for (j = i; j < *t - 1; j++)
                v[j] = v[j + 1];

            (*t)--;
        }
        else
            printf ("%d no existe\n", vbaja);
    }

    listar (v, *t);
}

void main (void)
{
    int v[N], valta, vbaja, total = 0, opcion;

    clrscr ();

    do {
        printf ("0.-salir   1.-altas   2.-bajas  Introduzca opción: ");
        scanf ("%d", &opcion);

        switch (opcion) {

            case 1:
                printf ("Introduzca valor alta: ");
                scanf ("%d", &valta);
                altas (v, &total, valta);
                break;

            case 2:
                printf ("Introduzca valor baja: ");
                scanf ("%d", &vbaja);
                bajas (v, &total, vbaja);
                break;
        }

        printf ("Pulse tecla...\n");
        getch ();
    }
    while (opcion);
}
