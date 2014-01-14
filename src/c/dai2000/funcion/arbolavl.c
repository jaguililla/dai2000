/* avl9905 */
#include <stdio.h>


typedef struct nodoarbol {
    int clave;
    int equi;
    struct nodoarbol *i, *d;
} nodoa;

typedef struct nodocola {
    nodoa *p;
    struct nodocola *sig;
} nodoc;

int esavl (nodoa * r)
{
    if (r == NULL)
        return (1);
    else if ((-1 <= r->equi) && (r->equi <= 1))
        return (esavl (r->i) && esavl (r->d));
    else
        return (0);
}

void altacola (nodoc ** cc, nodoc ** fc, nodoa * nuevo)
{
    nodoc *nuevonodo;

    nuevonodo = (nodoc *) malloc (sizeof (nodoc));
    nuevonodo->p = nuevo;
    nuevonodo->sig = NULL;
    if (*fc)
        (*fc)->sig = nuevonodo;
    else
        (*cc) = nuevonodo;
    *fc = nuevonodo;
};                              /* altacola */

void bajacola (nodoc ** cc, nodoc ** fc, nodoa ** nuevo)
{
    nodoc *aux;

    if (*cc) {
        *nuevo = (*cc)->p;
        aux = *cc;
        if (*fc == *cc)
            *fc = NULL;
        *cc = (*cc)->sig;
        free (aux);
    }
}                               /* bajacola */

int potencia (int b, int e)
{
    if (e)
        return (b * potencia (b, e - 1));
    else
        return (1);
}

/* --------------------------------------------------------------- */
void porniveles (nodoa * raiz)
{
    nodoc *cc, *fc, *ccaux, *fcaux;
    nodoa *actual;
    int i, nivel = 0, nodos, ini, separa;

    if (raiz == NULL)
        printf ("Arbol vacío\n");
    else {
        cc = NULL;
        fc = NULL;
        ccaux = NULL;
        fcaux = NULL;
        nivel = 0;              //
        switch (nivel) {
            case 0:
                ini = 38;
                separa = 0;
                break;
            case 1:
                ini = 16;
                separa = 38;
                break;
            case 2:
                ini = 6;
                separa = 18;
                break;
            case 3:
                ini = 1;
                separa = 8;
                break;
        }
        altacola (&cc, &fc, raiz);
        for (i = 1; i <= ini; i++)
            putchar (' ');
        while (cc) {
            do {
                bajacola (&cc, &fc, &actual);
                if (actual) {
                    altacola (&ccaux, &fcaux, actual->i);
                    altacola (&ccaux, &fcaux, actual->d);
                    printf ("%d_%d", actual->clave, actual->equi);
                }
                else
                    printf ("*_*");
                for (i = 1; i <= separa; i++)
                    putchar (' ');
            } while (cc);
            printf ("\n");
            nivel++;
            switch (nivel) {
                case 0:
                    ini = 38;
                    separa = 0;
                    break;
                case 1:
                    ini = 16;
                    separa = 38;
                    break;
                case 2:
                    ini = 6;
                    separa = 18;
                    break;
                case 3:
                    ini = 1;
                    separa = 8;
                    break;
            }
            cc = ccaux;
            ccaux = NULL;
            fc = fcaux;
            fcaux = NULL;
            for (i = 1; i <= ini; i++)
                putchar (' ');
        }                       //while (cc)
    }
}                               //Pornivel

void inorden (nodoa * raiz)
{
    if (raiz) {
        inorden (raiz->i);
        printf ("%4d", raiz->clave);
        inorden (raiz->d);
    }
}

