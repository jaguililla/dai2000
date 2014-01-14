// A G E N D A /////////////////////////////////////////////////////
// * Agenda que asigna memoria dinamicamente para cada registro * //
////////////////////////////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// D E F I N E S /////////////////////////////////////////////////////////////
#define SI 1
#define NO 0
// Parametros de registros
#define MAXNOM 20
#define MAXAPE 20
#define MAXDIR 30
#define MAXTLF 10

// E S T R U C T U R A S  /  T Y P E D E F S /////////////////////////////////

struct nodo {
    char nom[MAXNOM];
    char ape[MAXAPE];
    char dir[MAXDIR];
    char tlf[MAXTLF];
    int edad;

    struct nodo *sgte;
};

typedef struct nodo persona;

// G L O B A L E S ///////////////////////////////////////////////////////////
persona *agenda = NULL;

// P R O T O T I P O S ///////////////////////////////////////////////////////
persona *busca (persona person);    // Devuelve punt. a pos anterior a person
persona pide (void);            // LLamada en el parametro de alta
void alta (persona entrada);
void baja (persona salida);
void modifica (persona antes, persona despues);
void lista (void);

// F U N C I O N E S /////////////////////////////////////////////////////////
persona *busca (persona person)
{
    persona *aux = agenda;
    persona *ant = NULL;
    int hallado = NO;

    while ((aux != NULL) && (!hallado)) {
        if (strcmp (person.nom, aux->nom) == 0 &&
            strcmp (person.ape, aux->ape) == 0 &&
            strcmp (person.dir, aux->dir) == 0 &&
            strcmp (person.tlf, aux->tlf) == 0 && person.edad == aux->edad) {
            hallado = SI;       // La posición a insertar ha sido hallada
        }
        else {
            ant = aux;
            aux = aux->sgte;    // Si la pos no hallada avanza puntero
        }
    }

    if (hallado)
        return (ant);
    else
        return (NULL);
}

// Fin busca() ///////////////////////////////////////////////////////////////
persona pide (void)
{
    persona datos;
    int estan = NO;

    do {
        estan = NO;
        cprintf ("Introduce el nombre: ");
        gets (datos.nom);
        cprintf ("Introduce los apellidos: ");
        gets (datos.ape);
        cprintf ("Introduce la dirección: ");
        gets (datos.dir);
        cprintf ("Introduce el teléfono: ");
        gets (datos.tlf);
        cprintf ("Introduce la edad: ");
        scanf ("%d%c", &datos.edad);
        datos.sgte = NULL;

        if (busca (datos) != NULL) {
            estan = SI;
            cprintf ("Ese registro ya existe");
        }
    }
    while (estan);
    return (datos);
}

// Fin pide() ////////////////////////////////////////////////////////////////
void alta (persona entrada)
{
    persona *nuevo = NULL;
    persona *aux = agenda;      // aux apunta al primer elemento de la lista
    int hallado = NO;

    nuevo = (persona *) malloc (sizeof (persona));

    if (nuevo == NULL)          // Error alojando memoria
    {
        gotoxy (30, 12);
        cprintf ("No hay suficiente memoria");
        exit (1);
    }
    if (agenda == NULL)         // Agenda vacia
    {
        agenda = nuevo;
        nuevo->sgte = NULL;
        strcpy (nuevo->nom, entrada.nom);
        strcpy (nuevo->ape, entrada.ape);
        strcpy (nuevo->dir, entrada.dir);
        strcpy (nuevo->tlf, entrada.tlf);
        nuevo->edad = entrada.edad;
    }
    else                        // Agenda no vacia
    {
        while ((aux->sgte != NULL) && (!hallado)) {
            // Si pos anterior es <, y pos sgte es > q entrada o NULL

            if ((strcmp (aux->nom, entrada.nom) < 0) &&
                (strcmp (aux->sgte->nom, entrada.nom) > 0)) {
                hallado = SI;   // La posición a insertar ha sido hallada
            }
            else {
                aux = aux->sgte;    // Si la pos no hallada avanza puntero
            }
        }

        nuevo->sgte = aux->sgte;
        aux->sgte = nuevo;
        strcpy (nuevo->nom, entrada.nom);
        strcpy (nuevo->ape, entrada.ape);
        strcpy (nuevo->dir, entrada.dir);
        strcpy (nuevo->tlf, entrada.tlf);
        nuevo->edad = entrada.edad;
    }
}

// Fin alta() ////////////////////////////////////////////////////////////////
void baja (persona salida)
{
    persona *aux = agenda;
    persona *ant = NULL;

    if (agenda == NULL) {
        gotoxy (30, 12);
        cprintf ("La agenda está vacia");
    }
    else {
        ant = busca (salida);
        aux = ant->sgte;
        ant->sgte = aux->sgte;
        free (aux);
    }
}

// Fin baja() ////////////////////////////////////////////////////////////////
void modifica (persona antes, persona despues)
{
}

// Fin modifica() ////////////////////////////////////////////////////////////

void lista (void)
{
    persona *aux = agenda;
    int y = 6;

    gotoxy (5, 5);
    cprintf ("Nombre    Apellidos    Dirección    Teléfono    Edad");

    while (aux->sgte != NULL) {
        gotoxy (5, y);
        cprintf ("%10s", aux->nom);
        gotoxy (5, y);
        cprintf ("%10s", aux->ape);
        gotoxy (5, y);
        cprintf ("%10s", aux->dir);
        gotoxy (5, y);
        cprintf ("%10s", aux->tlf);
        gotoxy (5, y);
        cprintf ("%2d", aux->edad);
        gotoxy (5, y);
        aux = aux->sgte;
        y++;
    }
}

// Fin lista() ///////////////////////////////////////////////////////////////

// M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
    int salir = NO;
    char op = '\0';

    cprintf ("A G E N D A");
    cprintf ("1.- Añadir registro.");
    cprintf ("2.- Eliminar registro.");
    cprintf ("3.- Modificar registro.");
    cprintf ("4.- Mostrar listado.");
    cprintf ("5.- Salir.");

    do {
        op = getch ();

        switch (op) {

            case '1':
                alta (pide ());
                break;

            case '2':
                //    baja ();
                break;

            case '3':
                //    modifica ();
                break;

            case '4':
                lista ();

            case '5':
                salir = SI;
                break;

            default:
                printf ("Opción no valida");
                break;
        }
    }
    while (!salir);
}
/////////////////////////////// EOF "AGENDA.C" ///////////////////////////////
