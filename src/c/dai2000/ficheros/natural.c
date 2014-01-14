   /* natural.c Ordenación por mezcla natural */
#include<stdio.h>
#include <stdlib.h>
#define LON 30
#define MAX 1000
int t = sizeof (int), iniciales[MAX], finales[MAX];

void listar (char nf[])
{
    int rant, ract;
    FILE *pf;

    pf = fopen (nf, "rb");
    fread (&rant, t, 1, pf);
    if (!feof (pf)) {
        printf ("%5d", rant);
        fread (&ract, t, 1, pf);
        while (!feof (pf)) {
            if (rant <= ract)
                printf ("%5d", ract);
            else
                printf ("_%4d", ract);
            rant = ract;
            fread (&ract, t, 1, pf);
        }
    }
    printf ("\n");
    fclose (pf);
}                               /*   LISTAR   */

void crear (char nomfi[])
{
    FILE *fichero;
    int i, ne;

    fichero = fopen (nomfi, "wb");
    randomize ();
    printf ("número de elementos: ");
    scanf ("%d", &ne);
    while (ne) {
        i = rand () % MAX;
        iniciales[i]++;         /* CARGA DE CONTADORES INICIALES */
        ne--;
        fwrite (&i, t, 1, fichero);
    }
    /*printf ("\n"); */ fclose (fichero);
}

void dividir (char nf[], char nf1[], char nf2[], int *cambio)
{
    FILE *f, *f1, *f2;
    int rant, ract, enf1;

    f = fopen (nf, "rb");
    f1 = fopen (nf1, "wb");
    f2 = fopen (nf2, "wb");
    fread (&rant, t, 1, f);
    *cambio = 0;
    if (feof (f))
        printf ("FICHERO YA ORDENADO POR ESTAR VACIO\n");
    else {
        enf1 = 1;
        fwrite (&rant, t, 1, f1);
        fread (&ract, t, 1, f);
        while (!feof (f)) {
            if (rant > ract) {
                enf1 = !enf1;
                *cambio = 1;
            }
            if (enf1)
                fwrite (&ract, t, 1, f1);
            else
                fwrite (&ract, t, 1, f2);
            rant = ract;
            fread (&ract, t, 1, f);
        }
    }
    fclose (f);
    fclose (f1);
    fclose (f2);
}                               /*    dividir     */

void mezclar (char nf1[], char nf2[], char nf[])
{
    FILE *f, *f1, *f2;
    int r1, r2, ant1, ant2;

    f1 = fopen (nf1, "rb");
    f2 = fopen (nf2, "rb");
    f = fopen (nf, "wb");
    fread (&r1, t, 1, f1);
    fread (&r2, t, 1, f2);
    while (!feof (f1) && !feof (f2)) {
        ant1 = r1;
        ant2 = r2;
        do {
            if (r1 <= r2) {
                fwrite (&r1, t, 1, f);
                ant1 = r1;
                fread (&r1, t, 1, f1);
            }
            else {
                fwrite (&r2, t, 1, f);
                ant2 = r2;
                fread (&r2, t, 1, f2);
            }
        } while ((!feof (f1)) && (!feof (f2)) && (ant1 <= r1)
                 && (ant2 <= r2));
        if ((ant1 > r1) || feof (f1))
            do {
                fwrite (&r2, t, 1, f);
                ant2 = r2;
                fread (&r2, t, 1, f2);
            } while ((ant2 <= r2) && (!feof (f2)));
        else
            do {
                fwrite (&r1, t, 1, f);
                ant1 = r1;
                fread (&r1, t, 1, f1);
            } while ((ant1 <= r1) && (!feof (f1)));
    }
    if (feof (f1)) {
        if (!feof (f2))
            do {
                fwrite (&r2, t, 1, f);
                fread (&r2, t, 1, f2);
            } while (!feof (f2));
    }
    else {
        do {
            fwrite (&r1, t, 1, f);
            fread (&r1, t, 1, f1);
        } while (!feof (f1));
    }
    fclose (f);
    fclose (f1);
    fclose (f2);
}                               /*  mezclar  */

int iguales (int ini[], int fin[])
{
    int i = MAX - 1;

    while (ini[i] == fin[i] && i > 0)
        i--;
    return (ini[i] == fin[i]);
}

void main (void)
{
    char origen[LON], aux1[LON], aux2[LON];
    FILE *final;
    int datos2, i;
    char seguir;

    clrscr ();
    /* inicializar contadores de datos */
    for (i = 0; i < MAX; i++)
        iniciales[i] = finales[i] = 0;
    strcpy (origen, "f.dat");
    strcpy (aux1, "f1.dat");
    strcpy (aux2, "f2.dat");
    remove (origen);
    remove (aux1);
    remove (aux2);
    do {
        crear (origen);
        dividir (origen, aux1, aux2, &datos2);
        printf ("f= ");
        listar (origen);
        printf ("f1= ");
        listar (aux1);
        printf ("f2= ");
        listar (aux2);

        while (datos2) {
            printf (" ========================================\n");
            mezclar (aux1, aux2, origen);
            dividir (origen, aux1, aux2, &datos2);
            printf ("f= ");
            listar (origen);
            printf ("f1= ");
            listar (aux1);
            printf ("f2= ");
            listar (aux2);
            getch ();
        }
        /* proceso fichero ya ordenado para ver pérdida de datos */
        final = fopen (origen, "rb");
        fread (&i, t, 1, final);
        while (!feof (final)) {
            finales[i]++;
            fread (&i, t, 1, final);
        }
        fclose (final);
        if (iguales (iniciales, finales))
            printf ("fichero inicial ordenado.    OTRA ORDENACIÓN\n");
        else
            printf ("\aAlgo anduvo mal\n");
        seguir = getch ();
    } while (seguir != 'n');

}
