/* yoalse */

#include <stdio.h>


#define n 5

struct nodo {
    int clave, sig;
};

struct lista {
    int cl, pl;
    struct nodo datos[n];
};

void inicializar (struct lista *l)
{
    int i;

    l->cl = -1;
    l->pl = 0;
    for (i = 0; i <= n - 2; i++) {
        l->datos[i].sig = i + 1;
        l->datos[i].clave = -1;
    }
    l->datos[n - 1].clave = -1;
    l->datos[n - 1].sig = -1;
}

void listar (struct lista *l)
{
    int i;

    printf ("LISTA= ");
    i = l->cl;
    while (i != -1) {
        printf ("%6d", l->datos[i].clave);
        i = l->datos[i].sig;
    }
    printf ("\n");
}

void buscar (struct lista *l, int vbus, int *hallado, int *ant, int *act)
{
    *hallado = 0;
    *ant = -1;
    *act = l->cl;
    while (!(*hallado) && *act != -1)
        if (l->datos[*act].clave >= vbus)
            *hallado = 1;
        else {
            *ant = *act;
            *act = l->datos[*act].sig;
        }
    if (*hallado)
        *hallado = l->datos[*act].clave == vbus;
}

void alta (struct lista *l, int valta)
{
    int hallado, ant, act, nuevo;

    buscar (l, valta, &hallado, &ant, &act);
    if (hallado)
        printf ("ya existe la clave\n");
    else if (l->pl == -1)
        printf ("No hay espacio disponible \n");
    else {
        nuevo = l->pl;
        l->pl = l->datos[nuevo].sig;
        l->datos[nuevo].clave = valta;
        l->datos[nuevo].sig = act;
        if (ant != -1)
            l->datos[ant].sig = nuevo;
        else
            l->cl = nuevo;
    }
}

void baja (struct lista *l, int vbaja)
{
    int hallado, ant, act, aux;

    buscar (l, vbaja, &hallado, &ant, &act);
    if (!hallado)
        printf ("no existe la clave");
    else {
        if (ant != -1)
            l->datos[ant].sig = l->datos[act].sig;
        else
            l->cl = l->datos[act].sig;
        l->datos[act].sig = l->pl;
        l->pl = act;
    }
}

void memoria (struct lista l)
{
    int i;

    cprintf ("celdas:");
    for (i = 0; i < n; i++)
        cprintf ("%6d", i);
    printf ("\n");
    printf ("  cl= %d", l.cl);
    for (i = 0; i < n; i++)
        if (l.datos[i].clave > 0)
            cprintf ("%6d", l.datos[i].clave);
        else
            cprintf ("%6c", ' ');
    printf ("\n");
    printf ("  pl= %d", l.pl);
    for (i = 0; i < n; i++)
        printf ("%6d", l.datos[i].sig);
    printf ("\n");
    printf ("\n");
}

void main (void)
{
    struct lista l;
    int opcion, valta, vbaja;

    clrscr ();
    inicializar (&l);           /* inicialización de la zona de memoria */
    printf ("%60s\n", "ESTADO INICIAL DE LA MEMORIA");
    memoria (l);
    do {
        printf ("0.-fin    1.-altas      2.-bajas.       opción: ");
        scanf ("%d", &opcion);
        switch (opcion) {
            case 1:
                printf ("alta: ");
                scanf ("%d", &valta);
                alta (&l, valta);
                break;
            case 2:
                printf ("baja: ");
                scanf ("%d", &vbaja);
                baja (&l, vbaja);
                break;
        };
        listar (&l);
        getch ();
        memoria (l);
    } while (opcion);
    getch ();
}
