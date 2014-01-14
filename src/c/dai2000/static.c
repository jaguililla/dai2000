/* static.c -- variable estética */
#include <stdio.h>
void pruebastat (void);
int main (void)
{
    int cont;

    for (cont = 1; cont <= 3; cont++) {
        printf ("Aquí llega iteración %d:\n", cont);
        pruebastat ();
    }

    return 0;
}

void pruebastat (void)
{
    int muere = 1;
    static int vive = 1;

    printf ("muere = %d y vive = %d\n", muere++, vive++);
}
