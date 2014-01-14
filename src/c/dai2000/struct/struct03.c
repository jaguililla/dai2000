#include <stdio.h>
#define n 3

struct tipopro {                /* declaración del tipo registro */
    char nom[6];
    int bujias, precio;
};

void cargarproveedor (struct tipopro *p);
void escribirproveedor (struct tipopro p);
void cargamatriz (struct tipopro p[], int k);
void escribirmatriz (struct tipopro p[], int k);
int total (struct tipopro p[], int k);

void main (void)
{
    struct tipopro proveedor[n];

    cargamatriz (proveedor, n);
    escribirmatriz (proveedor, n);
    printf ("IMPORTE TOTAL= %d\n", total (proveedor, n));
    getch ();
}

void cargarproveedor (struct tipopro *p)
{
    printf ("proveedor: ");
    gets (p->nom);
    printf ("bujías: ");
    scanf ("%d", &p->bujias);
    printf ("precio: ");
    scanf ("%d%c", &p->precio);
}

void cargamatriz (struct tipopro p[], int k)
{
    int i;

    for (i = 0; i < k; i++)
        cargarproveedor (&p[i]);
}

void escribirproveedor (struct tipopro p)
{
    printf ("%9s", p.nom);
    printf ("%8d", p.bujias);
    printf ("%8d", p.precio);
    printf ("%8d\n", p.precio * p.bujias);
}

void escribirmatriz (struct tipopro pro[], int k)
{
    int i;

    printf ("%9s%8s%8s%8s\n", "proveedor", "bujias", "pvp", "ptas");
    for (i = 0; i < k; i++)
        escribirproveedor (pro[i]);
}

int total (struct tipopro p[], int k)
{
    int i, tot = 0;

    for (i = 0; i < k; i++)
        tot += p[i].bujias * p[i].precio;
    return (tot);
}
