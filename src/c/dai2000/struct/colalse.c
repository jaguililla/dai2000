#include<stdio.h>
#include<stdlib.h>


struct nodo {
    int dato;
    struct nodo *sig;
};

void alta (struct nodo **cc) {
    struct nodo *nuevo, *act;
    int num;
    nuevo = (struct nodo *) malloc (sizeof (struct nodo));
    if (nuevo == NULL) {
        printf ("La agenda está completa.");
    }
    else {
        printf ("Introduzca el valor a dar de alta: ");
        scanf ("%d", &num);
        nuevo->dato = num;
        nuevo->sig = NULL;
        if (*cc == NULL) {
            *cc = nuevo;
        }
        else {
            act = *cc;
            while (act->sig) {
                act = act->sig;
            }
            act->sig = nuevo;
        }
        printf ("Se ha dado de alta satisfactoriamente.");
    }
}

void baja (struct nodo **cc)
{
    struct nodo *aux;

    if (*cc) {
        aux = *cc;
        *cc = aux->sig;
        free (aux);
        printf ("Se ha dado de baja satisfactoriamente.");
    }
    else
        printf ("La cola está vacía.");
}

void listar (struct nodo *cc)
{
    if (cc)
        while (cc) {
            printf ("%d\t", cc->dato);
            cc = cc->sig;
        }
    else
        printf ("La cola está vacía.");
}

int main (void)
{
    int resp, valor = 0;
    struct nodo *cc;

    cc = NULL;
    do {
        printf ("Seleccione una opción:\n");
        printf ("\t1.- Agregar.\n");
        printf ("\t2.- Borrar.\n");
        printf ("\t3.- Listar.\n");
        printf ("\t4.- Salir\n");
        printf ("Ha elegido: ");
        do {
            scanf ("%d", &resp);
            if ((resp > 4) || (resp < 0))
                printf ("Introduzca una opción correcta: ");
        }
        while ((resp > 4) && (resp < 0));
        switch (resp) {
            case 1:
                alta (&cc);
                break;
            case 2:
                if (cc)
                    baja (&cc);
                else
                    printf ("La cola está vacía.");
                break;
            case 3:
                listar (cc);
                break;
            case 4:
                valor++;
                break;
        }
        if (resp != 4)
            getch ();
    }
    while (valor == 0);
}
