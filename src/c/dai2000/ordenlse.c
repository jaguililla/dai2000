#include<stdio.h>
#include<stdlib.h>



struct nodo {
    int dato;

    struct nodo *sig;
};

typedef struct nodo nodo;

//////////////////////////////////////////////////////////////////////////////

void listar (struct nodo *cl)
{
    while (cl != NULL) {
        printf ("%4d", cl->dato);
        cl = cl->sig;
    }

    printf ("\n");
    getch ();
}

//////////////////////////////////////////////////////////////////////////////
void ordenar (nodo ** cl)
{
    nodo *r, *ar, *a, *aa;

    r = *cl;
    ar = NULL;
    aa = a = NULL;

    while (r) {
        a = r->sig;
        aa = r;

        while (a) {
            if (a->dato <= r->dato) {
                aa->sig = a->sig;   // Se salta a que es el que va a cambiar
                a->sig = r;

                if (ar)
                    ar->sig = a;
                else
                    *cl = a;

                r = a;

                a = aa->sig;
            }
            else {
                aa = a;
                a = a->sig;
            }
        }

        ar = r;
        r = r->sig;
    }
}

//////////////////////////////////////////////////////////////////////////////

void difer (struct nodo *cl, struct nodo *cl2)
{
    int nume;

    while (cl) {
        nume = siesta (cl->dato, cl2);

        if (nume == 0)
            printf ("%4d", cl->dato);

        cl = cl->sig;
    }
}

//////////////////////////////////////////////////////////////////////////////

int siesta (int num, struct nodo *cl2)
{
    while (cl2) {
        if (num == cl2->dato)
            return (1);

        cl2 = cl2->sig;
    }

    return (0);
}

//////////////////////////////////////////////////////////////////////////////

void vaciar (struct nodo *cl)
{

    struct nodo *ant;

    while (cl) {
        ant = cl;
        cl = cl->sig;
        free (ant);
    }
}

//////////////////////////////////////////////////////////////////////////////

int uniones (struct nodo *cl, struct nodo *cl2, struct nodo **cl3)
{

    struct nodo *nuevo, *ant;
    int cont = 0;

    while ((cl) || (cl2)) {

        nuevo = (struct nodo *) malloc (sizeof (struct nodo));

        if (nuevo == NULL) {
            printf ("Oye, que no hago más uniones.");
            getch ();
        }
        else {
            nuevo->sig = NULL;

            if (*cl3) {
                if (ant)
                    ant->sig = nuevo;
                else
                    ant = nuevo;
            }
            else
                *cl3 = nuevo;

            if ((cl) && (cl2)) {
                if (cl->dato < cl2->dato) {
                    nuevo->dato = cl->dato;
                    cl = cl->sig;
                }
                else {
                    nuevo->dato = cl2->dato;
                    cl2 = cl2->sig;
                }
            }
            else if (cl) {
                nuevo->dato = cl->dato;
                cl = cl->sig;
            }
            else if (cl2) {
                nuevo->dato = cl2->dato;
                cl2 = cl2->sig;
            }

            ant = nuevo;
            cont++;
        }
    }

    return (cont);
}

//////////////////////////////////////////////////////////////////////////////

void inter (struct nodo *cl, struct nodo *cl2)
{

    struct nodo *aux;

    while (cl) {
        aux = cl2;

        while (aux) {
            if (cl->dato == aux->dato)
                printf ("%4d", cl->dato);

            aux = aux->sig;
        }

        cl = cl->sig;
    }

    getch ();
}

//////////////////////////////////////////////////////////////////////////////

void daralta (struct nodo **cl, int num)
{
    int indice;

    struct nodo *nuevo;

    for (indice = 1; indice <= num; indice++) {

        nuevo = (struct nodo *) malloc (sizeof (struct nodo));
        nuevo->dato = rand () % 100 + 1 + 1;

        if (nuevo == NULL) {
            printf ("No hay más sitio. Sólo hay %d elementos.", indice - 1);
            break;
        }

        if (indice == 1) {
            *cl = nuevo;
            nuevo->sig = NULL;
        }
        else {
            nuevo->sig = *cl;
            *cl = nuevo;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
void main (void)
{
    int num, indice, cont;

    struct nodo *cl, *nuevo, *cl2, *cl3;

    clrscr ();
    randomize ();
    printf ("Introduzca el nº de elementos: ");
    scanf ("%d", &num);
    daralta (&cl, num);
    daralta (&cl2, num);
    ///////////////////////////////////
    ordenar (&cl);
    ordenar (&cl2);
    printf ("Lista 1:\n");
    listar (cl);
    printf ("Lista 2:\n");
    listar (cl2);
    //////////////////////////////////
    cl3 = NULL;
    printf ("Unión:\n");
    cont = uniones (cl, cl2, &cl3);

    if (cont != 0)
        listar (cl3);
    else
        printf ("No hay datos comunes.\n");

    vaciar (cl3);

    /////////////////////////////////
    cl3 = NULL;

    printf ("Intersección:\n");

    inter (cl, cl2);

    //if(cont!=0)
    //listar(cl3);
    //else
    //printf("No hay intersección.\n");
    vaciar (cl3);

    ////////////////////////////////
    cl3 = NULL;

    printf ("\nDiferencia:\n");

    difer (cl, cl2);

    vaciar (cl3);

    getch ();
}
