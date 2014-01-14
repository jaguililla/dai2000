/* eco.c -- usa fgets() y fputs() */
#include <stdio.h>
#define LINEAMAX 20
int main (void)
{
    char linea[LINEAMAX];

    while (fgets (linea, LINEAMAX, stdin) != NULL && linea[0] != '\n')
        fputs (linea, stdout);

    return 0;
}
