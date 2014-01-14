/**************** Simulación de una calculadora ****************/
/* calcula.c */
#include <stdio.h>
#include <stdlib.h>

void main (void)
{
    double dato1, dato2, resultado;
    int operacion;

    /* Declaración de los prototipos de las funciones */
    double sumar (double dato1, double dato2);
    double restar (double dato1, double dato2);
    double multiplicar (double dato1, double dato2);
    double dividir (double dato1, double dato2);
    int menu (void);

    while (1) {
        operacion = menu ();

        if (operacion != 5) {
            printf ("\nTeclear dato 1: ");
            scanf ("%lf", &dato1);
            printf ("Teclear dato 2: ");
            scanf ("%lf", &dato2);
            fflush (stdin);

            switch (operacion) {
                case 1:
                    resultado = sumar (dato1, dato2);
                    break;
                case 2:
                    resultado = restar (dato1, dato2);
                    break;
                case 3:
                    resultado = multiplicar (dato1, dato2);
                    break;
                case 4:
                    resultado = dividir (dato1, dato2);
                    break;
            }

            printf ("\nResultado = %g\n", resultado);
            printf ("\nPulse <Entrar> para continuar ");
            getch ();
        }
        else
            break;
    }
}

int menu (void)
{
    int op;

    do {
        //system("cls");
        clrscr ();
        printf ("\t1.  sumar\n");
        printf ("\t2.  restar\n");
        printf ("\t3.  multiplicar\n");
        printf ("\t4.  dividir\n");
        printf ("\t5.  salir\n");
        printf ("\nSeleccione la operación deseada: ");
        scanf ("%d", &op);
    }
    while ((op < 1) || (op > 5));
    return op;
}

double sumar (double a, double b)
{
    double c;

    c = a + b;
    return (c);
}

double restar (double a, double b)
{
    double c;

    c = a - b;
    return (c);
}

double multiplicar (double a, double b)
{
    double c;

    c = a * b;
    return (c);
}

double dividir (double a, double b)
{
    double c;

    c = a / b;
    return (c);
}
