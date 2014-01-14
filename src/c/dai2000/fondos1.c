/* fondos1.c -- paso de miembros de estructura a una función */
#include <stdio.h>

struct fondos {
    char *banco;
    float ccorri;
    char *ahorro;
    float cahorro;
} garcia = {
"Banco Pacífico", 102343.25, "Banco de Poniente", 423987.21};
float suma (float, float);
int main (void)
{
    float total;

    extern struct fondos garcia;    /* declaración opcional */

    printf ("García tiene un total de %.2f pts.\n",
            suma (garcia.ccorri, garcia.cahorro));
    return 0;
}

/* función que suma dos números float */
float suma (float x, float y)
{
    return (x + y);
}
