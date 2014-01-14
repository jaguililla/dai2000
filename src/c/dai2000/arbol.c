// A R B O L E S /////////////////////////////////////////////////////////////
// * Operaciones básicas con arboles binarios de busqueda *                 //
//////////////////////////////////////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>



// D E F I N E S /////////////////////////////////////////////////////////////
#define SI 1
#define NO 0

// T I P O S /////////////////////////////////////////////////////////////////

struct nodo {
    int valor;

    struct nodo *izq, *der;
};

typedef struct nodo nodo;

// P R O T O T I P O S ///////////////////////////////////////////////////////
void menu (void);

void buscar (nodo * raiz, int val, nodo ** ant, nodo ** act, int *hallado);
void insertar (nodo ** raiz);
void borrar (nodo ** raiz);

void inorden (nodo * raiz);
void preorden (nodo * raiz);
void postorden (nodo * raiz);

// F U N C I O N E S /////////////////////////////////////////////////////////
void menu (void)
{
    int x = 0, y = 0;

    cprintf ("%35c ARBOLES %36c", 0, 0);
    x = 5;
    y = 4;
    cprintf ("1.-");
    cprintf ("2.-");
    cprintf ("3.-");
    cprintf ("4.-");
    x = 9;
    y = 4;
    cprintf ("Insertar un elemento.");
    cprintf ("Eliminar un elemento.");
    cprintf ("Listar el árbol.");
    cprintf ("Salir.");
}

// Fin menu() ////////////////////////////////////////////////////////////////
void buscar (nodo * raiz, int val, nodo ** ant, nodo ** act, int *hallado)
{
    *hallado = NO;
    *act = raiz;
    *ant = NULL;

    while (*act && !(*hallado)) {
        if (val == (*act)->valor)
            *hallado = SI;
        else {
            *ant = *act;

            if (val < (*act)->valor)
                *act = (*act)->izq;
            else if (val > (*act)->valor)
                *act = (*act)->der;
        }
    }
}

// Fin buscar() //////////////////////////////////////////////////////////////
void insertar (nodo ** raiz)
{
    nodo *nuevo;
    nodo *ant, *act;
    int hallado = NO;

    // Reserva memoria para el nuevo elemento e inicializa sus enlaces
    nuevo = (nodo *) malloc (sizeof (nodo));

    if (!nuevo) {
        gotoxy (20, 10);
        printf ("No hay suficiente memoria disponible");
        exit (1);
    }

    nuevo->izq = NULL;
    nuevo->der = NULL;
    // Comprueba q el elemento no existe y devuelve su posición de inserción
    gotoxy (10, 10);

    do {
        printf ("Introduce el valor a insertar: ");
        scanf ("%d", &(nuevo)->valor);
        buscar (*raiz, nuevo->valor, &ant, &act, &hallado);

        if (hallado) {
            printf ("¡¡¡ El valor introducido ya existe !!!\n");
        }
    }
    while (hallado);

    // Conecta el nuevo elemento en el subárbol del nodo correspondiente
    if (ant)                    // árbol con algún elemento
    {

        if (nuevo->valor > ant->valor)
            ant->der = nuevo;
        else
            ant->izq = nuevo;
    }
    else {                      // árbol vacio
        *raiz = nuevo;
    }
}

// Fin inserta() /////////////////////////////////////////////////////////////
void borrar (nodo ** raiz)
{
    nodo *ant = NULL, *act = NULL;
    int valor = 0, hallado = NO;

    do {
        gotoxy (10, 10);
        printf ("Introduce el valor a eliminar: ");
        scanf ("%d", &valor);
        buscar (*raiz, valor, &ant, &act, &hallado);

        if (hallado)
            printf ("¡¡¡ El valor introducido ya existe !!!");
    }
    while (hallado);
}

// Fin borrar () //////////////////////////////////////////////////////////////
void inorden (nodo * raiz)
{
    nodo *aux = raiz;

    if (aux) {
        inorden (aux->izq);
        printf ("%d ", aux->valor);
        inorden (aux->der);
    }
}

// Fin inorden() /////////////////////////////////////////////////////////////

// M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
    nodo *arbol = NULL;
    int opcion = 0, salir = NO;

    do {
        menu ();
        opcion = getch ();

        switch (opcion) {

            case '1':
                insertar (&arbol);
                break;

            case '2':
                //    borrar (arbol);
                break;

            case '3':
                inorden (arbol);
                break;

            case '4':
                salir = SI;
                break;

            default:
                cprintf ("Opción no valida, pulse una tecla.");
                break;
        }
    }
    while (!salir);

    free (arbol);
}

//nº de nodos
int cont;

void nodos (struct nodo *raiz)
{
    cont++;

    if (raiz->izq)
        nodos (raiz->izq);

    if (raiz->der)
        nodos (raiz->der);
}

//nº de hojas

void hojas (struct nodo *raiz)
{
    if ((raiz->izq == NULL) && (raiz->der)) {
        printf ("%d ", raiz->valor);
        cont++;
    }

    if (raiz->izq)
        hojas (raiz->izq);

    if (raiz->der)
        hojas (raiz->der);
}
/////////////////////////////// EOF "arbol.c" ////////////////////////////////
