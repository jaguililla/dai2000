/* cabecer2.c */
#include <stdio.h>
#define NOMBRE "ORDENATAS, S.A."
#define DIREC "Plaza del Byte 12"
#define CIUDAD "Villabits, E- 60006"
#define LIMITE 65
#define ESPACIO ' '
int main (void)
{
    int espacios;
    void n_car (char, int);

    n_car ('*', LIMITE);        /* constante como argumento     */
    putchar ('\n');
    n_car (ESPACIO, 25);        /* constante como argumento     */
    printf ("%s\n", NOMBRE);
    espacios = (65 - strlen (DIREC)) / 2;
    /* dejamos al programa calcular */
    /* los espacios a saltar        */
    n_car (ESPACIO, espacios);  /* variable como argumento      */
    printf ("%s\n", DIREC);
    n_car (ESPACIO, (65 - strlen (CIUDAD)) / 2);
    /* expresión como argumento     */
    printf ("%s\n", CIUDAD);
    n_car ('*', LIMITE);
    putchar ('\n');
    return 0;
}

/* aquí está n_car() */
void n_car (char car, int numero)
{
    int cont;

    for (cont = 1; cont <= numero; cont++)
        putchar (car);
}
