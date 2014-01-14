/* fondos3.c -- pasa una estructura */
#include <stdio.h>

struct fondos {
    char *banco;
    float ccorri;
    char *ahorro;
    float cahorro;
} garcia = {
"Banco Pacífico", 102343.25, "Banco de Poniente", 423987.21};

float suma (struct fondos);     /* el argumento es una estructura */
int main (void)
{
    printf ("García tiene un total de %.2f pts.\n", suma (garcia));
    return 0;
}

float suma (struct fondos pelas)
{
    return (pelas.ccorri + pelas.cahorro);
}
