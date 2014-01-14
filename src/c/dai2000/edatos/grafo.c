//////////////////////////////////////////////////////////////////////////////
//                                G R A F O                                 //
//////////////////////////////////////////////////////////////////////////////
//  Tarea          : construir la representación enlazada de un grafo en    //
//                   representación matricial                               //
//////////////////////////////////////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>

// D E F I N E S /////////////////////////////////////////////////////////////
#define SI 1                    // Definiciónes para valores booleanos
#define NO 0

#define NODOS 5                 // Nº de nodos del grafo (longitud del array)

// T I P O S /////////////////////////////////////////////////////////////////
typedef struct TipoArista {
    int NodoF;                  // Nodo final de la arista
    int Peso;                   // Peso de la arista
    struct TipoArista *Sig;     // Siguiente arista del nodo
} TipoArista;                   // Lista de las aristas de cada nodo

typedef struct TipoGrafo {
    int Nodo;                   // Nº de nodo
    TipoArista *Arista;         // Lista de las aristas del nodo
    struct TipoGrafo *Sig;      // Siguiente nodo del grafo
} TipoGrafo;                    // Lista de todos los nodos del grafo

// P R O T O T I P O S ///////////////////////////////////////////////////////
void LLenaMatriz (int Matriz[][NODOS]);
void VerMatriz (int Matriz[][NODOS]);
void EnlazaMatriz (int Matriz[][NODOS], TipoGrafo ** Grafo);
int BuscaNodo (TipoGrafo * Grafo, int Nodo, TipoGrafo ** Ant,
               TipoGrafo ** Act);
void AltaNodo (TipoGrafo ** Grafo, int Nodo);
void AltaArista (TipoGrafo ** Grafo, int NodoI, int NodoF, int Peso);
void VerGrafo (TipoGrafo * Grafo);
void VaciaGrafo (TipoGrafo * Grafo);

