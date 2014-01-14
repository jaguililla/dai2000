// P R I M   &   K R U S K A L ///////////////////////////////////////////////

// I N C L U D E S ///////////////////////////////////////////////////////////
#include <stdlib.h>


// D E F I N E S /////////////////////////////////////////////////////////////
#define NUMNODOS 5
#define SI 1
#define NO 0

// T I P O S /////////////////////////////////////////////////////////////////

typedef struct tipoarista {
    int origen;
    int dest;
    int peso;

    struct tipoarista *sig;
} tipoarista;

typedef struct tiponodo {
    int num_nodo, conexo;

    struct tiponodo *sig;
} tiponodo;

// P R O T O T I P O S ///////////////////////////////////////////////////////
void menu (void);

void alta_nodo (tiponodo ** raiz);
void alta_arista (tiponodo * raiz, tipoarista ** raizaris);
void menu (void);
void kruskal (tiponodo * raiz, tipoarista * raizaris);
int comprobar (int num, tiponodo * raiz);
int libres (tiponodo * raiz, int num1, int num2);
int conexos (tiponodo * raiz);

// F U N C I O N E S /////////////////////////////////////////////////////////
void menu (void)
{
    clrscr ();
    gotoxy (5, 2);
    printf ("Algoritmos de Kruskal");
    gotoxy (3, 4);
    printf ("1.- Dar de alta un nodo.");
    gotoxy (3, 5);
    printf ("2.- Dar de alta varios nodos.");
    gotoxy (3, 6);
    printf ("3.- Dar de alta una arista.");
    gotoxy (3, 7);
    printf ("4.- Aplicar el algoritmo de Kruskal al grafo.");
    gotoxy (3, 8);
    printf ("5.- Salir.");
}

//////////////////////////////////////////////////////////////////////////////
int libres (tiponodo * raiz, int num1, int num2)
{
    tiponodo *aux;
    int ten1 = 0, ten2 = 0;

    aux = raiz;

    while (aux) {
        if (aux->num_nodo == num1)
            if (aux->conexo == 0)
                ten1 = 1;
            else if (aux->num_nodo == num2)
                if (aux->conexo == 0)
                    ten2 = 1;

        aux = aux->sig;
    }

    if ((ten1 == 0) || (ten2 == 0))
        return (0);

    return (1);
}

//////////////////////////////////////////////////////////////////////////////
void listarnodos (tiponodo * cl)
{
    while (cl != NULL) {
        printf ("%4d", cl->num_nodo);
        cl = cl->sig;
    }

    printf ("\n");
}

