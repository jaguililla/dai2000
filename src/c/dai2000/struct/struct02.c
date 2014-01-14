#include <stdio.h>
#define n 3

void main (void)
{
    struct fecha {
        int dd, mm, aa;
    };
    struct tprov {
        char nom[16];
        int bujias, precio, ptas;
        struct fecha fec_nac;
    };

    struct tprov p[n];          /* se declara un array de proveedores */
    int cont, total = 0;

    for (cont = 0; cont < n; cont++) {
        printf ("proveedor: ");
        gets (p[cont].nom);
        printf ("bujías: ");
        scanf ("%d", &p[cont].bujias);
        printf ("precio: ");
        scanf ("%d%c", &p[cont].precio);
        printf ("fecha nacimiento: ");
        scanf ("%d %d %d%c", &p[cont].fec_nac.dd,
               &p[cont].fec_nac.mm, &p[cont].fec_nac.aa);
        p[cont].ptas = p[cont].bujias * p[cont].precio;
        total += p[cont].ptas;
    }

    /* salida de datos */
    printf ("%9s %8s %8s %8s %8s\n", "proveedor", "bujias", "pvp", "ptas",
            "fecha");
    for (cont = 0; cont < 3; cont++) {
        printf ("%9s", p[cont].nom);
        printf ("%8d", p[cont].bujias);
        printf ("%8d", p[cont].precio);
        printf ("%8d", p[cont].ptas);
        printf ("%d %d %d", p[cont].fec_nac.dd, p[cont].fec_nac.mm,
                p[cont].fec_nac.aa);
        printf ("\n");
    }
    printf ("%40s %10d", "precio total: ", total);
    getch ();
}
