/* cuadros.c -- define una función con argumento */
#include <stdio.h>
void cuadros ();                /* estilo antiguo de           */

/* declaración de funciones    */
main ()
{
    int veces = 5;
    char ch = '!';              /* código ASCII 33             */
    float f = 6.0;

    cuadros (veces);            /* argumento int               */
    cuadros (ch);               /* char automáticamente -> int */
    cuadros ((int) f);          /* el moldeado fuerza f -> int */
}

void cuadros (n)                /* encabezamiento al estilo    */
     int n;                     /* antiguo indica a cuadros()  */
{                               /* que acepte un argumento int */

    while (n-- > 0)
        printf ("#");

    printf ("\n");
}
