/* eldorado.c -- un programa para calcular su peso en oro */
#include <stdio.h>
main ()
{
    float peso, valor;          /* 2 variables en punto flotante */
    char pita;                  /* una variable carácter */

    pita = '\007';              /* asigna un carácter especial a pita */
    printf ("¿Vale su peso en oro?\n");
    printf ("Introduzca su peso en kg y ya veremos.\n");
    scanf ("%f", &peso);        /* toma un dato del usuario */
    valor = 400.0 * peso * 32.1512;
    /* supone que el oro se cotiza a 400$ la onza */
    /* 32.1512 pasa kg a onzas troy */
    printf ("%cSu peso en oro equivale a $%2.2f%c.\n", pita, valor, pita);
    printf ("¡Seguro que vale mucho más! Si el oro baja, ");
    printf ("coma más\npara mantener su valor.\n");
}
