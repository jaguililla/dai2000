//////////////////////////////////////////////////////////////////////////////
//                               E D A T O S                                //
//////////////////////////////////////////////////////////////////////////////
//  Tarea          : operaciones básicas con estructuras dinamicas de       //
//                   datos: colas, pilas y listas                           //
//////////////////////////////////////////////////////////////////////////////
//  Autor          : Juan José Aguililla                                    //
//  Desarrollado el: 25.5.1999                                              //
//  Última Revisión: 25.5.1999                                              //
//  Versión        : 0.0                                                    //
//////////////////////////////////////////////////////////////////////////////
//  Notas          :                                                        //
//////////////////////////////////////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>

// D E F I N E S /////////////////////////////////////////////////////////////
#define SI 1                    // Definición para valores booleanos
#define NO 0                    // Idem

// T I P O S /////////////////////////////////////////////////////////////////
typedef struct T_EDatos         // Tipo de datos de cada elemento, es
{                               // común para todas las estructuras
    int Datos;                  // Campo con el dato (entero)
    struct T_EDatos *Sig;       // Campo que apunta al siguiente nodo
} T_EDatos;

// P R O T O T I P O S ///////////////////////////////////////////////////////
// COLAS
void AltaCola (T_EDatos ** FCola, int Datos);
int BajaCola (T_EDatos ** FCola, int *Datos);
void ImpCola (T_EDatos * FCola);

// PILAS
void AltaPila (T_EDatos ** PPila, int Datos);
int BajaPila (T_EDatos ** PPila, int *Datos);
void ImpPila (T_EDatos * PPila);

// LISTAS
int BuscaLista (T_EDatos * PLista, int Datos, T_EDatos ** Ant,
                T_EDatos ** Act);
void AltaLista (T_EDatos ** PLista, int Datos);
int BajaLista (T_EDatos ** PLista, int Datos);
void ImpLista (T_EDatos * PLista);

// MENUS
void MenuCola (void);
void MenuPila (void);
void MenuLista (void);

// F U N C I O N E S /////////////////////////////////////////////////////////
void AltaCola (T_EDatos ** FCola, int Datos)
{
    T_EDatos *Nuevo = NULL;     // Memoria para el nuevo nodo

    // Reservo memoria para el nodo
    Nuevo = (T_EDatos *) malloc (sizeof (T_EDatos));
    if (!Nuevo) {
        printf ("No hay memoria suficiente");
        getch ();
        exit (1);
    }
    // Asigno los datos al nuevo nodo
    Nuevo->Datos = Datos;
    // Enlazo el nodo en la cola
    if (*FCola)                 // Si la cola no está vacia
    {
        Nuevo->Sig = (*FCola)->Sig;
        (*FCola)->Sig = Nuevo;
    }
    else                        // Si la cola está vacia
    {
        Nuevo->Sig = Nuevo;
    }
    *FCola = Nuevo;             // FCola apunta al último elemento (alta)
}

//////////////////////////////////////////////////////////////////////////////
int BajaCola (T_EDatos ** FCola, int *Datos)
{
    T_EDatos *Aux = (*FCola)->Sig;  // Puntero al primer elemento (baja)

    if (*FCola)                 // Si la cola no está vacia
    {
        *Datos = Aux->Datos;
        if (*FCola == Aux)      // Si la cola tiene solo un elemento
        {
            *FCola = NULL;
            free (Aux);
        }
        else                    // Si tiene más de un elemento
        {
            (*FCola)->Sig = Aux->Sig;
            free (Aux);
        }
        return (SI);            // Se ha dado de alta
    }
    else                        // Cola vacia, no se puede dar de baja
    {
        return (NO);            // No se ha dado de alta
    }
}

//////////////////////////////////////////////////////////////////////////////
void ImpCola (T_EDatos * FCola)
{
    T_EDatos *Aux = FCola->Sig; // Puntero para recorrer la cola (al 1ª nodo)

    if (Aux)                    // Si tiene algún elemento (no está vacia)
    {
        while (Aux != FCola) {
            printf ("%2d\t", Aux->Datos);
            Aux = Aux->Sig;
        }
        printf ("%2d\t", Aux->Datos);
    }
}

