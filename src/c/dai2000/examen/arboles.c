#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato;
    struct nodo *izq;
    struct nodo *der;
};

void buscar (struct nodo *r, int valor, struct nodo **ant, struct nodo **act);
void alta (struct nodo **r, int valor);
void baja (struct nodo **r, int valor);
void inorden (struct nodo *r);
void preorden (struct nodo *r);
void postorden (struct nodo *r);
int menu (void);

void main (void)
{
    int valor;
    struct nodo *r;

    clrscr ();
    r = NULL;
    for (;;) {
        switch (menu ()) {
            case 1:
                printf ("\nDato alta: ");
                scanf ("%d", &valor);
                alta (&r, valor);
                printf ("\nINORDEN: ");
                inorden (r);
                printf ("\nPREORDEN: ");
                preorden (r);
                printf ("\nPOSTORDEN: ");
                postorden (r);
                getch ();
                break;
            case 2:
                printf ("\nDato baja: ");
                scanf ("%d", &valor);
                baja (&r, valor);
                printf ("\nINORDEN: ");
                inorden (r);
                printf ("\nPREORDEN: ");
                preorden (r);
                printf ("\nPOSTORDEN: ");
                postorden (r);
                getch ();
                break;
            case 3:
                clrscr ();
                printf ("INORDEN: ");
                inorden (r);
                getch ();
                break;
            case 4:
                clrscr ();
                printf ("POSTORDEN: ");
                postorden (r);
                getch ();
                break;
            case 5:
                clrscr ();
                printf ("PREORDEN: ");
                preorden (r);
                getch ();
                break;
            case 6:
                exit (0);
                break;

        }
    }
}
void alta (struct nodo **r, int valor)
{
    struct nodo *act, *ant;

    buscar (*r, valor, &ant, &act);
    if (act /*!=NULL */ )
        printf ("Dato ya existe\n");
    else {
        act = (struct nodo *) malloc (sizeof (struct nodo));
        if (act == NULL)
            printf ("no hay espacio\n");
        else {
            act->dato = valor;
            act->izq = NULL;
            act->der = NULL;
            if (ant == NULL)
                *r = act;
            else if (ant->dato > valor)
                ant->izq = act;
            else
                ant->der = act;
        }
    }
}
void inorden (struct nodo *r)
{
    if (r /*!=NULL */ ) {
        inorden (r->izq);
        printf ("%4d", r->dato);
        inorden (r->der);
    }
}
void preorden (struct nodo *r)
{
    if (r /*!=NULL */ ) {
        printf ("%4d", r->dato);
        preorden (r->izq);
        preorden (r->der);
    }
}
void postorden (struct nodo *r)
{
    if (r /*!=NULL */ ) {
        postorden (r->izq);
        postorden (r->der);
        printf ("%4d", r->dato);
    }
}
void buscar (struct nodo *r, int valor, struct nodo **ant, struct nodo **act)
{
    int hallado = 0;

    *ant = NULL;
    *act = r;
    while (*act != NULL && hallado == 0) {
        if ((*act)->dato == valor)
            hallado = 1;
        else {
            *ant = *act;
            if ((*act)->dato > valor)
                *act = (*act)->der;
            else
                *act = (*act)->izq;
        }
    }
}
int menu (void)
{
    int opcion;

    do {
        clrscr ();
        printf ("1.Altas.\n");
        printf ("2.Bajas.\n");
        printf ("3.Listado inorden.\n");
        printf ("4.Listado postoerden.\n");
        printf ("5.Listado preorden.\n");
        printf ("6.Salir.\n");
        printf ("Elija opcion : ");
        opcion = getche () - 48;
    }
    while (opcion < 1 || opcion > 6);
    return (opcion);
}
void baja (struct nodo **r, int valor)
{
    struct nodo *ant, *act, *aux;

    buscar (*r, valor, &ant, &act);
    if (act == NULL)
        printf ("no existe");
    else {
        aux = act;
        if ((act->der == NULL) && (act->izq == NULL))
            if (ant == NULL)
                *r = NULL;
            else if (ant->der == act)
                ant->der = NULL;
            else
                ant->izq = NULL;
        else if ((act->der != NULL) && (act->izq == NULL)) {
            ant = act;
            aux = ant->izq;
            while (aux->der) {
                ant = aux;
                aux = aux->der;
            }
            act->dato = aux->dato;
            if (ant == act)
                ant->izq = aux->izq;
            else
                ant->der = aux->der;
        }
        else if (act->der == NULL)
            if (ant == NULL)
                *r = act->izq;
            else if (ant->der == act)
                ant->der = act->izq;
            else
                ant->izq = act->izq;
        else if (ant == NULL)
            *r = act->der;
        else if (ant->der == act)
            ant->der = act->der;
        else
            ant->izq = act->der;
        free (aux);
    }

}
