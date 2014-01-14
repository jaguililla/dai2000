/* pintura.c -- usa operador condicional */
#include <stdio.h>
#define RECUBRE 20              /* metros cuadrados que se pintan con una lata */
int main (void)
{
    int superficie;
    int latas;

    printf ("¿Cuántos metros cuadrados desea pintar?\n");

    while (scanf ("%d", &superficie) == 1) {
        latas = superficie / RECUBRE;
        latas += (superficie % RECUBRE == 0) ? 0 : 1;
        printf ("Necesita %d %s de pintura.\n", latas,
                latas == 1 ? "lata" : "latas");
    }

    return 0;
}
