#include<math.h>
void main (void)
{
    int indice;

    clrscr ();
    printf ("\tsen\tcos\ttg\n");

    for (indice = 0; indice <= 9; indice++) {
        printf ("%d\t%ld\t%ld\t%ld\n", indice * 5, sin (indice), cos (indice),
                tan (indice));
    }

    getch ();
}
