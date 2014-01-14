    /* sactuali. FICHERO DE CUENTAS CORRIENTES */
#include <stdio.h>
#include <stdlib.h>
#define lon 64
typedef struct {
    int ncc, saldo;
} rmae;
typedef struct {
    int ncc, impor;
} rmovi;
int lrmae = sizeof (rmae), lrmovi = sizeof (rmovi);

void crearmae (char *nf)
{
    FILE *pf;
    rmae r;

    pf = fopen (nf, "wb");
    do {
        printf ("cuenta: ");
        scanf ("%d", &r.ncc);
        if (r.ncc) {
            printf ("saldo: ");
            scanf ("%d", &r.saldo);
            fwrite (&r, lrmae, 1, pf);
        }
    } while (r.ncc);
    fclose (pf);
}      /************************/
void crearmovi (char *nf)
{
    FILE *pf;
    rmovi r;

    pf = fopen (nf, "wb");
    do {
        printf ("cuenta: ");
        scanf ("%d", &r.ncc);
        if (r.ncc) {
            printf ("importe: ");
            scanf ("%d", &r.impor);
            fwrite (&r, lrmovi, 1, pf);
        }
    } while (r.ncc);
    fclose (pf);
}      /************************/
void listarmae (char *nf)
{
    FILE *pf;
    rmae r;

    pf = fopen (nf, "rb");
    fread (&r, lrmae, 1, pf);
    while (!feof (pf)) {
        printf ("(%d,%d) ", r.ncc, r.saldo);
        fread (&r, lrmae, 1, pf);
    };
    printf ("\n");
    fclose (pf);
}   /**********************/
void listarmovi (char *nf)
{
    FILE *pf;
    rmovi r;

    pf = fopen (nf, "rb");
    fread (&r, lrmovi, 1, pf);
    while (!feof (pf)) {
        printf ("(%d,%d)", r.ncc, r.impor);
        fread (&r, lrmovi, 1, pf);
    };
    printf ("\n");
    fclose (pf);
}      /************************/
void mezclar (char *maes, char *movi, char *maeactu, char *errores)
{
    FILE *pfmae, *pfmovi, *pfmaeactu, *pferrores;
    rmae regmaes;
    rmovi regmovi;

    pfmae = fopen (maes, "rb");
    pfmovi = fopen (movi, "rb");
    pfmaeactu = fopen (maeactu, "wb");
    pferrores = fopen (errores, "wb");
    fread (&regmaes, lrmae, 1, pfmae);
    fread (&regmovi, lrmovi, 1, pfmovi);
    while ((!feof (pfmae)) && (!feof (pfmovi)))
        if (regmaes.ncc < regmovi.ncc) {
            fwrite (&regmaes, lrmae, 1, pfmaeactu);
            fread (&regmaes, lrmae, 1, pfmae);
        }
        else if (regmaes.ncc == regmovi.ncc) {
            regmaes.saldo += regmovi.impor;
            fread (&regmovi, lrmovi, 1, pfmovi);
        }
        else { /* maestro mayor que movimientos */ ;
            fwrite (&regmovi, lrmovi, 1, pferrores);
            fread (&regmovi, lrmovi, 1, pfmovi);
        }

    if (feof (pfmae))           /* fin del fichero maestro */
        while (!feof (pfmovi)) {
            fwrite (&regmovi, lrmovi, 1, pferrores);
            fread (&regmovi, lrmovi, 1, pfmovi);
        }
    else                        /* fin de movimientos */
        do {
            fwrite (&regmaes, lrmae, 1, pfmaeactu);
            fread (&regmaes, lrmae, 1, pfmae);
        } while (!feof (pfmae));
    fclose (pfmae);
    fclose (pfmovi);
    fclose (pfmaeactu);
    fclose (pferrores);
}    /**********************/

void main (void)
{
    char mae[lon], movi[lon], maeactu[lon], errores[lon];

    clrscr ();
    strcpy (mae, "maestro");
    strcpy (movi, "movimi");
    strcpy (maeactu, "maeactu");
    strcpy (errores, "errores");
    printf ("\nCREACIÓN MAESTRO\n");
    crearmae (mae);
    printf ("\nCREACIÓN MOVIMIENTOS\n");
    crearmovi (movi);
    mezclar (mae, movi, maeactu, errores);
    printf ("\nMAESTRO: ");
    listarmae (mae);
    getch ();
    printf ("\nMOVIMIENTOS: ");
    listarmovi (movi);
    getch ();
    printf ("\nMAESTRO ACTUALIZADO: ");
    listarmae (maeactu);
    getch ();
    printf ("\nERRORES: ");
    listarmovi (errores);
    printf ("\nFIN DE PROGRAMA...");
    getch ();
    remove (mae);
    remove (movi);
    remove (maeactu);
    remove (errores);
}
