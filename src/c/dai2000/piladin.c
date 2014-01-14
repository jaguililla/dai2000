// ALGORITMO COLA

// INCLUDES
#include <stdlib.h>
#include <stdio.h>



// DEFINES
#define NO 0
#define SI 1

// TIPOS

struct nodo {
    int valor;

    struct nodo *p_sgte;
};

typedef struct nodo elemento;

// PROTOTIPOS
void alta (elemento ** ppio, int num);
void baja (elemento ** ppio);
void listado (elemento ** ppio);

// FUNCIONES
void alta (elemento ** ppio, int num)
{
    elemento *nuevo = NULL;
    elemento *aux = *ppio;

    nuevo = malloc (sizeof (elemento));

    if (nuevo == NULL) {
        printf ("No hay memoria");
    }
    else {
        if (*ppio == NULL)      // Pila vacia
        {
            *ppio = nuevo;      // Principio pila apunta a nuevo valor
            nuevo->valor = num; // Asigna el valor al nuevo elemento
            nuevo->p_sgte = NULL;   // No existe elemento sgte (p_sgte==NULL)
        }
        else {
            while (aux->p_sgte) // Recorre la pila hasta último elemento
                aux = aux->p_sgte;

            aux->p_sgte = nuevo;

            nuevo->valor = num;

            nuevo->p_sgte = NULL;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
void baja (elemento ** ppio)
{
    elemento *aux = *ppio;

    if (*ppio == NULL) {
        printf ("La lista está vacia");
    }
    else {
        while (aux->p_sgte)
            aux = aux->p_sgte;

        free (aux);
    }
}

//////////////////////////////////////////////////////////////////////////////
void listado (elemento ** ppio)
{
}

//////////////////////////////////////////////////////////////////////////////

// MAIN
void main (void)
{
    elemento *pila = NULL;      // Inicio de pila
    int salir = NO;
    char op = '\0';
    int val = 0;

    gotoxy (2, 35);
    printf ("P I L A");
    gotoxy (5, 5);
    printf ("1.- Dar alta.");
    gotoxy (5, 6);
    printf ("2.- Dar baja.");
    gotoxy (5, 7);
    printf ("3.- Mostrar listado.");
    gotoxy (5, 8);
    printf ("4.- Salir.");

    do {
        op = getch ();

        switch (op) {

            case '1':
                scanf ("%d%c", &val);
                alta (&pila, val);
                break;

            case '2':
                baja (&pila);
                break;

            case '3':
                listado (&pila);
                break;

            case '4':
                salir = SI;

            default:
                printf ("Opción no valida");
                break;
        }
    }
    while (salir);
}
