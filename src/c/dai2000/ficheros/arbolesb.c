/* treb9905 */
#include <stdio.h>


#define orden 5
#define max 4
#define min 2

typedef struct nodo {
    int contador;
    char clave[orden];          /* claves indexadas de 0 a orden */
    struct nodo *rama[orden];   /* ramas indexadas de 0 a max */
} nodop;                        /* página */

typedef struct nodocola {
    nodop *p;
    struct nodocola *sig;
} nodoc;

void altacola (nodoc ** cc, nodoc ** fc, nodop * nuevo)
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

void bajacola (nodoc ** cc, nodoc ** fc, nodop ** nuevo)
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

void quitardepagina (nodop * p, int k)
{
    int i;

    for (i = k + 1; i <= p->contador; i++) {
        p->clave[i - 1] = p->clave[i];
        p->rama[i - 1] = p->rama[i];
    }
    (p->contador)--;
}                               // quitardepagina

void buscarennodo (nodop * p, char vbus, int *hallado, int *k)
{
    *k = 0;
    do
        (*k)++;
    while ((p->clave[*k] < vbus) && (*k < p->contador));
    if (p->clave[*k] == vbus)
        *hallado = 1;
    else {
        *hallado = 0;
        if (p->clave[*k] > vbus)
            (*k)--;
    }
}                               //buscarennodo

void buscarenarbol (nodop * raiz, char vbus,
                    int *hallado, nodop ** pagina, int *posicion)
{
    /* busca 'vbus' en el árbol apuntado por raiz */
    if (raiz == NULL)
        *hallado = 0;
    else {
        //buscarennodo (raiz, vbus, &(*hallado), &(*posicion));
        buscarennodo (raiz, vbus, hallado, posicion);
        if (*hallado)
            *pagina = raiz;
        else
            buscarenarbol (raiz->rama[*posicion], vbus, hallado, pagina,
                           posicion);
    }
}                               //buscarenarbol

void meterenpagina (nodop * p, int k, char x, nodop * xder)
{
    /* inserta la clave x y su rama xder en el nodo p^ en la posición *K+1*.
       Es en la posición k+1, porque x y xder suben por haber insertado en
       la rama k, y por tanto la clave y rama que suben se colocan en k+1 */

    int i;

    for (i = p->contador; i >= k + 1; i--) {
        p->clave[i + 1] = p->clave[i];
        p->rama[i + 1] = p->rama[i];
    }
    p->clave[k + 1] = x;
    p->rama[k + 1] = xder;
    (p->contador)++;
}                               //meterenpagina

// ---------------------------------------------------------------
void dividir (nodop * p, int pos, char x, nodop * xder, char *y,
              nodop ** yder)
{
    // divide la página p, que está completa, al tener que insertar en
    // ella en la posición 'pos' la clave 'x' y su rama 'xder'. Sube hacia
    // arriba la mediana 'y' y su rama derecha 'yder'
    int i;
    int posmediana;

    if (pos <= min)
        posmediana = min;
    else
        posmediana = min + 1;
    /* la mediana se queda en principio la última de la pág izquierda */

    *yder = (nodop *) malloc (sizeof (nodop));
    if (*yder) {
        for (i = posmediana + 1; i <= max; i++) {
            (*yder)->clave[i - posmediana] = p->clave[i];
            (*yder)->rama[i - posmediana] = p->rama[i];
        }
        (*yder)->contador = max - posmediana;
        p->contador = posmediana;
        if (pos <= min)
            meterenpagina (p, pos, x, xder);
        else
            meterenpagina (*yder, pos - posmediana, x, xder);
        /* metemos la mediana como raíz de la página padre */
        *y = p->clave[p->contador];
        (*yder)->rama[0] = p->rama[p->contador];
        (p->contador)--;
    }
}                               /* dividir */

