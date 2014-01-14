/* pru_sal.c */
#include <stdio.h>
extern void saleat1 (short x);
extern short aleat1 (void);
int main (void)
{
    int cont;
    short semilla;

    printf ("Elija un número como semilla.\n");
    scanf ("%d", &semilla);
    saleat1 (semilla);          /* pone una nueva semilla */

    for (cont = 1; cont <= 5; cont++)
        printf ("%hd\n", aleat ());

    return 0;
}
