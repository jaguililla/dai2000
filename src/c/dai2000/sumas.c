/* sumas.c -- suma enteros de forma interactiva */
#include <stdio.h>
main ()
{
    long num;
    long suma = 0L;             /* inicializa suma a cero     */
    int estado;

    printf ("Introduzca un entero a sumar. ");
    printf ("Pulse s para salir.\n");
    estado = scanf ("%ld", &num);

    while (estado == 1) {       /* == significa "son iguales" */
        suma = suma + num;
        printf ("Introduzca el siguiente. ");
        printf ("Pulse s para salir.\n");
        estado = scanf ("%ld", &num);
    }

    printf ("La suma de estos enteros es %ld.\n", suma);
}
