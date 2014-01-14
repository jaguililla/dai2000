/* pizza.c -- constantes aplicadas a veleidosas pizzas */
#include <stdio.h>
#define PI 3.14159
main ()
{
    float area, circun, radio;

    printf ("¿Cuál es el radio de su pizza?\n");
    scanf ("%f", &radio);
    area = PI * radio * radio;
    circun = 2.0 * PI * radio;
    printf ("Los parámetros básicos de su pizza son:\n");
    printf ("circunferencia = %1.2f, área = %1.2f\n", circun, area);
}
