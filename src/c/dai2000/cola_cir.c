// C O L A   C I R C U L A R /////////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>


// D E F I N E S /////////////////////////////////////////////////////////////
#define SI 1
#define NO 0

// T I P O S /////////////////////////////////////////////////////////////////

struct nodo {
    int dato;

    struct nodo *sgte;
};

typedef struct nodo nodo;

// P R O T O T I P O S ///////////////////////////////////////////////////////
void menu (void);
void alta (nodo ** final);
void baja (nodo ** final);
void lista (nodo * final);

// F U N C I O N E S /////////////////////////////////////////////////////////
void menu (void)
{
    int x = 0, y = 0;

    cprintf ("%32c COLA CIRCULAR %33c", 0, 0);
    // Opciones
    x = 5;
    y = 4;
    gotoxy (x, y);
    cprintf ("1.-");
    gotoxy (x, ++y);
    cprintf ("2.-");
    gotoxy (x, ++y);
    cprintf ("3.-");
    gotoxy (x, ++y);
    cprintf ("4.-");
    x = 9;
    y = 4;
    cprintf ("Insertar un elemento.");
    cprintf ("Eliminar un elemento.");
    cprintf ("Listar la cola.");
    cprintf ("Salir.");
}

//////////////////////////////////////////////////////////////////////////////
void alta (nodo ** final)
{
    nodo *nuevo = NULL;

    // Reserva memoria para el nuevo elemento

    if ((nuevo = (nodo *) malloc (sizeof (nodo))) == NULL)
        printf ("No hay memoria disponible");

    // Introduce el valor a dar de alta
    gotoxy (9, 9);

    printf ("Introduzca el valor a dar de alta: ");

    scanf ("%d", &nuevo->dato);

    // Ajusta los enlaces
    if (*final)                 // Si hay algún elemento...
    {
        nuevo->sgte = (*final)->sgte;
        (*final)->sgte = nuevo;
    }
    else                        // Si está vacia...
    {
        *final = nuevo;
        nuevo->sgte = *final;
    }
}

//////////////////////////////////////////////////////////////////////////////
void baja (nodo ** final)
{
    nodo *aux = (*final)->sgte;

    if (*final) {
        if (*final == aux)
            *final = NULL;
        else
            (*final)->sgte = aux->sgte;

        free (aux);
    }
    else {
        cprintf ("La cola está vacia, pulse una tecla.");
    }
}

//////////////////////////////////////////////////////////////////////////////
void lista (nodo * final)
{
    nodo *aux = final->sgte;

    while (aux != final) {
        printf ("%2d ", aux->dato);
        aux = aux->sgte;
    }

    printf ("%2d ", aux->dato); // Esto es xq no imprime el último dato
}

//////////////////////////////////////////////////////////////////////////////

// M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
    nodo *cola = NULL;
    int opcion = 0, salir = NO;

    do {
        menu ();
        opcion = getch ();

        switch (opcion) {

            case '1':
                alta (&cola);
                break;

            case '2':
                baja (&cola);
                break;

            case '3':
                lista (cola);
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

    free (cola);
}

///////////////////////////// EOF "cola_cir.c" ///////////////////////////////
