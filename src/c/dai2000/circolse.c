#include<stdlib.h>


#include<stdio.h>

struct nodo {
    int dato;

    struct nodo *sig;
};

void buscar (struct nodo *cl, int valor,
             int *hallado, struct nodo **ant, struct nodo **act)
{
    *ant = NULL;
    *act = cl;
    *hallado = 0;

    do {
        if ((*act)->dato >= valor)
            *hallado = 1;
        else {
            *ant = *act;
            *act = (*act)->sig;
        }
    }
    while ((*act != cl) && (!*hallado));    /* while */

    if (*hallado)
        *hallado = (*act)->dato == valor;
}                               /* buscar */

void alta (struct nodo **cl)
{

    struct nodo *ant, *act, *nuevo;
    int num, hallado = 0;

    nuevo = (struct nodo *) malloc (sizeof (struct nodo));

    if (nuevo == NULL)
        printf ("No hay más sitio.");
    else {
        printf ("Introduzca un valor a dar de alta: ");
        scanf ("%d", &num);
        nuevo->sig = nuevo;

        if (*cl == NULL)
            *cl = nuevo;
        else {
            buscar (*cl, num, &hallado, &ant, &act);
            nuevo->sig = act;
            ant->sig = nuevo;
        }

        nuevo->dato = num;
        printf ("Se ha dado de alta.");
    }

    getch ();
}

void baja (struct nodo **cl)
{

    struct nodo *ant, *act;
    int hallado = 0, num;

    printf ("introduzca un valor a dar de baja: ");
    scanf ("%d", &num);
    buscar (*cl, num, &hallado, &ant, &act);
}
void main (void)
{
    int resp, valor = 0;
    struct nodo *cl;

    cl = NULL;
    do {
        clrscr ();
        printf ("Seleccione una opción:\n");
        printf ("\t1.- Agregar.\n");
        printf ("\t2.- Borrar.\n");
        printf ("\t3.- Listar.\n");
        printf ("\t4.- Salir\n");
        printf ("Ha elegido: ");
        scanf ("%d", &resp);
        fflush (stdin);         //o "%d%c"
        switch (resp) {

            case 1:
                alta (&cl);
                break;
            case 2:
                baja (&cl);
                break;
            case 3:
                listar (cl);
                break;
            case 4:
                valor++;
                break;
        }
    }
    while (valor != 1);
}
