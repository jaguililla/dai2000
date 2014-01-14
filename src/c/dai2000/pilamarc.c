#include  <stdio.h>
#include  <stdlib.h>


struct nodo {
    int clave;

    struct nodo *sig;
};

void alta (struct nodo **cl)
{
    struct nodo *nuevo;

    nuevo = (struct nodo *)malloc (sizeof (struct nodo));
}

void main ()
{
    char valor;
    int num;

    struct nodo *cl;

    clrscr ();
    cl = NULL;
    printf ("Seleccione una opción:\n");
    printf ("\t1.- Agregar.\n");
    printf ("\t2.- Borrar.\n");
    printf ("\t3.- Listar.\n");
    printf ("\t4.- Salir\n");
    printf ("Ha elegido: ");

    do {
        scanf ("%s", &valor);

        if ((valor > '5') || (valor < '1'))
            printf ("Introduzca un número correcto: ");
    }
    while ((valor > '5') || (valor < '1'));

    switch (valor) {

        case '1':
            alta (&cl);
            break;
    }
}