void altas (int x, nodoa ** p, int *hacrecido)
{
    nodoa *p1, *p2;

    if (*p == NULL) {
        *p = (nodoa *) malloc (sizeof (nodoa));
        (*p)->clave = x;
        (*p)->i = NULL;
        (*p)->d = NULL;
        (*p)->equi = 0;
        *hacrecido = 1;
    }
    else if (x < (*p)->clave) { /*INSERTAR POR LA IZQUIERDA */
        altas (x, &(*p)->i, hacrecido);
        if (*hacrecido) {       /* ha crecido en altura a su izquierda */
            switch ((*p)->equi) {
                case 0:
                    (*p)->equi = -1;
                    *hacrecido = 1;
                    break;
                case 1:
                    (*p)->equi = 0;
                    *hacrecido = 0;
                    break;
                case -1:       /*Se desequilibra más. Ya no es AVL.Equilibrar */
                    p1 = (*p)->i;
                    if (p1->equi == -1) {   /*Rotación II simple */
                        (*p)->i = p1->d;
                        p1->d = *p;
                        (*p)->equi = 0;
                        *p = p1;
                    }
                    else {      /*p1->equi = 1. Rotacion ID doble */
                        p2 = p1->d;
                        p1->d = p2->i;
                        (*p)->i = p2->d;
                        p2->i = p1;
                        p2->d = *p;
                        /* Cambios en el equilibrio de p */
                        if (p2->equi == -1)
                            (*p)->equi = 1;
                        else
                            (*p)->equi = 0;
                        /* Cambios en el equilibrio de p1 */
                        if (p2->equi == 1)
                            p1->equi = -1;
                        else
                            p1->equi = 0;
                        *p = p2;
                    }
                    (*p)->equi = 0;
                    *hacrecido = 0;
                    break;      /* -1 */
            }                   // switch
        }                       //if (*hacrecido)
    }                           // if (x < (*p)->clave)
    else if (x > (*p)->clave) {
        altas (x, &(*p)->d, hacrecido);
        if (*hacrecido) {
            switch ((*p)->equi) {
                case -1:
                    (*p)->equi = 0;
                    *hacrecido = 0;
                    break;
                case 0:
                    (*p)->equi = 1;
                    break;
                case 1:        /* Si aumentó por derecha-derecha es una RDD simple,
                                   sino una Rotacion DI doble */
                    p1 = (*p)->d;
                    if (p1->equi == 1) {    /* RDDS */
                        (*p)->d = p1->i;
                        p1->i = *p;
                        (*p)->equi = 0;
                        *p = p1;
                    }
                    else {      /* RDI */
                        p2 = p1->i;
                        p1->i = p2->d;
                        (*p)->d = p2->i;
                        p2->i = *p;
                        p2->d = p1;
                        if (p2->equi == 1)
                            (*p)->equi = -1;
                        else
                            (*p)->equi = 0;
                        if (p2->equi == -1)
                            p1->equi = 1;
                        else
                            p1->equi = 0;
                        *p = p2;
                    }
                    (*p)->equi = 0;
                    *hacrecido = 0;
                    break;
            }                   /* switch */
        }                       /* if hadecrecido */
    }                           /* x >(*p)->clave */
    else
        printf ("Clave duplicada\n");
}                               /* altas */

void equilibrarizda (nodoa ** p, int *decrece)
{
    nodoa *p1, *p2;
    int ep1, ep2;               // decrece=True. Rama izquierda disminuye altura

    switch ((*p)->equi) {

        case -1:
            (*p)->equi = 0;
            break;

        case 0:
            (*p)->equi = 1;
            *decrece = 0;
            break;

        case 1:                /* Se rompe la condición AVL */
            p1 = (*p)->d;
            ep1 = p1->equi;
            if (ep1 >= 0) {     //RDD
                (*p)->d = p1->i;
                p1->i = *p;
                if (ep1 == 0) {
                    (*p)->equi = +1;
                    p1->equi = -1;
                    *decrece = 0;
                }
                else {
                    (*p)->equi = 0;
                    p1->equi = 0;
                }
                *p = p1;
            }
            else {              /* ep1= -1 */
                p2 = p1->i;
                ep2 = p2->equi;
                p1->i = p2->d;
                p2->d = p1;
                (*p)->d = p2->i;
                p2->i = *p;
                if (ep2 == 1)
                    (*p)->equi = -1;
                else
                    (*p)->equi = 0;
                if (ep2 == -1)
                    p1->equi = 1;
                else
                    p1->equi = 0;
                (*p) = p2;
                (*p)->equi = 0;
            }
            break;
    }                           // switch
};                              // equilibrarizda

