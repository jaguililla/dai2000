/* segamin.c -- convierte segundos en minutos y segundos */
#include <stdio.h>
#define SM 60                   /* segundos en un minuto */
main ()
{
    int seg, min, resto;

    printf ("Convierte segundos en minutos y segundos.\n");
    printf ("Introduzca segundos a convertir.\n");
    scanf ("%d", &seg);         /* se lee el número de segundos */
    min = seg / SM;             /* número truncado de minutos   */
    resto = seg % SM;           /* número de segundos de resto  */
    printf ("%d segundos son %d minutos, %d segundos.\n", seg, min, resto);
}
