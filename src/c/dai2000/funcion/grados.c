/* Paso de grados Centígrados a Fahrenheit (F=9/5*C+32) */

/* Directrices para el preprocesador */
#include <stdio.h>              /* declaración funciones C estándar de E/S. */
/* Definición de constantes */
#define INF -30                 /* límite inferior del intervalo de _C */
#define SUP 100                 /* límite superior */

/* Declaración de los prototipos de las funciones */
float convertir (int c);        /* prototipo de la función convertir */

void main (void)
{                               /* función principal - comienzo del programa */
    /* Declaración de variables locales de main */
    int gc = 0;                 /* grados centígrados */
    int incremento = 10;
    float gf = 0;

    gc = INF;                   /* sentencia de asignación */
    while (gc <= SUP) {
        /* Se llama a la función convertir */
        gf = convertir (gc);
        /* Se escribe la siguiente línea de la tabla */
        printf ("%10d C %10.2f F\n", gc, gf);
        /* Siguiente valor a convertir */
        gc += incremento;
    }
    getch ();
}                               /* fin de la función principal y del programa */

/************** Definición de la función convertir **************/
float convertir (int gcent)
{
    float gfahr;                /* variable local accesible sólo en la función */

    /* los operandos se convierten a la precisión más alta */
    gfahr = (float) 9 / (float) 5 *gcent + 32;

    return (gfahr);             /* valor que retorna la función convertir */
    /* Esta forma de devolver valores se utiliza sobre todo cuando
       hay que devolver un único valor al programa llamador.
       Su utilización es semejante a las funciones en Pascal */
}                               /* Fin de la función de convertir */
