   /* SCREAINT.c FICHERO SECUENCIAL CREA,COPIA Y LISTA FICHERO DE ENTEROS */
#include<stdio.h>
#include <stdlib.h>
#define LON 100
int t = sizeof (int);

void listar (char *nomfi)
{
    int i;
    FILE *pf;

    pf = fopen (nomfi, "rb");
    fread (&i, t, 1, pf);
    while (!feof (pf)) {
        printf ("%4d", i);
        fread (&i, t, 1, pf);
    }
    printf ("\n");
    fclose (pf);
}                               /* LISTAR */

void crear (char nomfi[])
{
    FILE *fichero;
    int i, ne;

    fichero = fopen (nomfi, "wb");
    randomize ();
    printf ("número de elementos: ");
    scanf ("%d", &ne);
    while (ne) {
        i = rand () % 100 + 1;
        printf ("Alta: %3d\n", i);
        ne--;
        fwrite (&i, t, 1, fichero);
    }
    printf ("\n");
    fclose (fichero);
}

void copiar (char *nomorigen, char *nomcopia)
{
    FILE *forigen, *fcopia;
    int i;

    forigen = fopen (nomorigen, "rb");
    fcopia = fopen (nomcopia, "wb");
    fread (&i, t, 1, forigen);
    while (!feof (forigen)) {
        fwrite (&i, t, 1, fcopia);
        fread (&i, t, 1, forigen);
    };
    fclose (forigen);
    fclose (fcopia);
}
void main (void)
{
    char nomorigen[LON], nomcopia[LON];

    printf ("Nombre fichero origen: ");
    gets (nomorigen);
    printf ("Nombre fichero copia: ");
    gets (nomcopia);
    crear (nomorigen);
    printf ("fichero origen: ");
    listar (nomorigen);
    printf ("\n");
    copiar (nomorigen, nomcopia);
    printf ("fichero copia: ");
    listar (nomcopia);
    printf ("\n");
    getch ();
    remove (nomorigen);
    remove (nomcopia);
}

/* EJECUCIÓN
Nombre fichero origen: c:\tc\datos\uno.dat
Nombre fichero copia: c:\tc\datos\dos.dat
número de elementos: 6
Alta:  43 Alta:  56 Alta:  18 Alta:  56 Alta:   8 Alta:  56
fichero origen:   43  56  18  56   8  56
fichero copia:   43  56  18  56   8  56
*/
