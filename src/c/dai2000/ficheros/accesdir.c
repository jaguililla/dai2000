// FICHERO DE ACCESO DIRECTO

// INCLUDES
#include <stdlib.h>
#include <stdio.h>


// DEFINES
#define NREGS 10                // Nº de registros de la zona principal
#define SI 1
#define NO 0

// MACROS
#define pos(CLAVE) ((CLAVE%NREGS)+1)
#define NCOL (NREGS*30)/100

// TIPOS
typedef struct {
    int activo;
    int clave;
    int dato;
    int colision;
} tiporeg;                      // Tipo de un registro

// PROTOTIPOS
void inicia (char *nomfich);
void alta (char *nomfich);
void baja (char *nomfich);
void lista (char *nomfich);

// FUNCIONES
void inicia (char *nomfich)
{
    FILE *fiche;
    tiporeg regaux;
    int cont = 0;

    fiche = fopen (nomfich, "wb");
    regaux.activo = NO;
    regaux.clave = 0;
    regaux.dato = 0;
    regaux.colision = NREGS + 1;
    fwrite (&regaux, sizeof (tiporeg), 1, fiche);
    for (cont = 1; cont <= NREGS + NCOL; cont++) {
        if (cont > NREGS)
            regaux.colision = cont + 1;
        fwrite (&regaux, sizeof (tiporeg), 1, fiche);
    }
}

//////////////////////////////////////////////////////////////////////////////
void alta (char *nomfich)
{
    tiporeg index, regalta, regaux;
    int posi;
    FILE *fiche;

    fiche = fopen (nomfich, "r+b"); // Abre fichero
    fread (&index, sizeof (tiporeg), 1, fiche); // Lee el registro indice
    printf ("Introduzca la clave y el dato: "); // Introduce valores registro
    scanf ("%d %d", &regaux.clave, &regaux.dato);
    posi = pos (regaux.clave);  // Calcula posición de clave
    // Lee el registro con esa clave (en la posición posi)
    if (index.colision)         // Si no está lleno
    {
        fseek (fiche, posi * sizeof (tiporeg), SEEK_SET);
        fread (&regalta, sizeof (tiporeg), 1, fiche);
        while (regalta.activo)  // Si esa posición está activa
        {
            fseek (fiche, posi * sizeof (tiporeg), SEEK_SET);
            fread (&regalta, sizeof (tiporeg), 1, fiche);
            posi = regalta.colision;    // Lee la sgte colision
        }
//indica en el registro 0 que da uno de alta
        index.colision = regalta.colision;
        fseek (fiche, 0, SEEK_SET);
        fwrite (&index, sizeof (tiporeg), 1, fiche);
//indica cual es si siguiente en la zona de colision
        regalta.colision = index.colision;
        fseek (fiche, posi * sizeof (tiporeg), SEEK_SET);
        fwrite (&regalta, sizeof (tiporeg), 1, fiche);
//arregla el struct y lo graba
        regalta.activo = SI;
        regalta.clave = regaux.clave;
        regalta.dato = regaux.dato;
        regalta.colision = 0;
        fseek (fiche, index.colision * sizeof (tiporeg), SEEK_SET);
        fwrite (&regalta, sizeof (tiporeg), 1, fiche);
        // Escribe el registro
    }
    else                        // Si está lleno
    {
        printf ("El fichero está lleno");
    }
    fclose (fiche);
}

//////////////////////////////////////////////////////////////////////////////
void baja (char *nomfich)
{
    FILE *fiche;
    int aux, posi;
    tiporeg reg;

    fiche = fopen (nomfich, "r+b");
    printf ("Introduzca la clave que quiere dar de baja: ");
    scanf ("%d", &aux);
    posi = pos (aux);
    fseek (fiche, posi * sizeof (tiporeg), SEEK_SET);
    fread (&reg, sizeof (tiporeg), 1, fiche);
    while ((aux != reg.clave) && (reg.colision)) {
        fseek (fiche, reg.colision * sizeof (tiporeg), SEEK_SET);
        fread (&reg, sizeof (tiporeg), 1, fiche);
    }
    if (reg.colision == 0)
        printf ("La clave no existe.");
    if (aux == reg.clave) {
        //dar de baja

        printf ("El dato ha sido dado de baja.");
    }
    getch ();
}

//////////////////////////////////////////////////////////////////////////////
void listar (char *nomfich)
{
}

//////////////////////////////////////////////////////////////////////////////
void main (void)
{
    int op;
    FILE *fiche;

    fiche = fopen ("accesso.dat", "wb");
    fclose ("accesso.dat");
    clrscr ();
    do {
        printf ("INTRODUZCA UNA OPCION: ");
        printf ("0.-FIN\n    1.-ALTAS\n    2.-BAJAS\n    3.-LISTADO\n");
        scanf ("%d", &op);
        switch (op) {
            case 1:
                alta ("accesso.dat");
                printf ("El dato ha sido dado de alta.");
                getch ();
                break;
            case 2:
                baja ("accesso.dat");
                break;
            case 3:
                listar ("accesso.dat");
                break;
        }
    } while (op);
    remove ("accesso.dat");
}