//////////////////////////////////////////////////////////////////////////////
void AltaPila (T_EDatos ** PPila, int Datos)
{
    T_EDatos *Nuevo = NULL;     // Memoria para el nuevo nodo
    T_EDatos *Ant = NULL, *Act = *PPila;    // Punteros para recorrer la pila

    // Reservo memoria para el nodo
    Nuevo = (T_EDatos *) malloc (sizeof (T_EDatos));
    if (!Nuevo) {
        printf ("No hay memoria suficiente");
        getch ();
        exit (1);
    }
    // Asigno los datos al nuevo nodo
    Nuevo->Datos = Datos;
    Nuevo->Sig = NULL;
    // Doy de alta el nodo
    if (*PPila)                 // Si la pila no está vacia
    {
        while (Act)             // Se situa al final de la pila (último nodo)
        {
            Ant = Act;
            Act = Act->Sig;
        }
        Ant->Sig = Nuevo;       // Enlaza el último elemento con el nuevo
    }
    else                        // Si la pila está vacia
    {
        *PPila = Nuevo;
    }
}

//////////////////////////////////////////////////////////////////////////////
int BajaPila (T_EDatos ** PPila, int *Datos)
{
    T_EDatos *Ant = NULL, *Act = *PPila;    // Punteros para recorrer la pila

    if (Act)                    // Si existen elementos
    {
        while (Act->Sig)        // Colocar punteros al final de la pila
        {
            Ant = Act;
            Act = Act->Sig;
        }
        if (!Ant)               // Si solo hay un elemento
        {
            *Datos = Act->Datos;
            free (Act);
            *PPila = NULL;
        }
        else                    // Si hay más de un elemento
        {
            *Datos = Act->Datos;
            Ant->Sig = NULL;
            free (Act);
        }
        return (SI);
    }
    else                        // No existen elementos, no se pueden eliminar
    {
        return (NO);
    }
}

//////////////////////////////////////////////////////////////////////////////
void ImpPila (T_EDatos * PPila)
{
    T_EDatos *Aux = PPila;      // Puntero auxiliar para recorrer la pila

    while (Aux) {
        printf ("%2d\t", Aux->Datos);
        Aux = Aux->Sig;
    }
}

//////////////////////////////////////////////////////////////////////////////
int BuscaLista (T_EDatos * PLista, int Datos, T_EDatos ** Ant,
                T_EDatos ** Act)
{
    int Hallado = NO;

    *Ant = NULL;
    *Act = PLista;
    while (*Act && !Hallado)    // Mientras no llege al final (*Act) o no
    {                           // encuentre el dato (Hallado=NO)
        if ((*Act)->Datos >= Datos) {
            Hallado = SI;
        }
        else {
            *Ant = *Act;
            *Act = (*Act)->Sig;
        }
    }
    if ((*Act)->Datos == Datos)
        return (SI);            // Devuelve SI si ha encontrado el elemento
    else
        return (NO);            // Devuelve NO si no ha encontrado el elemento
}

//////////////////////////////////////////////////////////////////////////////
void AltaLista (T_EDatos ** PLista, int Datos)
{
    T_EDatos *Nuevo = NULL;     // Memoria para el nuevo nodo
    T_EDatos *Ant = NULL, *Act = *PLista;   // Punteros para recorrer la pila

    // Reservo memoria para el nodo
    Nuevo = (T_EDatos *) malloc (sizeof (T_EDatos));
    if (!Nuevo) {
        printf ("No hay memoria suficiente");
        getch ();
        exit (1);
    }
    // Asigno los datos al nuevo nodo
    Nuevo->Datos = Datos;
    // Doy de alta el nodo (entre Ant y Act)
    if (*PLista)                // Si hay algún elemento
    {
        // Busco la posición donde insertar el nodo
        BuscaLista (*PLista, Datos, &Ant, &Act);
        if (!Ant)               // Si hay que insertar en 1ª posición
        {
            *PLista = Nuevo;
        }
        else                    // Si hay que insertar entre dos nodos
        {
            Ant->Sig = Nuevo;
        }
        Nuevo->Sig = Act;
    }
    else                        // Si no existe ningún nodo
    {
        *PLista = Nuevo;
        Nuevo->Sig = NULL;
    }
}

