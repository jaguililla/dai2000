/* subst.c -- sustituciones en tiras de caracteres */
#include <stdio.h>
#define PSQR(x)  printf("El cuadrado de " #x " es %d.\n", ((x)*(x)));
int main (void)
{
    int y = 5;

    PSQR (y);
    PSQR (2 + 4);
    return 0;
}
