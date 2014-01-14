/*  implementa colas mediante listas circulares simplemente enlazadas */
#include "stdio.h"
struct nodo {
    int dato;
    struct nodo *sig;
};
void alta (struct nodo **, int);
void baja (struct nodo **);
void listar (struct nodo *);

void main (void)
{
    int op = 0, valta;
    struct nodo *fc;            /* puntero a final de cola */

    clrscr ();
    fc = NULL;
    do {
        printf ("0.-fin    1.-alta  2.-baja  opcion: ");
        scanf ("%d", &op);
        switch (op) {
            case 1:
                printf ("alta: ");
                scanf ("%d", &valta);
                alta (&fc, valta);
                break;
            case 2:
                baja (&fc);
                break;
        }
        printf ("Cola= ");
        listar (fc);
    } while (op);
}

void alta (struct nodo **fc, int valta)
{
    struct nodo *nuevo;
    nuevo = (struct nodo *) malloc (sizeof (struct nodo));
    if (nuevo) {
        nuevo->dato = valta;
        if (*fc) {              /* la cola tiene ya elementos */
            nuevo->sig = (*fc)->sig;
            (*fc)->sig = nuevo;
        }
        else
            nuevo->sig = nuevo;
        *fc = nuevo;
    }
    else
        printf ("No hay espacio en memoria\n");
}                               /* altas */

void baja (struct nodo **p)
{
    struct nodo *aux;

    if (*p) {
        aux = (*p)->sig;
        if (*p == (*p)->sig)
            *p = NULL;
        else
            (*p)->sig = aux->sig;
        free (aux);
    }
    else
        printf ("Cola vacía\n");
}

void listar (struct nodo *p)
{
    struct nodo *aux;

    if (p) {
        aux = p->sig;
        do {
            printf ("%4d", aux->dato);
            aux = aux->sig;
        } while (aux != p->sig);
        printf ("\n");
    }
    else
        printf ("Lista vacía\n");
}
