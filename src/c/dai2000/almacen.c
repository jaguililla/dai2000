//Almacen
#include<stdlib.h>
#define suc 3
#define art 4
void main (void)
{
    int almacen[suc][art], precio[art], indice, mayor, prec, cont, pos1, pos2,
        arti;
    int artic[art], total1, total2, total3;

    clrscr ();
    //guarda las cantidades de artículos por sucursal

    for (indice = 0; indice < suc; indice++) {
        printf ("Introduzca cantidades para la sucursal %d.\n", indice + 1);

        for (cont = 0; cont < art; cont++) {
            printf ("\tArtículo %d: ", cont + 1);
            scanf ("%d", &almacen[indice][cont]);
            artic[cont] = 0;
        }
    }

    //guarda los precios de los artículos
    for (indice = 0; indice < art; indice++) {
        printf ("Introduzca el precio del artículo %d: ", indice + 1);
        scanf ("%d", &precio[indice]);
    }

    //existencias
    mayor = almacen[0][0];

    prec = precio[0];

    for (indice = 0; indice < suc; indice++) {
        for (cont = 0; cont < art; cont++) {
            if (almacen[indice][cont] > mayor) {
                mayor = almacen[indice][cont];
                pos1 = indice;
                pos2 = cont;
            }

            artic[cont] += almacen[indice][cont];
        }
    }

    //mayor valor de ingresos
    total3 = 0;

    for (indice = 0; indice < art; indice++) {
        total1 = precio[indice];
        total2 = artic[indice];
        total1 = total1 * total2;

        if (total1 > total3) {
            total3 = total1;
            arti = indice;
        }
    }

    printf
        ("La pieza de la que hay más existencias es: Almacen: %d. Pieza: %d\n",
         pos1 + 1, pos2 + 1);
    printf ("La pieza que da más ingresos es: %d con %d de precio.", arti + 1,
            total3);
    getch ();
}
