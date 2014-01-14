/* cuadrados.c -- produce una tabla de 20 cuadrados */
#include <stdio.h>
main ()
{
    int num = 1;

    while (num < 21) {
        printf ("%10d %10d\n", num, num * num);
        num = num + 1;
    }
}
