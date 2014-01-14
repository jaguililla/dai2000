/*  PUNTEROS.lista simplemente enlazada .  YOPLSE.C  */
#include <stdio.h>


struct nodo {
    int clave;

    struct nodo *sig;
};

void buscar (struct nodo *cl, int valor, int *hallado,
             struct nodo **ant, struct nodo **act);

void alta (struct nodo **cl, int valor);

void baja (struct nodo **cl, int valor);

void listar (struct nodo *cl);
void menu (void);

void main (void)
{
    int op = 0, dato;

    struct nodo *cl;

    clrscr ();
    cl = NULL;                  //inicialista (&cl);

    while (op != 3) {
        menu ();
        printf ("INTRODUCE OPCION (1/3) ");
        scanf ("%d", &op);

        switch (op) {

            case 1:
                printf ("dato alta: ");
                scanf ("%d", &dato);
                alta (&cl, dato);
                listar (cl);
                getch ();
                break;

            case 2:
                printf ("dato a dar de baja: ");
                scanf ("%d", &dato);
                baja (&cl, dato);
                listar (cl);
                getch ();
                break;
        }
    }
}

/**************************************************************/
void menu (void)
{
    printf ("%20c  1.- altas   2.- bajas  3.-SALIR. \n", ' ');
}                               /* menu */

/***************************************************/

void buscar (struct nodo *cl, int valor,
             int *hallado, struct nodo **ant, struct nodo **act)
{
    *ant = NULL;
    *act = cl;
    *hallado = 0;

    while ((*act != NULL) && (!*hallado)) {
        if ((*act)->clave >= valor)
            *hallado = 1;
        else {
            *ant = *act;
            *act = (*act)->sig;
        }
    }                           /* while */

    if (*hallado)
        *hallado = (*act)->clave == valor;
}                               /* buscar */

/*****************************************/

void alta (struct nodo **cl, int valor)
{

    struct nodo *nuevo, *ant, *act;
    int hallado;

    buscar (*cl, valor, &hallado, &ant, &act);

    if (hallado)
        printf ("La clave %d ya existe \n", valor);
    else {

        nuevo = (struct nodo *) malloc (sizeof (struct nodo));

        if (nuevo == NULL)
            printf ("NO EXISTE ESPACIO DISPONIBLE \n");
        else {
            nuevo->clave = valor;
            nuevo->sig = act;

            if (ant == NULL)
                *cl = nuevo;
            else
                ant->sig = nuevo;
        }
    }
}                               /* alta */

/************************************************************/

void baja (struct nodo **cl, int valor)
{

    struct nodo *ant, *act;
    int hallado;

    buscar (*cl, valor, &hallado, &ant, &act);

    if (!hallado)
        printf ("No existe el dato en la lista \n");
    else {
        if (ant == NULL)
            *cl = act->sig;
        else
            ant->sig = act->sig;

        free (act);
    }
}                               /* baja */

void listar (struct nodo *cl)
{
    while (cl != NULL) {
        printf ("%4d", cl->clave);
        cl = cl->sig;
    };

    printf ("\n");
}                               /* listar */
