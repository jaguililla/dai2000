/*  examen recuperación 2ª evaluación. Ejercicio 3 */
#include <stdio.h>
struct nodo {
    int clave;
    struct nodo *ant, *sig;
};
void hacercircular (struct nodo *cl);
void alta (struct nodo **cl, int valor, int posicion);
void baja (struct nodo **cl, int posicion);
void listar (struct nodo *cl);

void main (void)
{
    int op = 0, dato, n;
    struct nodo *cl;

    clrscr ();
    cl = NULL;                  //inicialista (&cl);
    do {
        printf ("0.-fin 1.-altas   2.-bajas  opcion:");
        scanf ("%d", &op);
        switch (op) {
            case 1:
                printf ("alta: ");
                scanf ("%d", &dato);
                printf ("lugar: ");
                scanf ("%d", &n);
                alta (&cl, dato, n);
                break;
            case 2:
                printf ("lugar: ");
                scanf ("%d", &n);
                baja (&cl, n);
                break;
        }                       /* switch */
        printf ("%43s\n", "LISTA");
        listar (cl);
        getch ();
    } while (op);
}

void hacercircular (struct nodo *cl)
{
    struct nodo *aux;

    if (cl) {
        aux = cl;
        while (aux->sig != NULL)
            aux = aux->sig;
        aux->sig = cl;
        cl->ant = aux;
    }
}

void listar (struct nodo *cl)
{
    struct nodo *aux;

    if (cl == NULL)
        printf ("\n\n ");
    else {
        printf ("Listado  ascendente: ");
        aux = cl;
        do {
            printf ("%4d", aux->clave);
            aux = aux->sig;
        } while (aux != cl);
        printf ("\n");
        printf ("Listado descendente: ");
        aux = cl->ant;
        do {
            printf ("%4d", aux->clave);
            aux = aux->ant;
        } while (aux != cl->ant);
        printf ("\n");
    }
}                               /* listar */

void alta (struct nodo **cl, int valor, int posicion)
{
    struct nodo *nuevo, *aux;

    nuevo = (struct nodo *) malloc (sizeof (struct nodo));
    if (nuevo == NULL)
        printf ("NO EXISTE ESPACIO DISPONIBLE \n");
    else {
        nuevo->clave = valor;
        if (*cl == NULL) {      /* lista inicialmente vacía */
            nuevo->sig = nuevo;
            nuevo->ant = nuevo;
            *cl = nuevo;
        }
        else {                  /* la lista contiene elementos */
            aux = *cl;
            posicion--;
            while (posicion && aux->sig != *cl) {
                posicion--;
                aux = aux->sig;
            }
            if (posicion) {
                /* la lista no contiene suficientes elementos */
                /* insertar a la derecha de aux               */
                nuevo->ant = aux;
                nuevo->sig = aux->sig;
                aux->sig->ant = nuevo;
                aux->sig = nuevo;
            }
            else {              /* insertar a la izquierda de aux */
                nuevo->ant = aux->ant;
                nuevo->sig = aux;
                aux->ant->sig = nuevo;
                aux->ant = nuevo;
                if (aux == (*cl))
                    *cl = nuevo;
            }
        }
    }
}

void baja (struct nodo **cl, int n)
{
    struct nodo *aux;

    if (*cl) {
        n--;
        aux = *cl;
        while (n && aux->sig != *cl) {
            n--;
            aux = aux->sig;
        }
        if (n)
            printf ("no hay suficientes datos\n");
        else {                  /* quitar el elemento referenciado por aux */
            if (*cl == (*cl)->sig)
                *cl = NULL;
            else {
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
                if (aux == *cl)
                    *cl = (*cl)->sig;
            }
            free (aux);
        }
    }
    else
        printf ("lista vacía");
}                               /* baja */
