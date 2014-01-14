/*Dado un grado en representacion matricial, se pide construir la
representacion enlazada*/

#include <stdio.h>

#include <math.h>
#include <ctype.h>

#include <stdlib.h>

#define N 3

typedef struct {
    int nodof;
    int peso;

    struct tipoarista *sig;
} tipoarista;

typedef struct {
    int nodo;
    tipoarista *aristas;
} tiponodo;

//PROTOTIPO DE LAS FUNCIONES

void rellena (int tabla[][N]);
void enlazar (int a[][N], tiponodo ** raiz);
void visualizar_lista (tiponodo * raiz);
void alta_arista (tipoarista ** raiz, int i, int peso);
void alta_nodo (tipoarista ** raiz, int i);

//PROGRAMA PRINCIPAL

void main (void)
{
    int pesos[N][N];
    tiponodo *raiz;

    raiz = NULL;
    randomize ();
    clrscr ();
    rellena (pesos);
    enlazar (pesos, &raiz);
    // visualizar_lista (raiz);
}

///////////////////////////////////////////////////////////////////////////

void rellena (int tabla[][N])
{
    int indice, cont;

    randomize ();
    printf ("Nº de nodo");

    for (indice = 1; indice <= N; indice++)
        printf ("\t%d", indice);

    printf ("\n");

    printf ("          *****************************************-\n");

    for (indice = 1; indice <= N; indice++) {
        printf ("\t%d *\t", indice);

        for (cont = 1; cont <= N; cont++) {
            if (indice == cont)
                tabla[indice][cont] = 0;
            else if (cont > indice)
                tabla[indice][cont] = rand ()%50 + 1;
            else
                tabla[indice][cont] = tabla[cont][indice];

            printf ("%d\t", tabla[indice][cont]);
        }

        printf ("\n\t  *\n");
    }

    getch ();
}

///////////////////////////////////////////////////////////////////////////

void enlazar (int a[][N], tiponodo ** raiz)
{
    tiponodo *nuevo;
    int i, j;

    for (i = 1; i <= N; i++) {
        alta_nodo (&raiz, i);

        for (j = 1; j <= N; j++) {
            if (i != j) {
                alta_arista (&raiz, j, a[i][j]);
            }
        }
    }
}

void alta_arista (tipoarista ** raiz, int i, int peso)
{
}

///////////////////////////////////////////////////////////////////////////

void visualizar_lista (tiponodo * raiz)
{
    tiponodo *aux;

    aux = raiz;

    while (aux != NULL) {
        printf ("%d", aux->nodo);
        aux = aux->aristas->sig;
    }

    getch ();

}

void alta_nodo (tipoarista ** raiz, int i)
{
}
