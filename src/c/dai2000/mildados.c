/* mildados.c -- tiradas múltiples de dados */
#include <stdio.h>
extern saleat1 (short);
extern int cubilete (int lados);
int main (void)
{
    int dados, cont, tirada;
    short semilla;
    int lados;

    printf ("Introduzca semilla.\n");
    scanf ("%d", &semilla);
    saleat1 (semilla);
    printf ("Indique número de caras por dado; 0 para terminar.\n");

    while (scanf ("%d", &lados) == 1 && lados > 0) ;
    {
        printf ("¿Cuántos dados?\n");
        scanf ("%d", &dados);

        for (tirada = 0, cont = 1; cont <= dados; cont++)
            tirada += cubilete (lados); /* calcula total de la tirada */

        printf ("Acaba de sacar un %d con %d dados de %.0f caras.\n",
                tirada, dados, lados);

        printf ("¿Cuántas caras? Pulse 0 para acabar.\n");
    }

    printf ("¡¡¡QUE TENGA SUERTE!!!\n");
    return 0;
}
