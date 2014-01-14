/* califica.c -- bucles para el procesado de arrays */
#include <stdio.h>
#define NUM 10
main ()
{
    int indice, valor[NUM];
    int suma = 0;
    float media;

    printf ("Introduzca %d valores:\n", NUM);

    for (indice = 0; indice < NUM; indice++)
        scanf ("%d", &valor[indice]);   /* lee 10 valores   */

    printf ("Los valores leídos son los siguientes:\n");

    for (indice = 0; indice < NUM; indice++)
        printf ("%5d", valor[indice]);  /* verifica entrada */

    printf ("\n");

    for (indice = 0; indice < NUM; indice++)
        suma += valor[indice];  /* suma los elementos  */

    media = (float) suma / NUM; /* sistema tradicional */

    printf ("Suma de valores = %d, media = %.2f\n", suma, media);
}
