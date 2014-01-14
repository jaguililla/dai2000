#include <stdio.h>
#define n 3
void main (void)
{
    char nompro[n][16];
    int bujias[n], i;
    float pvp[n], tot[n], total = 0.0;

    for (i = 0; i < n; i++) {
        printf ("Proveedor?: ");
        gets (nompro[i]);
        printf ("bujías?: ");
        scanf ("%d", &bujias[i]);
        printf ("precio?: ");
        scanf ("%f%c", &pvp[i]);
        tot[i] = bujias[i] * pvp[i];
        total += tot[i];
    }
    for (i = 0; i < n; i++) {
        printf ("%-30s %7.2f %7d %7.2f\n", nompro[i], pvp[i], bujias[i], tot[i]);
    }
    printf ("%15s %7.2f\n", "Importe total", total);
    getch ();
}