//////////////////////////////////////////////////////////////////////////////
int BajaLista (T_EDatos ** PLista, int Datos)
{
    T_EDatos *Ant = NULL, *Act = *PLista;   // Punteros para recorrer la pila

    if (*PLista)                // Si la lista tiene algún elemento
    {
        if (BuscaLista (*PLista, Datos, &Ant, &Act))    // Dato encontrado
        {
            if (!Ant)           // Si es el primer dato de la lista
            {
                *PLista = Act->Sig;
            }
            else                // Si no es el primer dato de la lista
            {
                Ant->Sig = Act->Sig;
            }
            free (Act);
            return (SI);
        }
        else                    // Dato no encontrado, no se puede dar de baja
        {
            return (NO);
        }
    }
    else {
        return (NO);            // Lista vacia no se puede dar de baja
    }
}

//////////////////////////////////////////////////////////////////////////////
void ImpLista (T_EDatos * PLista)
{
    T_EDatos *Aux = PLista;     // Puntero auxiliar para recorrer la pila

    while (Aux) {
        printf ("%2d\t", Aux->Datos);
        Aux = Aux->Sig;
    }
}

//////////////////////////////////////////////////////////////////////////////
void MenuCola (void)
{
    int x = 0, y = 0;

    cprintf ("%31c COLAS CIRCULARES %31c", 0, 0);
    // Opciones
    x = 5;
    y = 4;
    cprintf ("1.-");
    cprintf ("2.-");
    cprintf ("3.-");
    x = 9;
    y = 4;
    cprintf ("Insertar un elemento en la cola.");
    cprintf ("Eliminar un elemento en la cola.");
    cprintf ("Volver.");
}

//////////////////////////////////////////////////////////////////////////////
void MenuPila (void)
{
    int x = 0, y = 0;

    cprintf ("%36c PILAS %37c", 0, 0);
    // Opciones
    x = 5;
    y = 4;
    cprintf ("1.-");
    cprintf ("2.-");
    cprintf ("3.-");
    x = 9;
    y = 4;
    cprintf ("Insertar un elemento en la pila.");
    cprintf ("Eliminar un elemento de la pila.");
    cprintf ("Volver.");
}

//////////////////////////////////////////////////////////////////////////////
void MenuLista (void)
{
    int x = 0, y = 0;

    cprintf ("%31c LISTAS ENLAZADAS %31c", 0, 0);
    // Opciones
    x = 5;
    y = 4;
    cprintf ("1.-");
    cprintf ("2.-");
    cprintf ("3.-");
    x = 9;
    y = 4;
    cprintf ("Insertar un elemento en la lista.");
    cprintf ("Eliminar un elemento de la lista.");
    cprintf ("Volver.");
}

//////////////////////////////////////////////////////////////////////////////

// M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
    T_EDatos *Lista = NULL;
    int Opcion = 0, Salir = NO;
    int DatoAlta = 0;

    do {
        MenuLista ();
        Opcion = getch ();
        switch (Opcion) {
            case '1':
                printf ("Introduce el alta (entero): ");
                scanf ("%d", &DatoAlta);
                AltaLista (&Lista, DatoAlta);
                ImpLista (Lista);
                break;
            case '2':
                printf ("Introduce la baja (entero): ");
                scanf ("%d", &DatoAlta);
                if (!BajaLista (&Lista, DatoAlta)) {
                    printf ("Valor no encontrado o Lista vacia");
                }
                ImpLista (Lista);
                break;
            case '3':
                Salir = SI;
                break;
            default:
                gotoxy (20, 10);
                cprintf ("Opción no valida, pulse una tecla.");
                break;
        }
    }
    while (!Salir);
    free (Lista);
}

//////////////////////////////////////////////////////////////////////////////
