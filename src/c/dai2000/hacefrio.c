/* hacefrio.c -- porcentaje de días bajo cero */
#include <stdio.h>
#define ESCALA "Celsius"
#define CONGELA 0
int main (void)
{
    float temperatura;
    int congelado = 0;
    int dias = 0;

    printf ("Introduzca la lista de temperaturas mínimas diarias.\n");
    printf ("Use grados %s, y pulse s para terminar.\n", ESCALA);

    while (scanf ("%f", &temperatura) == 1) {
        dias++;

        if (temperatura < CONGELA)
            congelado++;
    }

    if (dias != 0)
        printf ("%d días en total: %.1f%% bajo cero.\n",
                dias, 100.0 * (float) congelado / dias);

    if (dias == 0)
        printf ("¡No se han introducido datos!\n");

    return 0;                   /* programa terminado correctamente */
}
