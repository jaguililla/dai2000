#include<stdlib.h>

int primo (int numero)
{
    int indice, res, cont = 0;

    for (indice = 2; indice <= numero / 2; indice++) {
        res = numero % indice;

        if (res = 0)
            cont++;
    }

    return (cont);
}

void main (void)
{
    int uno = 0, dos = 1, tres, total;

    clrscr ();

    do {
        tres = uno + dos;
        uno = dos;
        dos = tres;
        total = primo (tres);
    }
    while ((tres <= 10) || (total != 0));

    printf ("%d", tres);

    getch ();
}