// F U N C I O N E S /////////////////////////////////////////////////////////
void LLenaMatriz (int Matriz[][NODOS])
{
    int i = 0, j = 0;

    randomize ();
    for (i = 1; i <= NODOS; i++) {
        for (j = 1; j <= NODOS; j++) {
            if (i == j)
                Matriz[i][j] = 0;
            else if (j > i)
                Matriz[i][j] = rand () % 50 + 1 + 1;
            else
                Matriz[i][j] = Matriz[j][i];
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
void VerMatriz (int Matriz[][NODOS])
{
    int i = 0, j = 0;

    printf ("Nº de nodo");
    for (i = 1; i <= NODOS; i++)
        printf ("\t%d", i);
    printf ("\n          ________________________________________-\n");
    for (i = 1; i <= NODOS; i++) {
        printf ("\t%d _\t", i);
        for (j = 1; j <= NODOS; j++) {
            printf ("%d\t", Matriz[i][j]);
        }
        printf ("\n\t  _\n");
    }
}

//////////////////////////////////////////////////////////////////////////////
void EnlazaMatriz (int Matriz[][NODOS], TipoGrafo ** Grafo)
{
    int i = 0, j = 0;

    for (i = 1; i <= NODOS; i++) {
        AltaNodo (Grafo, i);
        for (j = 1; j <= NODOS; j++) {
            if (i != j) {
                AltaArista (Grafo, i, j, Matriz[i][j]);
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
int BuscaNodo (TipoGrafo * Grafo, int Nodo, TipoGrafo ** Ant,
               TipoGrafo ** Act)
{
    int Hallado = NO;

    *Ant = NULL;
    *Act = Grafo;
    while (*Act && !Hallado)    // Mientras no llege al final (*Act) o no
    {                           // encuentre el dato (Hallado=NO)
        if ((*Act)->Nodo >= Nodo) {
            Hallado = SI;
        }
        else {
            *Ant = *Act;
            *Act = (*Act)->Sig;
        }
    }
    if ((*Act)->Nodo == Nodo)
        return (SI);            // Devuelve SI si ha encontrado el elemento
    else
        return (NO);            // Devuelve NO si no ha encontrado el elemento
}

//////////////////////////////////////////////////////////////////////////////
void AltaNodo (TipoGrafo ** Grafo, int Nodo)
{
    TipoGrafo *Nuevo = NULL;    // Memoria para el nuevo nodo
    TipoGrafo *Ant = NULL, *Act = *Grafo;   // Punteros para recorrer grafo

    // Reservo memoria para el nodo
    Nuevo = (TipoGrafo *) malloc (sizeof (TipoGrafo));
    if (!Nuevo) {
        printf ("No hay memoria suficiente");
        getch ();
        exit (1);
    }
    // Asigno los datos al nuevo nodo
    Nuevo->Nodo = Nodo;
    Nuevo->Arista = NULL;
    // Doy de alta el nodo (entre Ant y Act)
    if (*Grafo)                 // Si hay algún elemento
    {
        // Busco la posición donde insertar el nodo
        BuscaNodo (*Grafo, Nodo, &Ant, &Act);
        if (!Ant)               // Si hay que insertar en 1ª posición
        {
            *Grafo = Nuevo;
        }
        else                    // Si hay que insertar entre dos nodos
        {
            Ant->Sig = Nuevo;
        }
        Nuevo->Sig = Act;
    }
    else                        // Si no existe ningún nodo
    {
        *Grafo = Nuevo;
        Nuevo->Sig = NULL;
    }
}

//////////////////////////////////////////////////////////////////////////////
void AltaArista (TipoGrafo ** Grafo, int NodoI, int NodoF, int Peso)
{
    TipoArista *Nuevo = NULL;   // Memoria para la nueva arista
    TipoGrafo *Ant = NULL, *Act = *Grafo;   // Punteros para recorrer grafo
    TipoArista *AntA = NULL, *ActA = NULL;  // Punteros para recorrer aristas

    // A esta función le falta comprobar la existencia del nodo final

    // Reservo memoria para la arista
    Nuevo = (TipoArista *) malloc (sizeof (TipoArista));
    if (!Nuevo) {
        printf ("No hay memoria suficiente");
        getch ();
        exit (1);
    }
    // Asigno los datos a la nueva arista
    Nuevo->NodoF = NodoF;
    Nuevo->Peso = Peso;
    // Doy de alta a la arista
    if (*Grafo)                 // Si hay algún elemento en el grafo
    {
        // Busco el nodo donde insertar la arista
        // Act es un puntero al nodo al que pertenece la arista
        if (BuscaNodo (*Grafo, NodoI, &Ant, &Act)) {
            ActA = Act->Arista; // Cabecera de lista de aristas del nodo
            AntA = NULL;        // Anterior a la cabecera de lista
            if (ActA)           // Si existe alguna arista en el nodo
            {
                while (ActA) {
                    AntA = ActA;
                    ActA = ActA->Sig;
                }
                AntA->Sig = Nuevo;
            }
            else                // No existen aristas en nodo (lista vacia)
            {
                ActA = Nuevo;
            }
            Nuevo->Sig = NULL;
        }
        else                    // No existe el nodo origen, el buscado por BuscaNodo()
        {
            gotoxy (10, 10);
            printf ("No se ha encontrado nodo origen");
            getch ();
        }
    }
    else                        // Si no existe ningún nodo
    {
        gotoxy (10, 10);
        printf ("No hay nodos donde insertar aristas");
        getch ();
    }
}

//////////////////////////////////////////////////////////////////////////////
void VerGrafo (TipoGrafo * Grafo)
{
    TipoGrafo *AuxG = Grafo;    // Puntero auxiliar para recorrer nodos
    TipoArista *AuxA = NULL;    // Puntero auxiliar para recorrer aristas

    while (AuxG) {
        printf ("%2d\t", AuxG->Nodo);   // Visualizo el valor del nodo
        AuxA = AuxG->Arista;
        while (AuxA) {
            printf ("\t%2d %2d", AuxA->NodoF, AuxA->Peso);
            AuxA = AuxA->Sig;
        }
        printf ("\n");
        AuxG = AuxG->Sig;
    }
}

//////////////////////////////////////////////////////////////////////////////

// M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
    int Pesos[NODOS][NODOS];
    TipoGrafo *Raiz = NULL;

    clrscr ();
    LLenaMatriz (Pesos);
    VerMatriz (Pesos);
    getch ();
    EnlazaMatriz (Pesos, &Raiz);
    VerGrafo (Raiz);
    free (Raiz);
    getch ();
}

//////////////////////////////////////////////////////////////////////////////
