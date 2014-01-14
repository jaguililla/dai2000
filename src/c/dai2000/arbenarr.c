#include<stdio.h>
#include<stdlib.h>


#define N 10

struct arbol {
    int dato, izq, der;
};

struct arbol cad[N];

int buscar (int valor)
{
    int indice = 1, parar = 0, ant = 0;

    while ((cad[0].der > 1) && (parar == 0)) {
        ant = indice;

        if (valor < cad[indice].dato)
            if (cad[indice].izq == 0)
                parar = 1;
            else
                indice = cad[indice].izq;
        else if (cad[indice].der == 0)
            parar = 1;
        else
            indice = cad[indice].der;
    }

    return (indice);
}

void altas ()
{
    int valor, indice2;

    if (cad[0].der < N - 1) {
        printf ("Introduzca valor a dar de alta: ");
        scanf ("%d", &valor);
        cad[cad[0].der].dato = valor;
        indice2 = buscar (valor);

        if (cad[0].der > 1) {
            if (valor < cad[indice2].dato)
                cad[indice2].izq = cad[0].der;
            else
                cad[indice2].der = cad[0].der;
        }

        cad[0].der++;
        printf ("El valor ha sido dado de alta.");
    }
    else
        printf ("El árbol está completo.");
}

void main (void)
{
    int resp, valor1 = 0;

    do {
        clrscr ();
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
                altas ();
                break;

            case 2:

                if (cad[0].der > 0)
                    //baja();
                    printf
                        ("Ahora daría de baja, pero este pardillo no lo ha hecho todavía.");
                else
                    printf ("La cola está vacía.");

                break;

            case 3:
                //listar();
                break;

            case 4:
                valor1++;

                break;
        }

        if (resp != 4)
            getch ();
    }
    while (valor1 == 0);
}