void equilibrardcha (nodoa ** p, int *decrece)
{
    nodoa *p1, *p2;
    int ep1, ep2;               // decrece=True. Rama derecdecrecea disminuye altura

    switch ((*p)->equi) {

        case 1:
            (*p)->equi = 0;
            break;

        case 0:
            (*p)->equi = -1;
            *decrece = 0;
            break;

        case -1:               //* Se rompe la condición AVL
            p1 = (*p)->i;
            ep1 = p1->equi;
            if (ep1 <= 0) {     // RII
                (*p)->i = p1->d;
                p1->d = *p;
                if (ep1 == 0) {
                    (*p)->equi = -1;
                    p1->equi = 1;
                    *decrece = 0;
                }
                else {
                    (*p)->equi = 0;
                    p1->equi = 0;
                };
                *p = p1;
            }
            else {              // ep1= -1
                p2 = p1->d;
                ep2 = p2->equi;
                p1->d = p2->i;
                p2->i = p1;
                (*p)->i = p2->d;
                p2->d = *p;
                if (ep2 == -1)
                    (*p)->equi = 1;
                else
                    (*p)->equi = 0;
                if (ep2 == 1)
                    p1->equi = -1;
                else
                    p1->equi = 0;
                (*p) = p2;
                (*p)->equi = 0;
            }
            break;
    }                           // switch
}                               // equilibrardcha

void borra2h (nodoa ** r, nodoa ** q, int *decrece)
{                               /*decrece se inicia a FALSE */
    if ((*r)->d) {              /*Se sustituye por rama derecdecrecea de r */
        borra2h (&(*r)->d, q, decrece);
        if (*decrece)
            equilibrardcha (r, decrece);
    }
    else {                      /* r^ sustituye a q^ */
        (*q)->clave = (*r)->clave;
        *q = *r;
        *r = (*r)->i;
        *decrece = 1;
    }
};

void bajas (int x, nodoa ** p, int *decrece)
{
    nodoa *q;                   /* decrece=false */

    if (*p == NULL) {
        printf ("no esta\n");
        *decrece = 0;
    }
    else if (x < (*p)->clave) {
        bajas (x, &(*p)->i, decrece);
        if (*decrece)
            equilibrarizda (p, decrece);
    }
    else if (x > (*p)->clave) {
        bajas (x, &(*p)->d, decrece);
        if (*decrece)
            equilibrardcha (p, decrece);
    }
    else {                      /* Clave iguales. Borrar p^ */
        q = *p;
        if (q->d == NULL) {     /* P tiene hijo izdo y DECRECE */
            *p = q->i;
            *decrece = 1;
        }
        else if (q->i == NULL) {    /* P tiene hijo dcho y DECRECE */
            *p = q->d;
            *decrece = 1;
        }
        else {                  /* P tiene 2 hijos. Le sustituye el inmediato inferior */
            borra2h (&(*p)->i, &q, decrece);
            if (*decrece)
                equilibrarizda (p, decrece);
        }
        free (q);
    }
}                               /* bajas */

void main (void)
{
    nodoa *raiz = NULL;
    int valta, vbaja, opcion;
    int crece;

    do {
        printf ("0.-fin 1.-alta  2.-baja opcion: ");
        scanf ("%d", &opcion);
        switch (opcion) {
            case 1:
                printf ("alta: ");
                scanf ("%d", &valta);
                altas (valta, &raiz, &crece);
                break;
            case 2:
                printf ("baja: ");
                scanf ("%d", &vbaja);
                bajas (vbaja, &raiz, &crece);
                break;
        };
        porniveles (raiz);
        if (esavl (raiz))
            printf ("Es avl\n");
        else
            printf ("\a¡¡ NO ES AVL!! \n");
    } while (opcion);
    getch ();
}