/* --------------------------------------------------------------- */
void hundir (nodop * p, char valta, int *crecer, char *x, nodop ** xder)
{
    /*Inserta en  el árbol apuntado por 'p', 'valta'. Como
       consecuencia de ello el árbol puede 'crecer' subiendo hacia
       arriba una mediana 'x' y su rama 'xder'. */
    int k, hallado, subir;
    char m;
    nodop *rm;

    if (p == NULL) {
        *crecer = 1;
        *x = valta;
        *xder = NULL;
    }                           //la clave que sube es la que queremos dar de alta
    else {
        buscarennodo (p, valta, &hallado, &k);
        if (hallado) {
            *crecer = 0;
            printf ("\a clave duplicada\n");
        }
        else {
            subir = 0;
            *crecer = 0;
            hundir (p->rama[k], valta, &subir, &m, &rm);
            if (subir)
                if (p->contador < max) {
                    *crecer = 0;
                    meterenpagina (p, k, m, rm);
                }
                else {
                    *crecer = 1;
                    //dividir (p,k,m,rm,&(*x),&(*xder));
                    dividir (p, k, m, rm, x, xder);
                }
        }
    }
}                               //hundir

/* ----------------------------------------------------------  */
void altas (nodop ** raiz, char valta)
{
    //Inserta nuevallave en el arbol on la raíz dada.
    //Requiere que nueva clave no está ya presenta en el árbol
    int crecer;
    char x;
    nodop *xr, *p;

    hundir (*raiz, valta, &crecer, &x, &xr);
    if (crecer) {
        p = (nodop *) malloc (sizeof (nodop));
        p->contador = 1;
        p->clave[1] = x;
        p->rama[0] = *raiz;
        p->rama[1] = xr;
        *raiz = p;
    }
}                               //altas

/* --------------------------------------------------------------- */
void sucesor (nodop * p, int k)
{
    //Reemplaza p->clave[k] por su sucesor inmediato en orden natural
    nodop *aux;                 //busca clave sucesora en una hoja

    aux = p->rama[k];
    while (aux->rama[0])
        aux = aux->rama[0];
    p->clave[k] = aux->clave[1];
}                               //sucesor

/* --------------------------------------------------------------- */
void moverderecha (nodop * p, int k)
{
    int c;

    for (c = p->rama[k]->contador; c >= 1; c--) {
        p->rama[k]->clave[c + 1] = p->rama[k]->clave[c];
        p->rama[k]->rama[c + 1] = p->rama[k]->rama[c];
    }
    p->rama[k]->rama[1] = p->rama[k]->rama[0];
    p->rama[k]->contador = p->rama[k]->contador + 1;
    p->rama[k]->clave[1] = p->clave[k];

    p->clave[k] = p->rama[k - 1]->clave[p->rama[k - 1]->contador];
    p->rama[k]->rama[0] = p->rama[k - 1]->rama[p->rama[k - 1]->contador];
    p->rama[k - 1]->contador--;
}

/* --------------------------------------------------------------- */
void moverizquierda (nodop * p, int k)
{
    // traemos claves de p->rama[k] a p->rama[k-1]
    int c, cont;

    //modificaciones en rama[k-1]
    p->rama[k - 1]->contador++;
    cont = p->rama[k - 1]->contador;
    p->rama[k - 1]->clave[cont] = p->clave[k];
    p->rama[k - 1]->rama[cont] = p->rama[k]->rama[0];
    //modificaciones en rama[k]. Pierde una clave que pasa a p->clave[k]
    p->clave[k] = p->rama[k]->clave[1];
    p->rama[k]->rama[0] = p->rama[k]->rama[1];
    p->rama[k]->contador--;
    cont = p->rama[k]->contador;
    for (c = 1; c <= cont; c++) {
        p->rama[k]->clave[c] = p->rama[k]->clave[c + 1];
        p->rama[k]->rama[c] = p->rama[k]->rama[c + 1];
    }
}                               //moverizquierda

