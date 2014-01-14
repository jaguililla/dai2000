/* problema.c -- uso erróneo de = */
#include <stdio.h>
main ()
{
    long num;
    long suma = 0L;
    int estado;

    printf ("Introduzca un entero a sumar. ");
    printf ("Pulse s para salir.\n");
    estado = scanf ("%ld", &num);

    while (estado = 1) {
        suma = suma + num;
        printf ("Introduzca el siguiente. ");
        printf ("Pulse s para salir.\n");
        estado = scanf ("%ld", &num);
    }

    printf ("La suma de estos enteros es %ld.\n", suma);
}
