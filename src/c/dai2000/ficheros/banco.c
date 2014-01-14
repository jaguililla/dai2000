// ACTUALIZA FICHERO

// INCLUDES
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// DEFINES
#define MAXFICH  10
#define MAXSALDO 10000

// TIPOS
typedef struct {
    int ncc, saldo;
} tipo_maestro;

typedef struct {
    int ncc, importe;
} tipo_movs;

// GLOBALES
const char *ruta = "C:\\TC\\BIN\\NUESTROS\\SOURCE\\FICHEROS\\";

const char *ext = ".DAT";

// PROTOTIPOS
void crea_ficheros (char *nom_maestro, char *nom_movs);
void actualiza (char *nom_maestro, char *nom_movs);
void visualiza (char *nomfich);

// FUNCIONES
void crea_ficheros (char *nom_maestro, char *nom_movs)
{
    int cont = 0;
    FILE *maestro, *movs;
    char *aux;
    tipo_maestro registro1;
    tipo_movs registro2;

    // Crea el archivo maestro.dat
    strcpy (aux, ruta);
    strcat (aux, nom_maestro);
    strcat (aux, ext);
    if ((maestro = fopen (aux, "wb")) == NULL) {
        printf ("Error al crear el archivo");
        exit (1);
    }
    // Crea el archivo movs.dat
    strcpy (aux, ruta);
    strcat (aux, nom_movs);
    strcat (aux, ext);
    if ((movs = fopen (aux, "wb")) == NULL) {
        printf ("Error al crear el archivo");
        exit (1);
    }
    for (cont = 0; cont < MAXFICH; cont++) {
        // Escribe registro en maestro.dat
        registro1.ncc = cont + 1;
        registro1.saldo = rand () % MAXSALDO + 1+ 1;
        fwrite (&registro1, sizeof (tipo_maestro), 1, maestro);
        // Escribe registro en movs.dat
        registro2.ncc = rand () % MAXFICH + 1 + 1;
        registro2.importe = rand () % MAXSALDO + 1 + 1;
        fwrite (&registro2, sizeof (tipo_movs), 1, movs);
    }
    fclose (maestro);
    fclose (movs);
}

//////////////////////////////////////////////////////////////////////////////
void actualiza (char *nom_maestro, char *nom_movs)
{
    int cont = 0;
    FILE *maestro = NULL, *movs = NULL;
    char *aux = NULL;
    tipo_maestro registro1;
    tipo_movs registro2;

    // Crea el archivo maestro.dat
    strcpy (aux, ruta);
    strcat (aux, nom_maestro);
    strcat (aux, ext);
    if ((maestro = fopen (aux, "rb")) == NULL) {
        printf ("Error al crear el archivo");
        exit (1);
    }
    // Crea el archivo movs.dat
    strcpy (aux, ruta);
    strcat (aux, nom_movs);
    strcat (aux, ext);
    if ((movs = fopen (aux, "rb")) == NULL) {
        printf ("Error al crear el archivo");
        exit (1);
    }
    for (cont = 0; cont < MAXFICH; cont++)  // Recorre registros de maestro.dat
    {
        // Lee registro en maestro.dat
        fread (&registro1, sizeof (tipo_maestro), 1, maestro);
        for (cont = 0; cont < MAXFICH; cont++)  // Recorre registros de movs.dat
        {
            fread (&registro2, sizeof (tipo_movs), 1, maestro); // Lee de movs.dat
            if (registro1.ncc == registro2.ncc)
                registro1.saldo += registro2.importe;
        }
        fwrite (&registro1, sizeof (tipo_movs), 1, maestro);
    }
    fclose (maestro);
    fclose (movs);
}

//////////////////////////////////////////////////////////////////////////////
void visualiza (char *nomfich)
{
    FILE *fiche;
    tipo_maestro tamano;

    fiche = fopen (nomfich, "rb");
    fread (&tamano, sizeof (tipo_maestro), 1, fiche);
    while (!feof (fiche)) {
        printf ("%2d %d\n", tamano.ncc, tamano.saldo);  //problema con los nombres
        fread (&tamano, sizeof (tipo_maestro), 1, fiche);
    }
    fclose (fiche);
}

//////////////////////////////////////////////////////////////////////////////

// MAIN
void main (void)
{
    clrscr ();
    crea_ficheros ("maestro", "movs");
    visualiza ("maestro");
    getch ();
    visualiza ("movs");
    getch ();
    actualiza ("maestro", "movs");
    visualiza ("maestro");
    getch ();
}

//////////////////////////////////////////////////////////////////////////////
