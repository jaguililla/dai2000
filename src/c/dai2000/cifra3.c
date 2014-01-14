/* Algoritmo Cifra_Al_Cubo */
#include <math.h>
#include <stdio.h>

/* Main */
void main (void)
{
    /* Variables */
    unsigned long cont, cont2, indice, coc, coc3, tem, salida;

    clrscr ();
    printf
        ("Los números que al sumar los cubos de sus cifras dan el mismo número son: \n");

    for (cont = 100; cont < 1000; cont++) {
        cont2 = cont;
        coc3 = 0;
        salida = 0;

        for (indice = 3; indice > 0; indice--) {
            tem = pow (10, indice - 1);
            coc = (cont2 / tem);    //valor de cifra
            cont2 = (cont2 % tem);  //resto
            coc3 = (coc3 + pow (coc, 3));
            /*tem = pow (10,indice-1); */

            if (coc3 == cont)
                if (salida != cont) {
                    printf ("%ld\t", cont);
                    salida = cont;
                }
                else
                    printf ("");
        };
    };

    getch ();
}