/* --------------------------------------------------------------- */
void combinarpaginas (nodop * p, int k)
{
    //junta las páginas p->rama[k-1] y p->rama[k] en p^rama[k-1]
    int c, cont;
    nodop *pi, *pd;             //pi=rama[k-1], pd=rama[k]

    pi = p->rama[k - 1];
    pd = p->rama[k];
    //bajamos a p->rama[k-1] la clave p->clave[k]
    pi->contador++;
    cont = pi->contador;
    pi->clave[cont] = p->clave[k];
    //trasladamos la rama[0] de pd
    pi->rama[cont] = pd->rama[0];
    // desplazamos todas las claves y ramas de pd a pi
    cont = pd->contador;
    for (c = 1; c <= cont; c++) {
        pi->contador++;
        pi->clave[pi->contador] = pd->clave[c];
        pi->rama[pi->contador] = pd->rama[c];
    }
    // bajamos todas las claves y ramas de p, que están por encima de k
    cont = p->contador;
    for (c = k; c <= cont - 1; c++) {
        p->clave[c] = p->clave[c + 1];
        p->rama[c] = p->rama[c + 1];
    };
    p->contador--;
    //dispose (q)
}

   /* --------------------------------------------------------------- */

void restablecer (nodop * p, int k)
{
    /*{p->rama[k] tiene un número de claves inferior al mínimo.
       Este procedimiento las restablece moviendo claves de páginas
       ermanas o recombinando páginas. No produce mínima altura */

    if (k == 0)
        if (p->rama[1]->contador > min)
            moverizquierda (p, 1);
        else
            combinarpaginas (p, 1);
    else if (k == p->contador)
        if (p->rama[k - 1]->contador > min)
            moverderecha (p, k);
        else
            combinarpaginas (p, k);
    else if (p->rama[k - 1]->contador > min)
        moverderecha (p, k);
    else if (p->rama[k + 1]->contador > min)
        moverizquierda (p, k + 1);
    else
        combinarpaginas (p, k);

}                               /* restablecer */

/* --------------------------------------------------------------- */
void restablecerminh (nodop * p, int k)
{
    // Restablece el número de claves al mínimo en p->rama[k]
    // Produce árbol de mínima altura
    if (k > 0)
        if (p->rama[k - 1]->contador > min)
            moverderecha (p, k);
        else
            combinarpaginas (p, k);
    else                        // k = 0
    if (p->rama[1]->contador > min)
        moverizquierda (p, 1);
    else
        combinarpaginas (p, 1);
}

/* --------------------------------------------------------------- */
void bajaenpagina (nodop * p, char vbaja, int *hallado)
{
    int k;                      // posiciín de keybaja o de la rama a buscar

    if (p == NULL)
        *hallado = 0;
    else {
        buscarennodo (p, vbaja, &(*hallado), &k);
        if (*hallado)
            if (p->rama[k - 1] == NULL)
                quitardepagina (p, k);
            else {
                sucesor (p, k);
                bajaenpagina (p->rama[k], p->clave[k], &(*hallado));
            }
        else
            bajaenpagina (p->rama[k], vbaja, &(*hallado));
        //Regreso de la llamada recursiva
        if (p->rama[k])
            if (p->rama[k]->contador < min)
                /*restablecerminh (p,k); */
                restablecer (p, k);
        //opcional entre 'restablecer' y 'restablecerminh'.
        //Este último produce un árbol B de mínima altura.
    }
}                               //baja en página

/* --------------------------------------------------------------- */
void bajas (nodop ** raiz, char vbaja)
{
    //Elimina la clave keybaja del arbol B con la raíz dada
    int hallado;                /* se ha encontrado el keybaja en un subarbol */
    nodop *aux;                 /* empleado para deshacerse de la raiz vacía */

    bajaenpagina (*raiz, vbaja, &hallado);
    if (!hallado)
        printf ("no existe la clave\n");
    else if ((*raiz)->contador == 0) {
        aux = *raiz;
        *raiz = (*raiz)->rama[0];
        free (aux);
    }
}

