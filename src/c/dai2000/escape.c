/* escape.c -- utiliza caracteres de escape */
#include <stdio.h>
main ()
{
    float salario;

    printf ("Introduzca salario mensual deseado:"); /* 1 */
    printf (" _______pts \b\b\b\b\b\b\b");  /* 2 */
    scanf ("%f", &salario);
    printf ("\n\t%.2f pts por mes equivale a %.2f pts por año.", salario, salario * 12.0);  /* 3 */
    printf ("\r¡Vale!\n");      /* 4 */
}
