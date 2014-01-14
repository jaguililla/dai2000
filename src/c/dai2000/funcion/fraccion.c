   /* fraccion */
#include <stdio.h>

int mcd (int, int);
void simplifica (int *, int *);
void suma (int, int, int, int, int *, int *);
void resta (int, int, int, int, int *, int *);
void producto (int, int, int, int, int *, int *);
void cociente (int, int, int, int, int *, int *);
void menu (void);
void salida (int, int, int, int, int, int, char);

void main (void)
{
    int n1, d1, n2, d2, n, d;
    char ope;

    clrscr ();
    printf ("Introduzca primera fracción: ");
    scanf ("%d %d%c", &n1, &d1);
    printf ("Introduzca segunda fracción: ");
    scanf ("%d %d%c", &n2, &d2);
    simplifica (&n1, &d1);
    simplifica (&n2, &d2);
    menu ();
    printf ("Introduzca operación: ");
    ope = getchar ();
    while (ope) {
        switch (ope) {
            case '+':
                suma (n1, d1, n2, d2, &n, &d);
                break;
            case '-':
                resta (n1, d1, n2, d2, &n, &d);
                break;
            case '*':
                producto (n1, d1, n2, d2, &n, &d);
                break;
            case '/':
                cociente (n1, d1, n2, d2, &n, &d);
                break;
        }                       /* switch */
        simplifica (&n, &d);
        salida (n1, d1, n2, d2, n, d, ope);
        menu ();
        printf ("Introduzca operación: ");
        ope = getchar ();
    };
    getch ();
}
int mcd (int a, int b)
{
    int aux;

    aux = (a <= b) ? a : b;
    while ((a % aux) || (b % aux))
        aux--;
    return aux;
}
void simplifica (int *a, int *b)
{
    int aux;

    aux = mcd (*a, *b);
    *a /= aux;
    *b /= aux;
}
void suma (int n1, int d1, int n2, int d2, int *n, int *d)
{
    *d = d1 * d2;
    *n = n1 * d2 + n2 * d1;
}
void resta (int n1, int d1, int n2, int d2, int *n, int *d)
{
    *d = d1 * d2;
    *n = n1 * d2 - n2 * d1;
}
void producto (int n1, int d1, int n2, int d2, int *n, int *d)
{
    *d = d1 * d2;
    *n = n1 * n2;
}
void cociente (int n1, int d1, int n2, int d2, int *n, int *d)
{
    *n = n1 * d2;
    *d = d1 * n2;
}
void menu (void)
{
    printf ("0.-fin    +   -   *   /\n");
}
void salida (int n1, int d1, int n2, int d2, int n, int d, char o)
{
    printf ("%d/%d %c %d/%d = %d/%d\n", n1, d1, o, n2, d2, n, d);
}
