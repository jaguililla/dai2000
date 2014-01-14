/* fondos2.c -- paso de la dirección de la estructura a una función */
#include <stdio.h>

struct fondos {
    char *banco;
    float ccorri;
    char *ahorro;
    float cahorro;
} garcia = {
"Banco Pacífico", 102343.25, "Banco de Poniente", 423987.21};

float suma (struct fondos *);   /* el argumento es un puntero */
int main (void)
{
    printf ("García tiene un total de %.2f pts.\n", suma (&garcia));
    return 0;
}

float suma (struct fondos *dinero)
{
    return (dinero->ccorri + dinero->cahorro);
}
