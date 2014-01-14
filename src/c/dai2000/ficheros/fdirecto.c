  /* fdirecto. operaciones básicas con ficheros de acceso directo */
#include <stdio.h>
#define n 10
int bytesreg = sizeof (int);

void main (void)
{
    FILE *fichero;
    char nomfi[100] = "fdirecto.dat";
    int op, i, nralta, ralta, nrbaja, rbaja, regfi;

    /* inicialización del fichero de acceso directo de enteros */
    clrscr ();
    printf ("\n %50s \n", "CONTENIDO DEL FICHERO");
    fichero = fopen (nomfi, "w+b");
    if (fichero) {

        for (i = 1; i <= n; i++) {
            fseek (fichero, bytesreg * i, SEEK_SET);
            fwrite (0, bytesreg, 1, fichero);
        }

        /* mostrar el fichero de acceso directo */
        for (i = 1; i <= n; i++)
            printf ("%6d", i);
        printf ("\n");
        for (i = 1; i <= n; i++) {
            fseek (fichero, bytesreg * i, SEEK_SET);
            fread (&regfi, bytesreg, 1, fichero);
            printf ("%6d", regfi);
        }
        printf ("\n");
        do {
            printf ("\n 0.-fin  1.-altas  2.-bajas opcion: ");
            scanf ("%d", &op);
            switch (op) {
                case 1:
                    do {
                        printf ("Nº registro de alta: ");
                        scanf ("%d", &nralta);
                    } while (nralta > n || nralta < 0);
                    fseek (fichero, bytesreg * nralta, SEEK_SET);
                    fread (&regfi, bytesreg, 1, fichero);
                    if (regfi)
                        printf ("\a El registro tiene el dato %d\n", regfi);
                    else {
                        regfi = nralta * 10;
                        fseek (fichero, bytesreg * nralta, SEEK_SET);
                        fwrite (&regfi, bytesreg, 1, fichero);
                    }
                    break;
                case 2:
                    do {
                        printf ("Nº registro de baja: ");
                        scanf ("%d", &nrbaja);
                    } while (nrbaja > n || nrbaja < 0);
                    fseek (fichero, bytesreg * nrbaja, SEEK_SET);
                    fread (&regfi, bytesreg, 1, fichero);
                    if (regfi) {
                        printf ("\a El registro tiene el dato %d\n", regfi);
                        fseek (fichero, bytesreg * nrbaja, SEEK_SET);
                        fwrite (0, bytesreg, 1, fichero);
                    }
                    else
                        printf ("\a NO EXISTEN DATOS EN ESTE REGISTRO\n");
                    break;
            }                   /* switch */

            printf ("\n %50s \n", "CONTENIDO DEL FICHERO");
            for (i = 1; i <= n; i++)
                printf ("%6d", i);
            printf ("\n");
            for (i = 1; i <= n; i++) {
                fseek (fichero, bytesreg * i, SEEK_SET);
                fread (&regfi, bytesreg, 1, fichero);
                printf ("%6d", regfi);
            }
            printf ("\n");
        } while (op);
        fclose (fichero);
    }                           /* if(fichero) */

    printf ("secuencial: ");
    fichero = fopen (nomfi, "rb");
    fread (&regfi, bytesreg, 1, fichero);
    while (!feof (fichero)) {
        printf ("%6d", regfi);
        fread (&regfi, bytesreg, 1, fichero);
    }
    fclose (fichero);
    getch ();
}