void listararis (tipoarista * cl)
{
    int cont = 0;

    while (cl != NULL) {
        printf ("{%2d,%2d} peso= %d\n", cl->origen, cl->dest, cl->peso);
        cl = cl->sig;
        cont++;

        if (cont % 20 == 0) {
            printf ("Presione una tecla para continuar.");
            getch ();
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
void alta_nodo (tiponodo ** raiz)
{
    //da de altas los nodos en una L.S.E.
    tiponodo *nuevo;
    tiponodo *act;

    act = *raiz;
    nuevo = (tiponodo *) malloc (sizeof (tiponodo));

    if (nuevo == NULL)
        printf ("No hay memoria suficiente.");
    else {                      //asigna automáticamente el número de los nodos
        nuevo->sig = NULL;
        nuevo->conexo = 0;

        if (*raiz == NULL)
            nuevo->num_nodo = 1;
        else {
            while (act->sig) {
                act = act->sig;
            }

            nuevo->num_nodo = act->num_nodo + 1;
        }

        act->sig = nuevo;
    }
}

//////////////////////// //////////////////////////////////////////////////////
void kruskal (tiponodo * raiz, tipoarista * raizaris)
{

    int con = 0, num1, num2, libre;
    tiponodo *act, *ant = NULL;
    tipoarista *aho /*, *prin=NULL */ ;

    aho = raizaris;
    printf ("Lista de aristas:\n");

    while ((!con) && (aho)) {
        num1 = aho->origen;
        num2 = aho->dest;
        act = raiz;
        //indica si se forma un ciclo,devuelve 0
        /*pseudo */
        libre = libres (&(*raiz), num1, num2);

        if (libre) {            //si no forma ciclo
            //da de alta la arista actual en una lista auxiliar con prin como raiz
            //alta2(prin,aho);
            printf ("{%2d,%2d}\t", num1, num2);

            while (act) {       /*&&((act->num_nodo<num1)&&(act->num_nodo<num2))) */
                ant = act;      //ahorra tiempo 

                if (ant->num_nodo == num1)
                    ant->conexo = 1;

                if (ant->num_nodo == num2)
                    ant->conexo = 1;

                act = act->sig;
            }

            aho = aho->sig;
            //indica si todos los nodos están unidos
            con = conexos (&(*raiz));
        }
    }

    if (con == 0)
        printf ("No se puede.");

    getch ();
}

//////////////////////////////////////////////////////////////////////////////
int conexos (tiponodo * raiz)
{
    while (raiz) {
        if (raiz->conexo == 0)
            return (0);
    }

    return (1);
}

//////////////////////////////////////////////////////////////////////////////
void varios (tiponodo ** raiz, int num)
{
    int indice;

    for (indice = 1; indice <= num; indice++) {
        alta_nodo (&(*raiz));
    }
}

//////////////////////////////////////////////////////////////////////////////
void alta_arista (tiponodo * raiz, tipoarista ** raizaris)
{
    //da de altas las aristas en una L.S.E.
    tipoarista *act, *nuevo, *ant = NULL;
    int esta = 1;

    if (!raiz)
        printf ("No hay nodos entre los cuales establecer aristas.");
    else if (!raiz->sig)        //solo hay un nodo
        printf ("No hay caminos posibles.");
    else {                      //hay varios nodos
        nuevo = (tipoarista *) malloc (sizeof (tipoarista));

        if (nuevo == NULL)
            printf ("No hay memoria suficiente.");
        else {
            printf ("Introduzca el nodo origen de la arista: ");

            do {                //comprueba que el origen existe
                scanf ("%d", &(nuevo->origen));
                esta = comprobar (nuevo->origen, raiz);

                if (!esta)
                    printf ("Introduzca un nodo correcto: ");
            }
            while (!esta);

            printf ("Introduzca el nodo destino de la arista: ");

            do {
                scanf ("%d", &(nuevo->dest));
                esta = comprobar (nuevo->dest, raiz);

                if (!esta)
                    printf ("Introduzca un nodo correcto: ");
            }
            while (!esta);

            printf ("Introduzca el peso de la arista: ");

            scanf ("%d", &(nuevo->peso));

            //colocación de punteros
            nuevo->sig = NULL;

            if (!raizaris)
                *raizaris = nuevo;
            else {
                act = *raizaris;

                while ((act) && (act->peso < nuevo->peso)) {
                    ant = act;
                    act = act->sig;
                }

                ant->sig = nuevo;
                nuevo->sig = act;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
int comprobar (int num, tiponodo * raiz)
{
    tiponodo *act;

    act = raiz;

    while (act->sig) {
        act = act->sig;
    }

    if (act->num_nodo > num)
        return (1);

    return (0);
}

// M A I N ///////////////////////////////////////////////////////////////////
void main (void)
{
    int op = 0, salir = NO, nume, indice;
    tiponodo *raiz;
    tipoarista *raizaris;

    raiz = NULL;
    raizaris = NULL;

    do {
        menu ();
        op = getch ();

        switch (op) {

            case '1':
                alta_nodo (&raiz);
                printf ("Nodo dado de alta.");
                getch ();
                listarnodos (raiz);
                break;

            case '2':
                printf ("\nIntroduzca el número de nodos: ");
                scanf ("%d", &nume);
                varios (&raiz, nume);
                printf ("%d nodos dados de alta.", &nume);
                getch ();
                listarnodos (raiz);
                break;

            case '3':
                alta_arista (raiz, &raizaris);
                listararis (raizaris);
                break;

            case '4':
                kruskal (raiz, raizaris);
                break;

            case '5':
                salir = SI;
                break;

            default:
                gotoxy (10, 10);
                sound (1000);
                printf ("Opción no valida");
                delay (500);
                nosound ();
                getch ();
                break;
        }
    }
    while (!salir);
}

//////////////////////////////////////////////////////////////////////////////
