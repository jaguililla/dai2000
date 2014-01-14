/* SCREAINT.c FICHERO SECUENCIAL CREA,COPIA Y LISTA FICHERO DE ENTEROS */

// INCLUDES
#include<stdio.h>
#include <stdlib.h>
#define LON 100

// TIPOS
typedef struct {
    char *dni;
    char *nom;
    char *ape;
} reg;

// FUNCIONES
void listar (char nomfi[])
{
    reg i;
    FILE *pf;

    if ((pf = fopen (nomfi, "rb")) == NULL) {
        printf ("Archivo no existe");
        exit (1);
    }
    fread (&i, sizeof (reg), 1, pf);
    while (!feof (pf)) {
        puts (i.dni);
        puts (i.nom);
        puts (i.ape);
        fread (&i, sizeof (reg), 1, pf);
    }
    printf ("\n");
    fclose (pf);
}                               /* LISTAR */

void crear (char nomfi[])
{
    FILE *fichero;
    reg i;
    int ne;

    if ((fichero = fopen (nomfi, "wb")) == NULL) {
        printf ("Error al crear el archivo");
        exit (1);
    }
    printf ("número de elementos: ");
    scanf ("%d%c", &ne);
    while (ne) {
        printf ("Introduce DNI: ");
        scanf ("%s", (i.dni));  // printf ("\n");
        printf ("Introduce nombre: ");
        scanf ("%s", (i.nom));  // printf ("\n");
        printf ("Introduce apellido: ");
        scanf ("%s", (i.ape));  // printf ("\n");
        fwrite (&i, sizeof (reg), 1, fichero);
        ne--;
    }
    printf ("\n");
    fclose (fichero);
}

void main (void)
{
    char nomorigen[LON];

    printf ("Nombre fichero origen: ");
    scanf ("%s", nomorigen);
    crear (nomorigen);
    printf ("fichero origen: ");
    listar (nomorigen);
    printf ("\n");
    getch ();
    remove (nomorigen);
}

/* EJECUCIÓN
Nombre fichero origen: c:\tc\datos\uno.dat
Nombre fichero copia: c:\tc\datos\dos.dat
número de elementos: 6
Alta:  43 Alta:  56 Alta:  18 Alta:  56 Alta:   8 Alta:  56
fichero origen:   43  56  18  56   8  56
fichero copia:   43  56  18  56   8  56
*/
