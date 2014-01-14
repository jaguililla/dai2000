/* ptr_oper.c -- operaciones con punteros */
#include <stdio.h>
int main (void)
{
    static int urn[3] = { 100, 200, 300 };
    int *punt1, *punt2;

    punt1 = urn;                /* asigna una dirección al puntero */
    punt2 = &urn[2];            /* idem */
    printf ("punt1 = %u, *punt1 =%d, &punt1 = %u\n", punt1, *punt1, &punt1);
    punt1++;                    /* incrementa el puntero */
    printf ("punt1 = %u, *punt1 =%d, &punt1 = %u\n", punt1, *punt1, &punt1);
    /* referencia y toma */
    /* la dirección del puntero */
    printf ("punt2 = %u, *punt2 =%d, &punt2 = %u\n", punt2, *punt2, &punt2);
    ++punt2;                    /* sobrepasa el array */
    printf ("punt2 = %u, *punt2 =%d, &punt2 = %u\n", punt2, *punt2, &punt2);
    printf ("punt2 - punt1 = %u\n", punt2 - punt1);
    /* substracción de punteros */
    return 0;
}
