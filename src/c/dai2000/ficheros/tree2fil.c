/*  ÁRBOLES BINARIOS DE BÚSQUEDA.  pornivel.C  (23-4-99)    */
#include <stdio.h>

typedef struct nodoa {
    int clave;
    struct nodoa *i, *d;
} parbol;

typedef struct nodoc {
    parbol *ptro;
    struct nodoc *sig;
} pcola;

void alreves (struct nodoa *r, char *cad);
int comprueba (struct nodoa *r, struct nodoa *r2, int num);

void altacola (pcola ** cc, pcola ** fc, parbol * p)
{
    pcola *nuevo;

    nuevo = (pcola *) malloc (sizeof (pcola));
    if (nuevo) {
        nuevo->ptro = p;
        nuevo->sig = NULL;
        if (*fc)
            (*fc)->sig = nuevo;
        else
            *cc = nuevo;
        *fc = nuevo;
    }
}
void bajacola (pcola ** cc, pcola ** fc, parbol ** p)
{
    pcola *aux;

    if (*cc) {
        aux = *cc;
        *p = (*cc)->ptro;
        if (*fc == *cc)
            *fc = NULL;
        *cc = (*cc)->sig;
        free (aux);
    }
}

void inor (parbol * r)
{                               /* inorden */
    if (r) {
        inor (r->i);
        printf ("%4d", r->clave);
        inor (r->d);
    }
}
void preor (parbol * r)
{                               /* preorden */
    if (r) {
        printf ("%4d", r->clave);
        preor (r->i);
        preor (r->d);
    }
}
void postor (parbol * r)
{                               /* preorden */
    if (r) {
        postor (r->i);
        postor (r->d);
        printf ("%4d", r->clave);
    }
}
void listar (parbol * r)
{
    printf ("INORDEN:   ");
    inor (r);
    printf ("\n");
    printf ("POSTORDEN: ");
    postor (r);
    printf ("\n");
    printf ("PREORDEN:  ");
    preor (r);
    printf ("\n");
}
void buscar (parbol * r, int valor, parbol ** ant, parbol ** act)
{
    int hallado = 0;

    *ant = NULL;
    *act = r;
    while (*act && !hallado) {
        if ((*act)->clave == valor)
            hallado = 1;
        else {
            *ant = *act;
            if ((*act)->clave > valor)
                *act = (*act)->i;
            else
                *act = (*act)->d;
        }
    }                           /* while */
}                               // buscar

           /*****************************************/
void alta (parbol ** r, int valor)
{
    parbol *ant, *act;

    buscar (*r, valor, &ant, &act);
    if (act)
        printf ("\a\aLa clave %d ya existe \n", valor);
    else {
        act = (parbol *) malloc (sizeof (parbol));
        if (act == NULL)
            printf ("NO EXISTE ESPACIO DISPONIBLE \n");
        else {
            act->clave = valor;
            act->i = NULL;
            act->d = NULL;
            if (ant == NULL)
                *r = act;
            else if (ant->clave > valor)
                ant->i = act;
            else
                ant->d = act;
        }
    }
}                               /* alta */

void baja (parbol ** r, int valor)
{
    parbol *ant, *act, *aux;

    buscar (*r, valor, &ant, &act);
    if (act == NULL)
        printf ("\aNo existe %d en el árbol \n", valor);
    else {
        aux = act;
        if ((act->d == NULL) && (act->i == NULL))   /* nodo hoja */
            if (ant == NULL)
                *r = NULL;
            else if (ant->d == act)
                ant->d = NULL;
            else
                ant->i = NULL;
        else if ((act->d != NULL) && (act->i != NULL)) {    /* 2 hijos */
            ant = act;
            aux = ant->i;
            while (aux->d) {
                ant = aux;
                aux = aux->d;
            }
            act->clave = aux->clave;
            if (ant == act)
                ant->i = aux->i;
            else
                ant->d = aux->i;
        }
        else /* 1 hijo */ if (act->d == NULL)   /* hijo izquierdo */
            if (ant == NULL)
                *r = act->i;
            else if (ant->d == act)
                ant->d = act->i;
            else
                ant->i = act->i;
        else /* act-> i = null. TIENE HIJO DERECHO  */ if (ant == NULL)
            *r = act->d;
        else if (ant->d == act)
            ant->d = act->d;
        else
            ant->i = act->d;
        free (aux);
    }
}                               /* baja */

void niveles (parbol * r)
{
    pcola *cc1 = NULL, *fc1 = NULL, *cc2 = NULL, *fc2 = NULL;
    parbol *aux;
    FILE *archi;

    if (r) {
        archi = fopen ("arbolin.dat", "wb");
        altacola (&cc1, &fc1, r);
        while (cc1) {
            do {
                bajacola (&cc1, &fc1, &aux);
                fwrite (&(aux->clave), sizeof (int), 1, archi);
                if (aux->i)
                    altacola (&cc2, &fc2, aux->i);
                if (aux->d)
                    altacola (&cc2, &fc2, aux->d);
            } while (cc1);
            //printf ("\n");
            cc1 = cc2;
            fc1 = fc2;
            cc2 = NULL;
            fc2 = NULL;
        }
        fclose (archi);
    }
    else
        printf ("Arbol vacío");
    //printf ("\n");
}
int comprueba (struct nodoa *r, struct nodoa *r2, int num)
{
    int uno = 1, dos = 1;

    if (num) {
        if (r->clave == r2->clave) {
            if (r->i)
                uno = comprueba (r->i, r2->i, uno);
            if (r->d)
                dos = comprueba (r->d, r2->d, dos);
        }
        else
            uno = 0;
        if ((uno == 1) && (dos == 1))
            return (uno);
        else
            return (0);
    }
}

void alreves (struct nodoa *r, char *cad)
{
    int dato, uno = 1;
    struct nodoa *r2;
    FILE *archi;
    struct nodoa *aux;

    r2 = NULL;
    archi = fopen (cad, "rb");
    fread (&dato, sizeof (int), 1, archi);
    while (!feof (archi)) {
        printf ("%d ", dato);
        alta (&r2, dato);
        fread (&dato, sizeof (int), 1, archi);
    }
    uno = comprueba (r, r2, uno);
    if (uno)
        printf ("Los árboles son idénticos.\n");
    else
        printf ("La hemos cagao.\n");
    fclose (archi);
}
void main (void)
{
    int op = 0, dato;
    parbol *r;

    clrscr ();
    r = NULL;
    do {
        printf ("0-fin   1-altas   2-bajas   3-copia   OPCION:");
        scanf ("%d", &op);
        switch (op) {
            case 1:
                printf ("dato alta: ");
                scanf ("%d", &dato);
                alta (&r, dato);
                break;
            case 2:
                printf ("dato baja: ");
                scanf ("%d", &dato);
                baja (&r, dato);
                break;
            case 3:
                niveles (r);
                alreves (r, "arbolin.dat");
                break;
        }
        listar (r);
        //printf ("\n %50s\n","por niveles");

    } while (op);
}
