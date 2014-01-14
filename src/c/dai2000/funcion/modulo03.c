  // modulo00
  /* calcula números combinatorios usando  funciones */
#include <stdio.h>
long int fact (int n);
void main (void)
{
    int n, m;

    clrscr ();
    do {
        printf ("Introduzca número combinatorio m y n (m >=n) ");
        scanf ("%d %d", &m, &n);
    } while (m < n);
    printf ("combinaciones= %ld\n", fact (m) / (fact (n) * fact (m - n)));
    getch ();
}
long int fact (int p)
{
    int u, i;

    u = 1;
    for (i = 1; i <= p; i++)
        u = u * i;
    return (u);
}
