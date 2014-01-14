// INCLUDES
#include<stdlib.h>

#include<stdio.h>

// DEFINES
#define N 5

// TIPOS

typedef struct nodo {
    int apunta, peso;

    struct nodo *sgte;
} nodo;

// PROTOTIPOS
void alta_lista (nodo ** flista, int vertice, int peso);
void imp_lista (nodo * flista);
void rellena (int tabla[][N]);
void visua (int tabla[][N]);
void enlaza (int activos[], int tabla[][N], nodo * raiz[]);

// FUNCIONES
void alta_lista (nodo ** flista, int vertice, int peso)
{
    nodo *nuevo = NULL;

    // Reserva la memoria

    if ((nuevo = (nodo *) malloc (sizeof (nodo))) == NULL)
        printf ("No hay memoria");

    // Introduce el valor
    nuevo->apunta = vertice;

    nuevo->peso = peso;

    // Apunta el nuevo elemento (último) al principio de la lista
    // Pregunta si la lista está vacia (flista==NULL)
    if (flista)
        (*flista)->sgte = nuevo;

    *flista = nuevo;

    nuevo->sgte = (*flista)->sgte;
}

// Fin alta()
void imp_lista (nodo * flista)
{
    nodo *aux = flista->sgte;

    gotoxy (10, 10);

    do {
        printf ("%2d ", aux->apunta);
        aux = aux->sgte;
    }
    while (aux != flista->sgte);

    getch ();
}

// Fin lista ()
void rellena (int tabla[][N])
{
    int indice, cont;

    randomize ();
    printf ("Nº de nodo");

    for (indice = 0; indice < N; indice++)
        printf ("\t%d", indice);

    printf ("\n");

    printf ("          ________________________________________-\n");

    for (indice = 0; indice < N; indice++) {
        printf ("\t%d _\t", indice);

        for (cont = 0; cont < N; cont++) {
            if (indice == cont)
                tabla[indice][cont] = 0;
            else if (cont > indice)
                tabla[indice][cont] = rand ()%50 + 1;
            else
                tabla[indice][cont] = tabla[cont][indice];

            printf ("%d\t", tabla[indice][cont]);
        }

        printf ("\n\t  _\n");
    }
}

//////////////////////////////////////////////////////////////////////////////
void enlaza (int activos[], int tabla[][N], nodo * raiz[])
{
    int cont1 = 0, cont2 = 0;

    for (cont1 = 0; cont1 < N; cont1++) {
        if (activos[cont1]) {
            for (cont2 = 0; cont2 < N; cont2++) // Mira columnas
            {
                alta_lista (&raiz[cont1], cont2, tabla[cont1][cont2]);
            }
        }

        imp_lista (raiz[cont1]);
    }
}

//////////////////////////////////////////////////////////////////////////////
void activa_nodos (int array[])
{
    int cont1 = 0;

    for (cont1 = 0; cont1 < N; cont1++) {
        array[cont1] = 1;
        printf ("\t%d", array[cont1]);
    }
}

//////////////////////////////////////////////////////////////////////////////

void main (void)
{
    int tabla[N][N];
    nodo *raiz[N];
    int nodos[N];

    clrscr ();
    printf ("\tEste es el grafo en representación matricial\n\n");
    rellena (tabla);
    activa_nodos (nodos);
    getch ();
    clrscr ();
    printf ("\tEste es el grafo en representación enlazada\n");
    enlaza (nodos, tabla, raiz);
    getch ();
}
