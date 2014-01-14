/* anchovar.c -- campos de salida de ancho variable */
#include <stdio.h>
main ()
{
    unsigned anchura, precision;
    int numero = 256;
    double peso = 242.5;

    printf ("¿Cuál es el ancho?\n");
    scanf ("%d", &anchura);
    printf ("El número es :%*d:\n", anchura, numero);
    printf ("Ahora introduzca el ancho y la precisión:\n");
    scanf ("%d %d", &anchura, &precision);
    printf ("Peso = %*.*f\n", anchura, precision, peso);
}
