/* global.c -- unidades como global */
#include <stdio.h>
int Unidades;                   /* una variable externa */
void critica (void);
int main (void)
{
    extern int Unidades;

    printf ("¿Cuántos reburcios hay en una drumera de harina?\n");
    scanf ("%d", &Unidades);

    while (Unidades != 3419)
        critica ();

    printf ("¡¡¡Seguro que has mirado!!!\n");
}

void critica (void)
{
    extern int Unidades;

    printf ("Lo siento, chaval. Prueba otra vez.\n");
    scanf ("%d", &Unidades);
}
