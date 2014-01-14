#include <stdio.h>
void menu (void);
void suma (int, int, int, int, int *, int *);
void resta (int, int, int, int, int *, int *);
void producto (int, int, int, int, int *, int *);
void cociente (int, int, int, int, int *, int *);
void simplificar (int *, int *);

void main (void)
{
    int n1, d1, n2, d2, n, d, ope;

    //unsigned char ope;

    clrscr ();
    printf ("Introduzca numerador y denominador primera fracción ");
    scanf ("%d %d", &n1, &d1);
    printf ("Introduzca numerador y denominador segunda fracción ");
    scanf ("%d %d", &n2, &d2);
    menu ();
    printf ("Introduzca operación: ");
    //ope = getchar();
    scanf ("%d", &ope);
    switch (ope) {
        case 1:
            suma (n1, d1, n2, d2, &n, &d);
            break;
        case 2:
            resta (n1, d1, n2, d2, &n, &d);
            break;
        case 3:
            producto (n1, d1, n2, d2, &n, &d);
            break;
        case 4:
            cociente (n1, d1, n2, d2, &n, &d);
            break;
    }
    simplificar (&n, &d);
    printf ("Resultado = %d / %d\n", n, d);
    getch ();
}

void menu (void)
{
    printf ("+ 1 \n");
    printf ("- 2 \n");
    printf ("* 3 \n");
    printf ("/ 4 \n");
}

void suma (int a, int b, int c, int d, int *nu, int *de)
{
    *nu = a * d + b * c;
    *de = b * d;
}

void resta (int a, int b, int c, int d, int *nu, int *de)
{
    *nu = a * d - b * c;
    *de = b * d;
}

void producto (int a, int b, int c, int d, int *nu, int *de)
{
    *nu = a * c;
    *de = b * d;
}

void cociente (int a, int b, int c, int d, int *nu, int *de)
{
    *nu = a * d;
    *de = b * c;
}

void simplificar (int *n, int *d)
{
    int divisor;

    if (*n <= *d)
        divisor = *n;
    else
        divisor = *d;
    while ((*n % divisor != 0) || (*d % divisor != 0))
        divisor--;
    *n = *n / divisor;
    *d = *d / divisor;
}
