#include <stdio.h>
void main (void)
{
    int p, m;

    clrscr ();
    p = 0;
    m = 4;
    while (m >= -1) {
        do {
            p = p + m;
        } while (p <= 5);
        m--;
    }
    printf ("p= %d\n", p);
    getch ();
}