/* --------------------------------------------------------------- */
int potencia (int b, int e)
{
    if (e)
        return (b * potencia (b, e - 1));
    else
        return (1);
}

/* --------------------------------------------------------------- */
void listarnodo (nodop * p, int separa)
{
    int i;

    for (i = 1; i <= separa; i++)
        putchar (' ');
    for (i = 1; i <= p->contador; i++)
        printf ("%c", p->clave[i]);
    for (i = p->contador + 1; i <= max; i++)
        printf ("%c", '.');
    printf ("%s", "_ ");
}

/* --------------------------------------------------------------- */
void porniveles (nodop * raiz)
{
    nodoc *cc, *fc, *ccaux, *fcaux;
    nodop *actual;
    int i, nivel, paginas, separa;

    if (raiz == NULL)
        printf ("Arbol vacío\n");
    else {
        cc = NULL;
        fc = NULL;
        ccaux = NULL;
        fcaux = NULL;
        nivel = 1;
        paginas = potencia (orden, nivel - 1);
        separa = (80 - max * paginas) / (paginas + 1);
        altacola (&cc, &fc, raiz);
        while (cc) {
            do {
                bajacola (&cc, &fc, &actual);
                if (actual->rama[0])
                    for (i = 0; i <= actual->contador; i++)
                        altacola (&ccaux, &fcaux, actual->rama[i]);
                listarnodo (actual, separa);
            } while (cc);
            printf ("\n");
            nivel++;
            paginas = potencia (orden, nivel - 1);
            separa = (80 - max * paginas) / (paginas + 1);
            cc = ccaux;
            fc = fcaux;
            ccaux = NULL;
            fcaux = NULL;
        }
    }
}                               //Pornivel

/* --------------------------------------------------------------- */
void inorden (nodop * raiz)
{
    int i;

    if (raiz) {
        inorden (raiz->rama[0]);
        for (i = 1; i <= raiz->contador; i++) {
            printf ("%c", raiz->clave[i]);
            inorden (raiz->rama[i]);
        }
    }
}

/* --------------------------------------------------------------- */
void main (void)
{
    nodop *raiz = NULL;
    int i;
    char opcion, valtas[30], vbajas[30];

    clrscr ();
    do {
        printf ("0.-fin  1.-altas 2.-bajas  opcion:");
        opcion = getch ();
        switch (opcion) {
            case '1':          //printf ("Introduzca línea claves alta: "); gets(valtas);
                strcpy (valtas, "agfbkdhmjesirxclntup");
                printf ("longitud %d\n", strlen (valtas));
                for (i = 0; i < strlen (valtas); i++) {
                    printf ("Inserta: %c\t", valtas[i]);
                    altas (&raiz, valtas[i]);
                    printf ("Inorden: ");
                    inorden (raiz);
                    printf ("\nPor niveles\n");
                    porniveles (raiz);
                    printf ("<_\n");
                    getch ();
                }
                break;
            case '2':          //printf ('Introduzca bajas: '); gets (vbajas);
                strcpy (vbajas, "hrpd");
                for (i = 0; i < strlen (vbajas); i++) {
                    printf ("Baja: %c\t", vbajas[i]);
                    bajas (&raiz, vbajas[i]);
                    printf ("Inorden: ");
                    inorden (raiz);
                    printf ("\nPor niveles\n");
                    porniveles (raiz);
                    printf ("<_\n");
                    getch ();
                }
                break;
        }                       //switch
//    printf ("Inorden: "); inorden (raiz);
//    printf ("\nPor niveles\n"); porniveles (raiz);printf ("\a<_\n"); getch();
//    printf ("\n");
    } while (opcion != '0');
    printf ("FIN DE PROGRAMA...Pulse tecla\n");
    getch ();
}
