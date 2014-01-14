// COLA CIRCULAR

// INCLUDES
#include <stdlib.h>


// DEFINES
#define SI 1
#define NO 0

// TIPOS

struct nodo {
    int valor;

    struct nodo *sgte;
};

typedef struct nodo nodo;

// PROTOTIPOS
void alta (nodo ** flista);
void baja (nodo ** flista);
void lista (nodo * flista);
void menu (void);

// FUNCIONES
void alta (nodo ** flista)
{
    nodo *nuevo = NULL;

    // Reserva la memoria

    if ((nuevo = (nodo *) malloc (sizeof (nodo))) == NULL)
        printf ("No hay memoria");

    // Introduce el valor
    printf ("Introduzca el valor a dar de alta: ");

    scanf ("%d", &nuevo->valor);

    // Apunta el nuevo elemento (último) al principio de la lista
    // Pregunta si la lista está vacia (flista==NULL)
    if (flista)
        (*flista)->sgte = nuevo;

    *flista = nuevo;

    nuevo->sgte = (*flista)->sgte;
}

// Fin alta()
void baja (nodo ** flista)
{
    nodo *aux = (*flista)->sgte;

    if (*flista == NULL)
        printf ("No hay elementos.");
    else if (aux == *flista)
        *flista = NULL;
    else
        (*flista)->sgte = aux->sgte;

    free (aux);
}

// Fin baja()
void lista (nodo * flista)
{
    nodo *aux = flista->sgte;

    gotoxy (10, 10);

    do {
        printf ("%2d ", aux->valor);
        aux = aux->sgte;
    }
    while (aux != flista);

    getch ();
}

// Fin lista ()

// MAIN
void main (void)
{
    nodo *fc = NULL;
    int op = 0, salir = NO;

    do {
        clrscr ();
        printf ("1.- Alta.");
        printf ("2.- Baja.");
        printf ("3.- Listar.");
        printf ("4.- Salir.");
        op = getch ();

        switch (op) {

            case '1':
                alta (&fc);
                break;

            case '2':
                baja (&fc);
                break;

            case '3':
                lista (fc);
                break;

            case '4':
                salir = SI;
                break;

            default:
                printf ("Opción no valida.");
                break;
        }
    }
    while (!salir);
}
